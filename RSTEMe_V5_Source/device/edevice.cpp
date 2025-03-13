#include "edevice.h"
#include <QDebug>
#include <QVariant>
#include "elog.h"

//Static

EDevice::EDevice(QObject *parent)
    : QObject{parent}
{
m_connection = new EConnection();
this->init();
}

EDevice::EDevice(EConnection *conn)
{
this->setConnection(conn);
this->init();
}

EDevice::~EDevice()
{
    this->stop();
}

void EDevice::setConnection(EConnection *conn)
{
    if(m_connection){
        QObject::disconnect(m_connection,&EConnection::connectChanged,this,&EDevice::on_connectChanged);
        QObject::disconnect(m_connection,&EConnection::errorOccurred,this,&EDevice::on_errorOccurred);
        QObject::disconnect(m_connection,&EConnection::reply,this,&EDevice::on_reply);
        QObject::disconnect(m_connection,&EConnection::modbusRequest,this,&EDevice::on_modbusRequest);
    }
m_connection = conn;
QObject::connect(m_connection,&EConnection::connectChanged,this,&EDevice::on_connectChanged);
QObject::connect(m_connection,&EConnection::errorOccurred,this,&EDevice::on_errorOccurred);
QObject::connect(m_connection,&EConnection::reply,this,&EDevice::on_reply);
QObject::connect(m_connection,&EConnection::modbusRequest,this,&EDevice::on_modbusRequest);
}


void EDevice::init()
{
    //Timer
    m_timerPoll = new QTimer();
    QObject::connect(m_timerPoll,&QTimer::timeout,this,&EDevice::on_timerPoll);
}

int EDevice::getRequestID(ERequestUnit::RequestType type)
{
int _id = ERequestUnit::requestID();
if(type==ERequestUnit::Read)m_requestID_Read = _id;
else m_requestID_Write = _id;
return _id;
}

bool EDevice::checkRequestID(ERequestUnit::RequestType type,int id)
{
if(type==ERequestUnit::Read&&id==m_requestID_Read)return true;
if(type==ERequestUnit::Write&&id==m_requestID_Write)return true;
return false;
}

bool EDevice::start()
{
    m_startPoll = true;
    return this->start(m_startPoll);
}

bool EDevice::start(bool res)
{
    m_startPoll = res;
    if(m_isStart!=StartStatus::StIdle)return false;
    return this->modbusRtuStart();;
}

bool EDevice::stop()
{
    m_connectionStart = StartProcess::SpIdle;
    if(m_timerPoll){
        m_timerPoll->stop();
        QObject::disconnect(m_timerPoll,&QTimer::timeout,this,&EDevice::on_timerPoll);
        m_timerPoll->deleteLater();
        m_timerPoll = nullptr;
    }
    if(m_connection){
        QObject::disconnect(m_connection,&EConnection::connectChanged,this,&EDevice::on_connectChanged);
        QObject::disconnect(m_connection,&EConnection::errorOccurred,this,&EDevice::on_errorOccurred);
        QObject::disconnect(m_connection,&EConnection::reply,this,&EDevice::on_reply);
        QObject::disconnect(m_connection,&EConnection::modbusRequest,this,&EDevice::on_modbusRequest);
    }
    emit this->finished();
    return true;
}

bool EDevice::MeasureRequest(ERequestUnit request)
{
    m_requestSingle.status = true;
    m_requestSingle.request = request;
    return this->Measure();
}


bool EDevice::MeasureSingleShot(ERequestUnit request)
{
m_measureType = MeasureType::MSingleShot;
m_requestPeriodic.request = request;
return this->Measure();
}
bool EDevice::MeasurePeriodic(ERequestUnit request)
{
m_measureType = MeasureType::MPeriodic;
m_requestPeriodic.request = request;
return this->Measure();
}

/*
 * Slots
 */
void EDevice::on_connectChanged(bool status)
{
    emit this->connectChanged(status);
}

