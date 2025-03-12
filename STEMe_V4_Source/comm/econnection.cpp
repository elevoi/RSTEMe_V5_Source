#include "econnection.h"
#include <QDebug>
#include <QMetaType>
#include <device/def/edeviceparameter.h>


EConnection::EConnection(QObject *parent)
    : QObject{parent}
{
this->init();
}
EConnection::EConnection(SerialPort port)
{
    this->init();
    m_serialPort = port;
}

int EConnection::setConnect(SerialPort port)
{
m_serialPort = port;
auto _request = ERequestUnit::getRequestRead();
auto _data = _request.data();
_data.setRegisterType(QModbusDataUnit::HoldingRegisters);
_data.setStartAddress(40001);
_data.setValueCount(1);
_request.setData(_data);

_request.setSlaveAddress(127);
_request.setPriority(1);
_request.setRetries(1);
_request.setTimeout(20);
_request.setId(ERequestUnit::requestID());
this->sendRequest(_request);
return _request.requestID();
}

EConnection::~EConnection()
{
if(m_timerPoll){
    m_timerPoll->deleteLater();
    m_timerPoll = nullptr;
    }
if(m_emodbus){
    m_emodbus->deleteLater();
    m_emodbus = nullptr;
    }
if(m_thread){
    m_thread->quit();
    m_thread->wait();
    m_thread->deleteLater();
    m_thread = nullptr;
    }
}



void EConnection::init()
{
    //register Type
    qRegisterMetaType<ERequestUnit>("ERequestUnit");
    qRegisterMetaType<QModbusDevice::Error>("QModbusDevice::Error");

    if(m_emodbus){
        m_emodbus->deleteLater();
        m_emodbus = nullptr;
    }
    if(m_thread){
        m_thread->quit();
        m_thread->wait();
        m_thread->deleteLater();
        m_thread = nullptr;
        }
    m_emodbus = new EModbus();
    m_thread = new QThread();
    QObject::connect(m_thread,&QThread::finished,this,&EModbus::deleteLater);

    //signal and slot
    QObject::connect(this,&EConnection::modbusRequest,m_emodbus,&EModbus::on_modbusRequest);

    QObject::connect(m_emodbus,&EModbus::connected,this,&EConnection::on_connected);
    QObject::connect(m_emodbus,&EModbus::error,this,&EConnection::on_error);
    QObject::connect(m_emodbus,&EModbus::reply,this,&EConnection::on_reply);

    m_emodbus->moveToThread(m_thread);
    m_thread->start(QThread::TimeCriticalPriority);
    //Timer Test
    if(!m_timerPoll){
        m_timerPoll = new QTimer();
        QObject::connect(m_timerPoll,&QTimer::timeout,this,&EConnection::on_timerPoll);
    }
}

bool EConnection::sendRequest(ERequestUnit request)
{
    return this->insertRequestModbusRTU(request);
}

int EConnection::sendRequestId(ERequestUnit request)
{
    request.setId(ERequestUnit::requestID());
    if(this->insertRequestModbusRTU(request))return request.id();
    return -1;
}

void EConnection::on_connected(bool status)
{
m_isConnect = status;
emit this->connectChanged(status);
//resetDevice
if(status&&!m_resetSlaveAddress){
    this->resetSlaveAddress();
    }
m_resetSlaveAddress = status;
}

void EConnection::on_error(QModbusDevice::Error error)
{
m_stateRequest = false;
emit this->error(error);
m_requestUnit.setError(error);
emit this->errorOccurred(m_requestUnit);
}

