#include "esensor.h"
#include "QDebug"

QT_CHARTS_USE_NAMESPACE

ESensor::ESensor(EDevice *dev):m_edevice(dev)
{
this->setDevice(dev);
}
ESensor::ESensor(QObject *parent, EDevice *dev):QObject(parent)
{
    this->setDevice(dev);
}
ESensor::~ESensor()
{
    if(m_edef){delete m_edef;m_edef = nullptr;}
}

void ESensor::setDevice(EDevice *dev)
{
this->destroy();
m_edevice = dev;
this->init();
}

void ESensor::appendSeries(qreal tick)
{
    if(!m_seriesValue)return;
    if(m_seriesValue->count()<1)m_timeTickLast=0;
    if(m_edeviceParameter.values().count()<1)return;
    if(m_timeTickLast>=tick)return;
    qreal elap = this->elapsed(tick,m_timeTickLast)/QVariant(m_edeviceParameter.values().count()).toDouble();
    for(int i=0;i<m_edeviceParameter.values().count();i++){
        if(m_seriesValue->count()>=m_series_Max)m_seriesValue->remove(0);
        m_timeTickLast += elap;
        //check time reset
        //qDebug()<<_time<<"-"<<m_edeviceParameter.values().at(i)<<">>"<<m_edeviceParameter.values().count();
        m_seriesValue->append(QPointF(m_timeTickLast,m_edeviceParameter.values().at(i)));
        if(m_edeviceParameter.isTemp()){
            if(!m_seriesTemperature)return;
            if(m_seriesTemperature->count()>=m_series_Max)m_seriesTemperature->remove(0);
            m_seriesTemperature->append(QPointF(m_timeTickLast,m_edeviceParameter.temp()));
        }
    }
}

void ESensor::replaceSeries(qreal interval,uint32_t &index,qreal max)
{
    if(!m_seriesValue)return;
    if(m_seriesValue->count()<1)m_timeTickLast=0;
    if(m_edeviceParameter.values().count()<1)return;
    for(int i=0;i<m_edeviceParameter.values().count();i++){
        m_timeTickLast += interval;
        //check time reset
        if((int)index<m_seriesValue->count())m_seriesValue->replace(index,QPointF(m_seriesValue->at(index).x(),m_edeviceParameter.values().at(i)));
            else m_seriesValue->append(QPointF(m_timeTickLast,m_edeviceParameter.values().at(i)));
        if(m_edeviceParameter.isTemp()){
            if(!m_seriesTemperature)return;
            if(m_seriesTemperature->count()>=m_series_Max)m_seriesTemperature->remove(0);
            if((int)index<m_seriesTemperature->count())m_seriesTemperature->replace(index,QPointF(m_seriesTemperature->at(index).x(),m_edeviceParameter.temp()));
                else m_seriesTemperature->append(QPointF(m_timeTickLast,m_edeviceParameter.temp()));
        }
        index++;
        if(m_timeTickLast>max){
            index=0;
            m_timeTickLast = 0;
        }
    }
}

EDeviceParameter ESensor::devicePara(EDeviceInfo dev)
{
    EDef _def(dev);
return _def.parameter();
}

void ESensor::setParameter(EDeviceParameter var)
{
m_edeviceParameter = var;
this->setDevicePara(var);
}

void ESensor::start()
{
    if(!m_edevice)return;
    this->measureStart();
}

void ESensor::start(uint32_t tick)
{
    if(!m_edevice)return;
    this->measureStart(tick);
}




void ESensor::init()
{
    if(!m_edevice)return;
    m_edeviceInfo = m_edevice->deviceInfo();
    if(m_edef){delete m_edef;m_edef = nullptr;}
    m_edef = new EDef(m_edeviceInfo);
    m_edeviceParameter = this->getDevicePara();
    //para
    m_edeviceParameter.setClock(m_edeviceInfo.rangeMax(),m_edeviceInfo.rangeMin());
    m_edeviceParameter.setRegType(m_edeviceInfo.regStart(),m_edeviceInfo.regNumber());
    this->setDevicePara(m_edeviceParameter);
    //request
    m_requestUnit.setPriority(m_edeviceInfo.priority());
    m_requestUnit.setRetries(m_edeviceInfo.retries());
    m_requestUnit.setTimeout(m_edeviceInfo.timeOut());
    //device
    QObject::connect(m_edevice,&EDevice::result,this,&ESensor::on_result);
    QObject::connect(m_edevice,&EDevice::error,this,&ESensor::on_error);

    //chart
    this->initChart();
}