void EDevice::on_reply(ERequestUnit request)
{
    if(!this->checkRequestID(request.type(),request.id()))return;
    m_deviceReply.reply = true;
    m_deviceReply.unit = request;
    m_deviceReply.unit.setTimeRequest(m_modbusTimeRequestCount);
    ELog::log(m_deviceInfo,m_deviceReply.unit);
}
void EDevice::on_errorOccurred(ERequestUnit request)
{
    if(!this->checkRequestID(request.type(),request.id()))return;
    m_deviceReply.reply = true;
    m_deviceReply.unit = request;
    if(m_connectionStart != SpGetAddress)emit error(Error::ErrorRequestData);
    m_modbusTimeRequestCount = 0;
}

void EDevice::on_modbusRequest(ERequestUnit request)
{
    if(!this->checkRequestID(request.type(),request.id()))return;
    m_deviceReply.request = true;
    m_modbusTimeRequestCount = 0;
}


void EDevice::on_timerPoll()
{
m_modbusRtuTimeTick++;
m_modbusTimeRequestCount++;
this->deviceStart();
}

/*
 * Function
 */
bool EDevice::modbusRtuStart()
{
    //Check connect to serialPort of modbusRTU
    m_timerPoll->start(1);
    m_isStart = StartStatus::StStarting;
    m_connectionStart = StartProcess::SpIdle;
    m_reConnectNumber = 0;
    return true;
}

void EDevice::deviceStart()
{
static int _timeWaitStart=0;
_timeWaitStart++;
switch(m_connectionStart){
    case StartProcess::SpIdle:
        m_isMeasure = MeasureStatus::MsIdle;
        m_isStart = StartStatus::StIdle;
        if(m_connection){
            m_connectionStart = StartProcess::SpSetAddress;
            m_measureRetries = 0;
            m_requestAddressNumber = 0;
            m_requestUnit.setSlaveAddress(m_deviceInfo.addressDefault());
            m_isStart = StartStatus::StStarting;                       //qDebug()<<m_deviceInfo.address()<<": setAddress";
            }
        m_modbusRtuTimeTick = 0;
        break;
    case StartProcess::SpSetAddress:
        if(m_requestAddressNumber>1){
            m_connectionStart = StartProcess::SpError;
            emit error(Error::ErrorStart);
            }
            else{
                if(this->modbusRtuSetAddress()){
                    m_connectionStart = StartProcess::SpGetAddress;     //qDebug()<<m_deviceInfo.address()<<": getAddress ->"<<m_requestAddressNumber;
                    m_modbusRtuTimeTick = 0;
                    _timeWaitStart=0;
                }
            }
        break;
    case StartProcess::SpGetAddress:
        if(this->modbusRtuGetAddress()&&(_timeWaitStart>100)){                                //qDebug()<<"timeRequest:"<<m_connection->portParameter().timeOut<<"      timeOut:"<<m_modbusTimeRequestCount;
            m_requestAddressNumber++;
            m_connectionStart = StartProcess::SpCheckSN;
            m_modbusRtuTimeTick = 0;
            }
        break;
    case StartProcess::SpCheckSN:
        if(this->modbusRtuRequestSerialNumber()){
            m_connectionStart = StartProcess::SpGetSN;                      //qDebug()<<m_deviceInfo.address()<<": getSN";
            m_modbusRtuTimeTick = 0;
            }
        break;
    case StartProcess::SpGetSN:
        if(m_deviceReply.reply){
            if(this->modbusRtuGetSerialNumber()){                           //qDebug()<<m_deviceInfo.address()<<": SpStarted-"<<m_modbusRtuTimeTick;
                    m_connectionStart = StartProcess::SpStarted;
                    m_isStart = StartStatus::StStarted;
                    emit error(Error::NoError);
                    m_modbusRtuTimeTick = 0;
                }
                else{
                        m_connectionStart = StartProcess::SpSetAddress;     //qDebug()<<m_deviceInfo.address()<<": Error-"<<m_modbusRtuTimeTick;
                        m_measureRetries = 0;
                        m_modbusRtuTimeTick = 0;
                    }
            }
        break;
    case StartProcess::SpStarted:
        if(!measurePoll())m_connectionStart = StartProcess::SpIdle;
        m_modbusRtuTimeTick = 0;
        break;
    case StartProcess::SpError:
        break;
    }
    //Check timeOut Start
    if(m_modbusRtuTimeTick>(m_deviceInfo.sampleTime()+1000)){
        if(m_startPoll){
            m_connectionStart = StartProcess::SpIdle;
            m_reConnectNumber++;
            }
        }
}