void EConnection::on_timerPoll()
{
    this->modbusRequestPoll();
}
void EConnection::modbusRequestPoll()
{
    ERequestUnit _rq;
    if(!m_emodbus)return;
    if(m_stateRequest){
        if(m_errorSerialPort++>1000){
            m_stateRequest = false;
            m_slaveReseting = false;
            m_errorSerialPort = 0;
            emit this->errorOccurred(m_requestUnit);
            }
        return;
    }
    if(!getRequestModbusRTU(&_rq)){
        if(m_slaveReseting)m_slaveReseting = false;
        m_timerPoll->stop();
        return;
    }
    //update port
    _rq.setComport(m_serialPort.port);
    _rq.setBaudRate(m_serialPort.baudRate);
    //request
    emit modbusRequest(_rq);
    m_stateRequest = true;
    m_errorSerialPort = 0;
    m_requestUnit = _rq;
}

void EConnection::resetSlaveAddress()
{
    auto _requestUnit = ERequestUnit::getRequestRead();
    auto _data = _requestUnit.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET);
    _data.setValueCount(2);
    _requestUnit.setData(_data);
    _requestUnit.setTimeout(20);
    m_requestQueueRTU.clear();
    for(int i=1;i<=16;i++){
        _requestUnit.setSlaveAddress(i);
        m_requestQueueRTU.append(_requestUnit);
    }
    _requestUnit.setSlaveAddress(127);
    m_requestQueueRTU.append(_requestUnit);
    m_slaveReseting = true;
    //Check timerPoll
    if(!m_timerPoll->isActive())m_timerPoll->start(1);
}

void EConnection::searchSlave()
{
    auto _requestUnit = ERequestUnit::getRequestRead();
    auto _data = _requestUnit.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET);
    _data.setValueCount(2);
    _requestUnit.setData(_data);
    _requestUnit.setTimeout(20);
    for(int i=1;i<=32;i++){
        _requestUnit.setSlaveAddress(i);
        m_requestQueueRTU.append(_requestUnit);
    }
    _requestUnit.setSlaveAddress(127);
    m_requestQueueRTU.append(_requestUnit);
}

void EConnection::getSlaveAddress(ERequestUnit request)
{
if(!m_slaveReseting)return;
if(request.error()!=QModbusDevice::NoError)return;   //check error
//CheckSerialNumber
int _sn = QVariant(request.data().value(EDeviceParameter::DEVICE_SN1)&0xFFFF).toInt();
_sn = _sn<<16;
_sn = _sn|request.data().value(EDeviceParameter::DEVICE_SN2);
m_edeviceInfoList.load(false);
foreach (auto var, m_edeviceInfoList.deviceList()) {
    if(_sn == var.serial()){
        var.setAddress(request.slaveAddress());
        m_edeviceInfoList.replaceDevice(var);
       // qDebug()<<var.serialHex()<<":"<<var.address();
        }
    }
}

void EConnection::on_reply(ERequestUnit request)
{
    m_stateRequest = false;
    if(m_slaveReseting)this->getSlaveAddress(request);
    else emit this->reply(request);
}

////////////////////////////////////////////////////////////////////////////////Request Buffer
bool EConnection::insertRequestModbusRTU(ERequestUnit request)
{
int place=-1;
if(m_slaveReseting)return false;                        //Communication is reseting
if(!this->checkRequestModbusRTU(request))return false;
for(int i=0;i<m_requestQueueRTU.count();i++){
    if(m_requestQueueRTU.at(i).priority()>request.priority()){
        place = i;break;
    }
}
if(place==-1)m_requestQueueRTU.append(request);
    else m_requestQueueRTU.insert(place,request);
//Check timerPoll
if(!m_timerPoll->isActive())m_timerPoll->start(1);
return true;
}

bool EConnection::getRequestModbusRTU(ERequestUnit *request)
{
if(m_requestQueueRTU.isEmpty())return false;
*request = m_requestQueueRTU.first();
m_requestQueueRTU.removeFirst();
return true;
}

bool EConnection::checkRequestModbusRTU(ERequestUnit request)
{
    foreach (auto rq, m_requestQueueRTU) {
        if(rq.slaveAddress() == request.slaveAddress())return false;
    }
    return true;
}