void ESensor::on_result(ERequestUnit request)
{
if(request.slaveAddress()!=m_edevice->deviceInfo().address())return;
if(request.error()!=QModbusDevice::NoError)return;
if(request.type()==ERequestUnit::Write)return;
m_requestUnit = request;
this->setRequest();
m_edeviceParameter = getDevicePara();
//this->appendSeries();
emit this->newData(m_requestUnit.id());
emit this->newDataDevice(m_edevice);
}

void ESensor::on_error(EDevice::Error error)
{
    ELog::log(error);
    emit this->error(error);
}
void ESensor::destroy()
{
    if(m_edevice){
        QObject::disconnect(m_edevice,&EDevice::result,this,&ESensor::on_result);
        QObject::disconnect(m_edevice,&EDevice::error,this,&ESensor::on_error);
    }
}
void ESensor::measureStart()
{
    if(m_edevice->isStart()==EDevice::StIdle){
        m_edevice->start();
        this->setSampleTime(m_edeviceInfo.sampleTime());
        this->setMeasurePeriodic();
    }
}
void ESensor::measureStart(uint32_t tick)
{
    if(m_edevice->isStart()==EDevice::StIdle){
        m_edevice->start();
        this->setTimeDefault(m_edeviceInfo.sampleTime(),tick);
        this->setMeasurePeriodic();
        }
}

EDeviceParameter ESensor::getDevicePara()
{
    if(m_edef)m_edeviceParameter = m_edef->parameter();
    return m_edeviceParameter;
}

void ESensor::setDevicePara(EDeviceParameter para)
{
    if(!m_edef)return;
    m_edef->setParameter(para);
}


void ESensor::setRequest()
{
    if(!m_edef)return;
    m_edef->setRequest(m_requestUnit);
}

uint32_t ESensor::elapsed(uint32_t now, uint32_t last)
{
    if(now>=last)return (now-last);
    else return (((uint32_t)-last)+now);
}

qreal ESensor::elapsed(qreal now, qreal last)
{
return (now>last)?(now-last):(last-now);
}
void ESensor::setTimeDefault(int time, uint32_t tick)
{
    QVector<quint16> val;
    auto _request = ERequestUnit::getRequestWrite();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET+EDeviceParameter::DATA_SAMPLE_TIME);
    _data.setValueCount(3);
    val.append(time);
    val.append((quint16)(tick>>16));
    val.append((quint16)tick);
    _data.setValues(val);
    _request.setData(_data);

    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(30);

    m_edevice->MeasureRequest(_request);
}


void ESensor::setTempCompensation(bool var)
{
    QVector<quint16> val;
    auto _request = ERequestUnit::getRequestWrite();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET+EDeviceParameter::SENSOR_STATUS);
    _data.setValueCount(1);
    m_edeviceParameter = this->getDevicePara();
    /*
    typedef enum{
        ESS_None = 0,
        ESS_TEMP_COMP = 7//1: set temperature compensation, 0: none
    }ESensorStatus_TypeDef;
     */
    quint16 _st = m_edeviceParameter.status();
    if(var)_st|=(1<<7); //set temperature compensation
        else _st&=~(1<<7);//clear temperature compensation
    val.append(_st);
    _data.setValues(val);
    _request.setData(_data);

    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(30);

    m_edevice->MeasureRequest(_request);


    m_edeviceParameter.setIsTempComp(var);
    this->setDevicePara(m_edeviceParameter);
}