bool EDevice::Measure()
{
if(m_requestProcess == RequestProcess::MIdle)m_requestProcess = RequestProcess::MSendRequest;
if(m_connectionStart!=StartProcess::SpIdle)return true;
return this->start();
}

bool EDevice::measurePoll()
{
m_modbusRtuSampleTime++;//qDebug()<<".";
switch(m_requestProcess){
    case RequestProcess::MIdle:
        m_isMeasure = MeasureStatus::MsIdle;
        m_modbusRtuTimeTick = 0;
        break;
    case RequestProcess::MSendRequest:
        m_modbusRtuSampleTime=0;
        if(m_requestSingle.status){
            m_requestProcess = RequestProcess::MMeasureSingle;
            m_isMeasure = MeasureStatus::MsSingle;
            m_requestSingle.status = false;
            }
            else {
                m_requestProcess = RequestProcess::MMeasurePeriodic;
                m_isMeasure = MeasureStatus::MsPeriodic;
                }
        break;
    case RequestProcess::MMeasureSingle:
        if(this->modbusRtuRequestSingle()){
            m_requestProcess = RequestProcess::MGetData;
            m_modbusRtuTimeTick = 0;
            }
        break;
    case RequestProcess::MMeasurePeriodic:
        if(this->modbusRtuRequestPeriodic()){
            m_requestProcess = RequestProcess::MGetData;
            m_modbusRtuTimeTick = 0;
            m_modbusTimeOutCount=0;
            }
        break;
    case RequestProcess::MGetData:
        if(m_deviceReply.reply){
            if(this->modbusRtuGetData()){
                m_requestProcess = RequestProcess::MCheckTime;
                m_measureRetries = 0;
                m_modbusRtuTimeTick = 0;
                }
                else{
                    m_requestProcess = RequestProcess::MError;
                    }
            }
        if(m_deviceReply.request)m_modbusTimeOutCount++;
        break;
    case RequestProcess::MCheckTime:
        if(m_isMeasure == MeasureStatus::MsSingle)m_requestProcess = RequestProcess::MCheckType;
        else
            if(m_modbusRtuSampleTime>m_deviceInfo.sampleTime())m_requestProcess = RequestProcess::MCheckType;
        break;
    case RequestProcess::MCheckType:
        if(m_measureType==MeasureType::MPeriodic)m_requestProcess = RequestProcess::MSendRequest;
            else m_requestProcess = RequestProcess::MIdle;
        break;
    case RequestProcess::MError:
        m_measureRetries = 0;
        m_requestProcess = RequestProcess::MSendRequest;
        emit error(Error::ErrorRequestData);
        return false;
    }
    if(m_modbusRtuTimeTick>(m_deviceInfo.sampleTime()+1000)){
        m_requestProcess = RequestProcess::MError;
        }
  // if(m_test++%100==0) qDebug()<<"request "<<m_test++;
return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ForModbusRTU


bool EDevice::modbusRtuSetAddress()
{
if(m_requestUnit.slaveAddress()!=m_deviceInfo.addressDefault())m_requestUnit.setSlaveAddress(m_deviceInfo.addressDefault());
    else m_requestUnit.setSlaveAddress(m_deviceInfo.address());    //Toggle Address
m_requestUnit.setType(ERequestUnit::RequestType::Write);
QVector<quint16> value;
value.append((unsigned short)(m_deviceInfo.serial()>>16));
value.append((unsigned short)m_deviceInfo.serial());
value.append((unsigned short)m_deviceInfo.address());


auto _data = m_requestUnit.data();
_data.setRegisterType(QModbusDataUnit::HoldingRegisters);
_data.setValues(value);
_data.setStartAddress(HOLDING_OFFSET);
_data.setValueCount(Device_ID+1);
m_requestUnit.setData(_data);

m_deviceReply.reply = false;
m_deviceReply.request = false;
m_requestUnit.setId(this->getRequestID(m_requestUnit.type()));
m_requestUnit.setTimeout(100);
m_requestUnit.setRetries(0);
return m_connection->sendRequest(m_requestUnit);
}

bool EDevice::modbusRtuGetAddress()
{
    if(!m_deviceReply.reply)return false;
    return true;
}

bool EDevice::modbusRtuRequestSerialNumber()
{
    m_requestUnit.setSlaveAddress(m_deviceInfo.address());
    m_requestUnit.setType(ERequestUnit::RequestType::Read);

    auto _data = m_requestUnit.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(HOLDING_OFFSET);
    _data.setValueCount(2);
    m_requestUnit.setData(_data);

    m_deviceReply.reply = false;
    m_deviceReply.request = false;
    m_requestUnit.setId(this->getRequestID(m_requestUnit.type()));
    //m_requestUnit.setTimeout(30);
    m_requestUnit.setTimeout(m_deviceInfo.timeOut());
    m_requestUnit.setRetries(0);
    return m_connection->sendRequest(m_requestUnit);
}

bool EDevice::modbusRtuGetSerialNumber()
{
    if(m_deviceReply.unit.error()!=QModbusDevice::NoError)return false;   //check error
    //CheckSerialNumber
    int _sn = QVariant(m_deviceReply.unit.data().value(Device_SN1)&0xFFFF).toInt();
    _sn = _sn<<16;
    _sn = _sn|m_deviceReply.unit.data().value(Device_SN2);
    if(_sn!=m_deviceInfo.serial())return false;
    return true;
}

bool EDevice::modbusRtuRequestSingle()
{
    m_deviceReply.reply = false;
    m_deviceReply.request = false;
    m_requestSingle.request.setSlaveAddress(m_deviceInfo.address());
    m_requestSingle.request.setId(this->getRequestID(m_requestSingle.request.type()));
    m_requestSingle.request.setTimeout(m_deviceInfo.timeOut());
    return m_connection->sendRequest(m_requestSingle.request);
}

bool EDevice::modbusRtuRequestPeriodic()
{
    //Calculate Timeout
    /*int _time = this->calculateTimeOut();
    if(_time>0){
        m_requestPeriodic.request.setTimeout(_time);
    }*/
    m_deviceReply.reply = false;
    m_deviceReply.request = false;
    m_requestPeriodic.request.setSlaveAddress(m_deviceInfo.address());
    m_requestPeriodic.request.setId(this->getRequestID(m_requestPeriodic.request.type()));
    return m_connection->sendRequest(m_requestPeriodic.request);
}

bool EDevice::modbusRtuGetData()
{
    if(m_deviceReply.unit.error()!=QModbusDevice::NoError)return false;   //check error
    //ELog::log(m_deviceInfo,m_deviceReply.unit);
    emit result(m_deviceReply.unit);
    return true;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ForMacro
int EDevice::calculateTimeOut()
{
    if(m_modbusTimeOut.count()>=5)m_modbusTimeOut.removeFirst();
    m_modbusTimeOut.append(m_modbusTimeOutCount);
    if(m_modbusTimeOut.count()==5){
        double sum=0;
        for(int i=0;i<5;i++){
            sum += QVariant(m_modbusTimeOut.at(i)).toDouble();
        }
        sum = (sum/5)*1.2;  //1.5 is safe coefficient
        if(sum<5||sum>100)sum = 50;
        return QVariant(sum).toInt();
    }
    return -1;
}

