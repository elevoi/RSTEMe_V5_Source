#include "edeviceparameter.h"
#include <QtMath>
#include <QDebug>
EDeviceParameter::EDeviceParameter()
{

}

void EDeviceParameter::appendUnit(QString name, QString symbol, double factor,double offset)
{
UnitType _unit;
_unit.name = name;
_unit.symbol = symbol;
_unit.factor = factor;
_unit.offset = offset;
m_displayParameter.unit.append(_unit);
}

void EDeviceParameter::setCurrentUnit(QString name, QString symbol, double factor, double offset)
{
    m_unit.name = name;
    m_unit.symbol = symbol;
    m_unit.factor = factor;
    m_unit.offset = offset;
}

void EDeviceParameter::appendResolution(QString name, double factor)
{
ResolutionType _res;
_res.name = name;
_res.factor = factor;
m_displayParameter.resolution.append(_res);
}

void EDeviceParameter::updateDataHoldingSensor(quint16 add, quint16 value)
{
    switch(add){
        case DEVICE_SN1:this->setSerial(value);
            break;
        case DEVICE_SN2:this->setSerial((this->serial()*65535)+value);
            break;
        case DEVICE_ID:this->setId(value);
            break;
        case SENSOR_STATUS:this->setSensorStatus(value);
            break;
        case SENSOR_CAL01X_HI:this->setCalibPointOne(QPointF(QVariant(value).toDouble(),this->calibPointOne().y()));
            break;
        case SENSOR_CAL01X_LO:this->setCalibPointOne(QPointF((this->calibPointOne().x()*65536)+QVariant(value).toDouble(),this->calibPointOne().y()));
            break;
        case SENSOR_CAL01Y_HI:this->setCalibPointOne(QPointF(this->calibPointOne().x(),QVariant(value).toDouble()));
            break;
        case SENSOR_CAL01Y_LO:this->setCalibPointOne(QPointF(this->calibPointOne().x(),(this->calibPointOne().y()*65536)+QVariant(value).toDouble()));
            break;
        case SENSOR_CAL02X_HI:this->setCalibPointTwo(QPointF(QVariant(value).toDouble(),this->calibPointTwo().y()));
            break;
        case SENSOR_CAL02X_LO:this->setCalibPointTwo(QPointF((this->calibPointTwo().x()*65536)+QVariant(value).toDouble(),this->calibPointTwo().y()));
            break;
        case SENSOR_CAL02Y_HI:this->setCalibPointTwo(QPointF(this->calibPointTwo().x(),QVariant(value).toDouble()));
            break;
        case SENSOR_CAL02Y_LO:this->setCalibPointTwo(QPointF(this->calibPointTwo().x(),(this->calibPointTwo().y()*65536)+QVariant(value).toDouble()));
            break;
        case SENSOR_CAL03X_HI:this->setCalibPointThree(QPointF(QVariant(value).toDouble(),this->calibPointThree().y()));
            break;
        case SENSOR_CAL03X_LO:this->setCalibPointThree(QPointF((this->calibPointThree().x()*65536)+QVariant(value).toDouble(),this->calibPointThree().y()));
            break;
        case SENSOR_CAL03Y_HI:this->setCalibPointThree(QPointF(this->calibPointThree().x(),QVariant(value).toDouble()));
            break;
        case SENSOR_CAL03Y_LO:this->setCalibPointThree(QPointF(this->calibPointThree().x(),(this->calibPointThree().y()*65536)+QVariant(value).toDouble()));
            this->updateCalibFactor();
            break;
        case SENSOR_RESOLUTION:this->setDivision(value);
            break;
        case SENSOR_ADC_HI:m_valueRaw = value;
            break;
        case SENSOR_ADC_LO:this->setAdc(this->convertUnit(decryption_toDouble((quint32)(m_valueRaw<<16)|value)));
            break;
        case SENSOR_VALUE_HI:m_valueRaw = value;
            break;
        case SENSOR_VALUE_LO:this->setValue(this->getResolution(this->convertUnit(decryption_toDouble((quint32)(m_valueRaw<<16)|value))));
            break;
        case SENSOR_TEMP:this->setTemp(decryption_toDouble(value));
            break;
        case SENSOR_ZERO_HI:m_valueRaw = value;
            break;
        case SENSOR_ZERO_LO:this->setZero(this->convertUnit(decryption_toDouble((quint32)(m_valueRaw<<16)|value)));
            break;
        case SENSOR_CTRL:this->setControl(value);
            break;
        case DATA_SAMPLE_TIME:this->setSampleTime(value);
            break;
        case DATA_TIME_TICK_HI:m_timeTickRaw = value;
            break;
        case DATA_TIME_TICK_LO:this->setTimeTick((m_timeTickRaw<<16)|value);
            break;
        case DATA_BUFFER:
                this->removeValues();
                this->removeAdcs();
                m_valueRaw_Count = 0;
                this->updateBuffer(value);
                break;
        }
    //update buffer
    if(add>DATA_BUFFER)this->updateBuffer(value);
}

