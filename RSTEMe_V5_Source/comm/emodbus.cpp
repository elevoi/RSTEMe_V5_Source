#include "emodbus.h"
#include <QVariant>
#include <QDebug>


EModbus::EModbus(QObject *parent)
    : QObject{parent}
{

}

EModbus::~EModbus()
{
    if(m_modbusDevice){
        m_modbusDevice->disconnectDevice();
        m_modbusDevice->deleteLater();
        m_modbusDevice = nullptr;
    }
}


void EModbus::on_modbusRequest(ERequestUnit request)
{
    //check connect
    if(!this->connectModbus(request)){
        emit this->error(QModbusDevice::ConnectionError);
        return;
        }
    m_requestUnit = request;
    if(request.type()==ERequestUnit::Read){
        //qDebug()<<"TimeOut:"<<request.timeout();
        if(!this->readRequestModbus(request))emit this->error(QModbusDevice::ReadError);
        }
        else {
            if(!this->writeRequestModbus(request))emit this->error(QModbusDevice::WriteError);
            }
}


bool EModbus::connectModbus(ERequestUnit request)
{
    bool m_isConnect = false;
    if(!m_modbusDevice){
        m_modbusDevice = new QModbusRtuSerialMaster(this);
        }
        else m_modbusDevice->disconnectDevice();
    if(m_modbusDevice->state()!=QModbusDevice::ConnectedState){
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,request.comPort());
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::NoParity);
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,request.baudRate());
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);
        //modbus time
        m_modbusDevice->setTimeout(request.timeout());
        m_modbusDevice->setNumberOfRetries(request.retries());
        //connect to modbus
        m_isConnect = m_modbusDevice->connectDevice();
    }
    emit this->connected(m_isConnect);
    return m_isConnect;
}

/***************************************************************Modbus read Request**************************
  * @brief slots Function
  */
void EModbus::on_ReadReady()
{
auto _reply = qobject_cast<QModbusReply*>(sender());
if(_reply){
    m_requestUnit.setData(_reply->result());
    m_requestUnit.setError(_reply->error());
    m_requestUnit.setErrorString(_reply->errorString());
    emit this->reply(m_requestUnit);
     _reply->deleteLater();
    }
    else emit this->error(QModbusDevice::ReplyAbortedError);
}

void EModbus::on_WriteReady()
{
    auto _reply = qobject_cast<QModbusReply*>(sender());
    if(_reply){
        m_requestUnit.setData(_reply->result());
        m_requestUnit.setError(_reply->error());;
        m_requestUnit.setErrorString(_reply->errorString());
        emit this->reply(m_requestUnit);
         _reply->deleteLater();
        }
        else emit this->error(QModbusDevice::ReplyAbortedError);
}

void EModbus::on_errorOccurred(QModbusDevice::Error error)
{
emit this->error(error);
}

/*
* @brief request Function
*/
bool EModbus::readRequestModbus(ERequestUnit request)
{
if(auto *reply = m_modbusDevice->sendReadRequest(request.data(),request.slaveAddress())){
    if(!reply->isFinished()){
        QObject::connect(reply,&QModbusReply::finished,this,&EModbus::on_ReadReady);
        QObject::connect(reply,&QModbusReply::errorOccurred,this,&EModbus::on_errorOccurred);
        return true;
        }
        else reply->deleteLater();
    }
return false;
}

bool EModbus::writeRequestModbus(ERequestUnit request)
{
if(auto *reply = m_modbusDevice->sendWriteRequest(request.data(),request.slaveAddress())){
    if(!reply->isFinished()){
        QObject::connect(reply,&QModbusReply::finished,this,&EModbus::on_WriteReady);
        QObject::connect(reply,&QModbusReply::errorOccurred,this,&EModbus::on_errorOccurred);
        return true;
        }
        else reply->deleteLater();
    }
return false;
}