void ESensor::setControl(uint16_t ctrl)
{
    QVector<quint16> val;
    auto _request = ERequestUnit::getRequestWrite();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET+EDeviceParameter::SENSOR_CTRL);
    _data.setValueCount(1);
    val.append(ctrl);
    _data.setValues(val);
    _request.setData(_data);

    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(30);

    m_edevice->MeasureRequest(_request);
}

void ESensor::setZero(uint32_t zero)
{
    QVector<quint16> val;
    auto _request = ERequestUnit::getRequestWrite();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET+EDeviceParameter::SENSOR_ZERO_HI);
    _data.setValueCount(2);
    val.append((quint16)(zero>>16));
    val.append((quint16)zero);
    _data.setValues(val);
    _request.setData(_data);

    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(30);

    m_edevice->MeasureRequest(_request);
}


void ESensor::setSampleTime()
{
this->setSampleTime(m_edeviceInfo.sampleTime());
}
void ESensor::setSampleTime(int time)
{
    QVector<quint16> val;
    auto _request = ERequestUnit::getRequestWrite();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET+EDeviceParameter::DATA_SAMPLE_TIME);
    _data.setValueCount(1);
    auto dev = m_edevice->deviceInfo();
    if(time<dev.timeOut())time = dev.timeOut();
    dev.setSampleTime(time);
    m_edevice->setDeviceInfo(dev);
    val.append(time);
    _data.setValues(val);
    _request.setData(_data);

    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(30);

    m_edevice->MeasureRequest(_request);

}
void ESensor::setTimeTick(uint32_t time)
{
    QVector<quint16> val;
    auto _request = ERequestUnit::getRequestWrite();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET+EDeviceParameter::DATA_TIME_TICK_HI);
    _data.setValueCount(2);
    val.append((quint16)(time>>16));
    val.append((quint16)time);
    _data.setValues(val);
    _request.setData(_data);

    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(30);

    m_edevice->MeasureRequest(_request);
}

void ESensor::setMeasurePeriodic()
{
    auto _request = ERequestUnit::getRequestRead();
    auto _data = _request.data();
    if(m_edeviceParameter.reg().RegStart>=40000)_data.setRegisterType(QModbusDataUnit::HoldingRegisters);
        else _data.setRegisterType(QModbusDataUnit::InputRegisters);
    _data.setStartAddress(m_edeviceParameter.reg().RegStart);
    _data.setValueCount(m_edeviceParameter.reg().RegNumber);
    _request.setData(_data);

    _request.setPriority(m_requestUnit.priority());
    _request.setRetries(m_requestUnit.retries());
    _request.setTimeout(m_requestUnit.timeout());

    m_edevice->MeasurePeriodic(_request);
}

void ESensor::setCalib(int p,uint32_t x, uint32_t y)
{
    QVector<quint16> val;
    auto _request = ERequestUnit::getRequestWrite();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET+EDeviceParameter::SENSOR_CAL01X_HI + (p*4));
    _data.setValueCount(4);
    val.append((quint16)(x>>16));
    val.append((quint16)x);
    val.append((quint16)(y>>16));
    val.append((quint16)y);
    _data.setValues(val);
    _request.setData(_data);

    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(30);

    m_edevice->MeasureRequest(_request);
}




//===========================================================================================Chart
void ESensor::initChart()
{
if(m_seriesValue){m_seriesValue->deleteLater();m_seriesValue = nullptr;}
if(m_seriesTemperature){m_seriesTemperature->deleteLater();m_seriesTemperature = nullptr;}
 m_listSeries.clear();
 //default
 m_seriesValue = new QLineSeries;
 m_seriesValue->setPen(QPen(Qt::green,2));
 m_seriesValue->setName(m_edeviceInfo.name());
 m_listSeries.append(m_seriesValue);

 if(m_edeviceParameter.isTemp()){
     m_seriesTemperature = new QLineSeries;
     m_seriesTemperature->setPen(QPen(Qt::red,2));
     m_seriesTemperature->setName("Nhiệt độ");
     m_listSeries.append(m_seriesTemperature);
 }
}