void EDeviceParameter::finishUpdateDataSensor()
{
    this->setTemp(this->temp()/100);
    this->setTempCpu(this->tempCpu()/100);
    if(this->values().count()<1)return;
    qreal _sum=0;
    foreach (auto var, this->values()) {
        _sum += var;
    }
    qreal _raw = _sum/this->values().count();
    _raw = QString::number(_raw,'f',this->currentResolution().factor).toDouble();
    this->setValue(_raw);
}

qreal EDeviceParameter::convertUnit(qreal value)
{
    qreal _raw=0;
    _raw = value*this->currentUnit().factor+this->currentUnit().offset;
    return _raw;
}

qreal EDeviceParameter::getResolution(qreal value)
{
return QString::number(value,'f',this->currentResolution().factor).toDouble();
}
double EDeviceParameter::getConvertValue(double value,UnitType unit, ResolutionType res)
{
    qreal _raw = value*unit.factor+unit.offset;
    _raw = QString::number(_raw,'f',res.factor).toDouble();
    return _raw;
}
void EDeviceParameter::updateBuffer(uint16_t val)
{
     if(val==0xFFFF)return;
     double _adc = 0;
     switch(m_bufferType){
     case BUFFER_TYPE::BUF_8_BIT:
         _adc = this->convertUnit(decryption_toDouble((quint8)(val>>8)));
         this->addAdcs(_adc);
         this->addValues(this->getCalib(_adc));
         _adc = this->convertUnit(decryption_toDouble((quint8)val));
         this->addAdcs(_adc);
         this->addValues(this->getCalib(_adc));
         break;
     case BUFFER_TYPE::BUF_16_BIT:
         _adc = this->convertUnit(decryption_toDouble((quint16)val));
         this->addAdcs(_adc);
         this->addValues(this->getCalib(_adc));
         break;
     case BUFFER_TYPE::BUF_32_BIT:
         if(m_valueRaw_Count++%2==0)m_valueRaw = val;
         else{
            _adc = this->convertUnit(decryption_toDouble((quint32)(m_valueRaw<<16)|val));
            this->addAdcs(_adc);
            this->addValues(this->getCalib(_adc));
         }
         break;
     }
}

void EDeviceParameter::setSensorStatus(quint16 val)
{
    quint8 _st = (quint8)(val&0xFF);
    quint8 _err = (quint8)((val>>8)&0xFF);
    this->setStatus(_st);
    this->setStatus(_err);
    //check temp compensation
    if(_st&(1<<7))this->setIsTempComp(true);
        else this->setIsTempComp(false);
}

quint8 EDeviceParameter::encode_toUInt8(double f, int m)
{
    quint8 _val = 0;
    if(f<0){
        f *= (-1);
        _val = 0x80;
    }
    _val |= (quint8)(f*pow(10,m));
    return _val;
}

double EDeviceParameter::decryption_toDouble(quint8 val)
{
    double _f = 1;
    if(val&0x80){
        val &= ~0x80;
        _f *= (-1);
    }
    _f *= (double)val;
    return _f;
}

double EDeviceParameter::decryption_toDouble(quint8 val, int m)
{
    double _f = 1;
    if(val&0x80){
        val &= ~0x80;
        _f *= (-1);
    }
    _f *= (double)val/pow(10,m);
    return _f;
}

quint16 EDeviceParameter::encode_toUInt16(double f, int m)
{
    quint16 _val = 0;
    if(f<0){
        f *= (-1);
        _val = 0x8000;
    }
    _val |= (quint16)(f*pow(10,m));
    return _val;
}

