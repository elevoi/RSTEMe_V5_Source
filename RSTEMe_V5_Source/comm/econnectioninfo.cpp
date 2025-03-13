#include "econnectioninfo.h"
#include <QJsonArray>
#include <QSettings>

EConnectionInfo::EConnectionInfo()
{

}

void EConnectionInfo::save()
{
    this->updateJsonObject();
    this->saveDocument();
}

bool EConnectionInfo::load()
{
return this->loadDocument();
}

void EConnectionInfo::updateJsonObject()
{
    //Parameter
    m_jsonObject.insert("ModbusPort",m_connectPrarameter.ModbusPort);
    m_jsonObject.insert("ModbusBaud",m_connectPrarameter.ModbusBaud);
    m_jsonObject.insert("NetworkIP",m_connectPrarameter.NetworkIP);
}

void EConnectionInfo::setJsonObject(QJsonObject json)
{
    m_connectPrarameter.ModbusPort = this->getJsonValue(json.value("ModbusPort"),QJsonValue("COM7")).toString();
    m_connectPrarameter.ModbusBaud = this->getJsonValue(json.value("ModbusBaud"),QJsonValue(115200)).toInt();
    m_connectPrarameter.NetworkIP = this->getJsonValue(json.value("NetworkIP"),QJsonValue("127.0.0.1")).toString();
}

QJsonValue EConnectionInfo::getJsonValue(QJsonValue value, QJsonValue init)
{
    if(value==QJsonValue::Undefined)return init;
    else return value;
}

void EConnectionInfo::saveDocument()
{
    QJsonDocument jsDoc;
//return false;
    QSettings settings("ELEVOI","STEME");
    settings.beginWriteArray("EConnectionInfo");
    settings.remove("");
    jsDoc.setObject(m_jsonObject);
    settings.setArrayIndex(0);
    settings.setValue("ConnectionParameter",jsDoc.toJson());
    settings.endArray();
}

bool EConnectionInfo::loadDocument()
{
    QSettings settings("ELEVOI","STEME");
    QJsonObject jsDevice;
    QJsonDocument jsDoc;
    //get data from setting file.
    settings.beginWriteArray("EConnectionInfo");
    settings.setArrayIndex(0);
    QString _device = settings.value("ConnectionParameter","").toString();
    settings.endArray();
    jsDoc = QJsonDocument::fromJson(_device.toUtf8());
    jsDevice = jsDoc.object();
    if(jsDevice.isEmpty())return false;
    this->setJsonObject(jsDevice);
    return true;
}
