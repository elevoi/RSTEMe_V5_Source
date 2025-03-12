#include "elog.h"
#include "device/edeviceinfo.h"


ELog::DataTypeLog ELog::m_dataTypeLog=ELog::DataTypeLog::DATA_REG_DEC;
ELog::ELog(QObject *parent)
    : QObject{parent}
{
}

void ELog::log(const QVariant var)
{
    qDebug()<<var;
}

void ELog::log(ERequestUnit unit)
{
    QString str="";
    switch(m_dataTypeLog){
    case DataTypeLog::DATA_REG_DEC:
        str+= "Slave-"+QString::number(unit.slaveAddress())+": ";
        for(uint i=0;i<unit.data().valueCount();i++){
            str+=QString::number(unit.data().value(i));
            str+="-";
        }
        qDebug()<<str;
        break;
    case DataTypeLog::DATA_REG_HEX:
        str+= "Slave:"+QString::number(unit.slaveAddress())+"Data: ";
        for(uint i=0;i<unit.data().valueCount();i++){
            str+=QString::number(i) + ":" + QString("%1").arg(unit.data().value(i),4, 16, QLatin1Char( '0' ));
            str+=" | ";
        }
        qDebug()<<str;
        break;
    }
}

void ELog::log(EDeviceInfo dev, ERequestUnit unit)
{
    QString str="";
    str+= "("+QString::number(unit.id()) + ") -> " + dev.serialHex() + "-" + QString::number(unit.slaveAddress()) + "-"\
        + QString::number(unit.data().valueCount()) + "-" + QString::number(unit.timeRequest());
  //  qDebug()<<str;
}

void ELog::log(EDevice::Error error)
{
    return;
    switch(error){
        case EDevice::Error::NoError:
            //qDebug()<<"NoError";
            break;
        case EDevice::Error::ErrorSetAddress:
            qDebug()<<"Error set Address!";
            break;
        case EDevice::Error::ErrorSerialNumber:
            qDebug()<<"Error check SerialNumber!";
            break;
        case EDevice::Error::ErrorRequestData:
            qDebug()<<"Error request data, check connect!";
            break;
        case EDevice::Error::ErrorStart:
            qDebug()<<"Error request data, check connect!";
            break;
    }
}