double EDeviceParameter::decryption_toDouble(quint16 val)
{
    double _f = 1;
    if(val&0x8000){
        val &= ~0x8000;
        _f *= (-1);
    }
    _f *= (double)val;
    return _f;
}

double EDeviceParameter::decryption_toDouble(quint16 val, int m)
{
    double _f = 1;
    if(val&0x8000){
        val &= ~0x8000;
        _f *= (-1);
    }
    _f *= (double)val/pow(10,m);
    return _f;
}

quint32 EDeviceParameter::encode_toUInt32(double f, int m)
{
    quint32 _val = 0;
    if(f<0){
        f *= (-1);
        _val = 0x80000000;
    }
    _val |= (quint32)(f*pow(10,m));
    return _val;
}

double EDeviceParameter::decryption_toDouble(quint32 val)
{
    double _f = 1;
    if(val&0x80000000){
        val &= ~0x80000000;
        _f *= (-1);
    }
    _f *= (double)val;
    return _f;
}

double EDeviceParameter::decryption_toDouble(quint32 val, int m)
{
    double _f = 1;
    if(val&0x80000000){
        val &= ~0x80000000;
        _f *= (-1);
    }
    _f *= (double)val/pow(10,m);
    return _f;
}




////////////////////////////////////////////////////////////Calibration
///
bool EDeviceParameter::calibSort(QPointF &v1, QPointF &v2)
{
    return (v1.y()<v2.y());
}
void EDeviceParameter::updateCalibFactor(){
    //sord
    QList<QPointF> _list;
    foreach (auto var, m_calibType.point) {
        if((var.x()!=0xFFFFFFFF)&&(var.y()!=0xFFFFFFFF)){
            _list.append(QPointF(decryption_toDouble((uint32_t)var.x(),this->calibResolution().factor),decryption_toDouble((uint32_t)var.y(),this->calibResolution().factor)));
            }
        }
    std::sort(_list.begin(),_list.end(),this->calibSort);
    m_calibType.number = _list.count();
    //get number of calib point
    switch(m_calibType.number){
    case 1:m_calibType.a1 = _list.at(0).y()/_list.at(0).x();//y = ax => a = y/x
        break;
    case 2:
        m_calibType.a1 = (_list.at(0).y()-_list.at(1).y())/(_list.at(0).x()-_list.at(1).x()); //a = (y1-y2)/(x1-x2)
        m_calibType.b1 = _list.at(0).y() - (m_calibType.a1*_list.at(0).x());
        break;
    case 3:
        m_calibType.a1 = (_list.at(0).y()-_list.at(1).y())/(_list.at(0).x()-_list.at(1).x()); //a = (y1-y2)/(x1-x2)
        m_calibType.b1 = _list.at(0).y() - (m_calibType.a1*_list.at(0).x());

        m_calibType.a2 = (_list.at(1).y()-_list.at(2).y())/(_list.at(1).x()-_list.at(2).x()); //a = (y1-y2)/(x1-x2)
        m_calibType.b2 = _list.at(1).y()- (m_calibType.a2*_list.at(1).x());
        break;
    }
}
double EDeviceParameter::getCalib(double value){
    auto _val = value;
    switch(m_calibType.number){
    case 1:
        _val = this->calibOnePoint(value);
        break;
    case 2:
        _val = this->calibTwoPoint(value);
        break;
    case 3:
        _val = this->calibThreePoint(value);
        break;
    }
    _val = QString::number(_val,'f',this->currentResolution().factor).toDouble();
    return _val;
}

double EDeviceParameter::calibOnePoint(double value){
    //y = ax
    return (value*m_calibType.a1);
}
double EDeviceParameter::calibTwoPoint(double value){
    //y = ax + b
    return ((value*m_calibType.a1)+m_calibType.b1);
}
double EDeviceParameter::calibThreePoint(double value){
    double _calib = 0;
    auto _list = m_calibType.point;
    std::sort(_list.begin(),_list.end(),this->calibSort);
    //y = a1x+b1 from (x1,y1) to (x2,y2),y = a2x+b2 from (x2,y2) to (x3,y3)
    if(value<=_list.at(1).x())_calib = (value*m_calibType.a1)+m_calibType.b1;
        else _calib = (value*m_calibType.a2)+m_calibType.b2;
    return _calib;
}
