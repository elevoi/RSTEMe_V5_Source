#include "edeviceinfo.h"
#include <QFile>
#include <QFileDialog>
#include <QCoreApplication>
#include <QMessageBox>

EDeviceInfo::EDeviceInfo()
{

}

EDeviceInfo::EDeviceInfo(QJsonObject object)
{
m_jsonObject = object;
this->setJsonObject(m_jsonObject);
}

QJsonObject EDeviceInfo::getJsonDevice()
{
this->updateJsonObject();
    return m_jsonObject;
}

void EDeviceInfo::setJsonDevice(QJsonObject jsonObject)
{
    this->setJsonObject(jsonObject);
}

QString EDeviceInfo::serialHex(int var)
{
    return QString("%1").arg(var, 8, 16, QLatin1Char( '0' )).toUpper();
}

QString EDeviceInfo::serialHex(quint16 hi, quint16 lo)
{
int var = hi;
var = (var<<16)&lo;
return EDeviceInfo::serialHex(var);
}

int EDeviceInfo::serialDec(QString var, bool *ok)
{
return QString(var).toUInt(ok,16);
}

QString EDeviceInfo::serialHex()
{
return QString("%1").arg(this->serial(), 8, 16, QLatin1Char( '0' )).toUpper();
}

int EDeviceInfo::serial(SerialType type) const
{
    int val=-1;
switch(type){
case SERIAL_VERSION:
    val = (m_deviceParameter.SerialNumber>>28)&0x0F;
    break;
case SERIAL_GROUP:
    val = (m_deviceParameter.SerialNumber>>24)&0x0F;
    break;
case SERIAL_DEVICE:
    val = (m_deviceParameter.SerialNumber>>16)&0xFF;
    break;
case SERIAL_ID:
    val = m_deviceParameter.SerialNumber&0xFFFF;
    break;
case SERIAL_WINDOW:
    val = (m_deviceParameter.SerialNumber>>16)&0xFFF;   //12 bit of GROUP|DEVICE
    break;
}
return val;
}

QString EDeviceInfo::objectName()
{
    QString _name = "";
    switch(this->serial(EDeviceInfo::SERIAL_GROUP)){
        case EDeviceInfo::GroupType::GROUP_SOFTWARE:
            _name = "SOF"+this->serialHex();
            break;
        case EDeviceInfo::GroupType::GROUP_SENSOR:
            _name = "SEN"+this->serialHex();
            break;
        case EDeviceInfo::GroupType::GROUP_MODULE:
            _name = "MOD"+this->serialHex();
            break;
        case EDeviceInfo::GroupType::GROUP_SYSTEM:
            _name = "SYS"+this->serialHex();
            break;
    case EDeviceInfo::GroupType::GROUP_TOOL:
            _name = "TLS"+this->serialHex();
        break;
    }
return _name;
}

bool EDeviceInfo::openFile()
{
    return this->openDeviceInfo();
}

bool EDeviceInfo::saveFile()
{
 return this->saveDeviceInfo();
}

void EDeviceInfo::updateJsonObject()
{
    //Parameter
    m_jsonObject.insert("Address",m_deviceParameter.Address);
    m_jsonObject.insert("AddressDefault",m_deviceParameter.AddressDefault);
    m_jsonObject.insert("SerialNumber",m_deviceParameter.SerialNumber);
    m_jsonObject.insert("SampleTime",m_deviceParameter.SampleTime);
    m_jsonObject.insert("TypeConnect",m_deviceParameter.TypeConnect);

    m_jsonObject.insert("Priority",m_deviceParameter.Priority);
    m_jsonObject.insert("Retries",m_deviceParameter.Retries);
    m_jsonObject.insert("TimeOut",m_deviceParameter.TimeOut);
    m_jsonObject.insert("RegStart",m_deviceParameter.RegStart);
    m_jsonObject.insert("RegNumber",m_deviceParameter.RegNumber);

    m_jsonObject.insert("RangeMin",m_deviceParameter.RangeMin);
    m_jsonObject.insert("RangeMax",m_deviceParameter.RangeMax);
    //Tool
    m_jsonObject.insert("ToolDisplay",getQJsonArray(m_deviceParameter.ToolDisplay));
    m_jsonObject.insert("ToolPractice",getQJsonArray(m_deviceParameter.ToolPractice));
    m_jsonObject.insert("ToolControl",getQJsonArray(m_deviceParameter.ToolControl));
    //Info
    m_jsonObject.insert("Account",m_deviceInfo.Account);
    m_jsonObject.insert("Name",m_deviceInfo.Name);
    m_jsonObject.insert("Description",m_deviceInfo.Description);
    m_jsonObject.insert("Icon",m_deviceInfo.Icon);
    m_jsonObject.insert("IconOn",m_deviceInfo.IconOn);

    //Calib
    m_jsonObject.insert("CalibTime",m_calibParameter.calibTime);
    m_jsonObject.insert("CalibSampleTime",m_calibParameter.sampleTime);
    m_jsonObject.insert("CalibSampleNumber",m_calibParameter.sampleNumber);
    m_jsonObject.insert("CalibAccuracyType",m_calibParameter.accuracyType);
    m_jsonObject.insert("CalibAccuracyValue",m_calibParameter.accuracyValue);
    m_jsonObject.insert("CalibRangeMin",m_calibParameter.RangeMin);
    m_jsonObject.insert("CalibRangeMax",m_calibParameter.RangeMax);
    m_jsonObject.insert("CalibMethodType",m_calibParameter.methodType);
    m_jsonObject.insert("CalibStandardValue01",m_calibParameter.standardValue01);
    m_jsonObject.insert("CalibStandardValue02",m_calibParameter.standardValue02);
    m_jsonObject.insert("CalibStandardValue03",m_calibParameter.standardValue03);
    m_jsonObject.insert("CalibEvaluateType",m_calibParameter.evaluateType);

}

void EDeviceInfo::setJsonObject(QJsonObject json)
{
    //Parameter
    m_deviceParameter.Address = this->getJsonValue(json.value("Address"),QJsonValue(1)).toInt();
    m_deviceParameter.AddressDefault = this->getJsonValue(json.value("AddressDefault"),QJsonValue(127)).toInt();
    m_deviceParameter.SerialNumber = this->getJsonValue(json.value("SerialNumber"),QJsonValue(0)).toInt();
    m_deviceParameter.SampleTime = this->getJsonValue(json.value("SampleTime"),QJsonValue(1000)).toInt();

    m_deviceParameter.Priority = this->getJsonValue(json.value("Priority"),QJsonValue(3)).toInt();
    m_deviceParameter.Retries = this->getJsonValue(json.value("Retries"),QJsonValue(3)).toInt();
    m_deviceParameter.TimeOut = this->getJsonValue(json.value("TimeOut"),QJsonValue(100)).toInt();
    m_deviceParameter.RegStart = this->getJsonValue(json.value("RegStart"),QJsonValue(40004)).toInt();
    m_deviceParameter.RegNumber = this->getJsonValue(json.value("RegNumber"),QJsonValue(100)).toInt();

    m_deviceParameter.RangeMin = this->getJsonValue(json.value("RangeMin"),QJsonValue(0)).toDouble();
    m_deviceParameter.RangeMax = this->getJsonValue(json.value("RangeMax"),QJsonValue(100)).toDouble();

    m_deviceParameter.ToolDisplay = fromQJsonArray(this->getJsonValue(json.value("ToolDisplay"),QJsonValue("")).toArray(),0x0FF);
    m_deviceParameter.ToolPractice = fromQJsonArray(this->getJsonValue(json.value("ToolPractice"),QJsonValue("")).toArray(),0x0FF);
    m_deviceParameter.ToolControl = fromQJsonArray(this->getJsonValue(json.value("ToolControl"),QJsonValue("")).toArray(),0x0FF);


    int _type = this->getJsonValue(json.value("TypeConnect"),QJsonValue(0)).toInt();
    switch(_type){
    case 0:m_deviceParameter.TypeConnect = ModbusRTU;
        break;
    case 1:m_deviceParameter.TypeConnect = ModbusTCP;
        break;
    }

    //Info
    m_deviceInfo.Account = this->getJsonValue(json.value("Account"),QJsonValue(0)).toInt();
    m_deviceInfo.Name = this->getJsonValue(json.value("Name"),QJsonValue("")).toString();
    m_deviceInfo.Description = this->getJsonValue(json.value("Description"),QJsonValue("")).toString();
    m_deviceInfo.Icon = this->getJsonValue(json.value("Icon"),QJsonValue("")).toString();
    m_deviceInfo.IconOn = this->getJsonValue(json.value("IconOn"),QJsonValue("")).toString();

    //Calib
    m_calibParameter.calibTime = this->getJsonValue(json.value("CalibTime"),QJsonValue(10)).toInt();
    m_calibParameter.sampleTime = this->getJsonValue(json.value("CalibSampleTime"),QJsonValue(100)).toInt();
    m_calibParameter.sampleNumber = this->getJsonValue(json.value("CalibSampleNumber"),QJsonValue(10)).toInt();
    m_calibParameter.accuracyType = this->getJsonValue(json.value("CalibAccuracyType"),QJsonValue(0)).toInt();
    m_calibParameter.methodType = this->getJsonValue(json.value("CalibMethodType"),QJsonValue(0)).toInt();
    m_calibParameter.evaluateType = this->getJsonValue(json.value("CalibEvaluateType"),QJsonValue(0)).toInt();

    m_calibParameter.accuracyValue = this->getJsonValue(json.value("CalibAccuracyValue"),QJsonValue(1)).toDouble();
    m_calibParameter.RangeMin = this->getJsonValue(json.value("CalibRangeMin"),QJsonValue(0)).toDouble();
    m_calibParameter.RangeMax = this->getJsonValue(json.value("CalibRangeMax"),QJsonValue(1)).toDouble();
    m_calibParameter.standardValue01 = this->getJsonValue(json.value("CalibStandardValue01"),QJsonValue(0)).toDouble();
    m_calibParameter.standardValue02 = this->getJsonValue(json.value("CalibStandardValue02"),QJsonValue(0)).toDouble();
    m_calibParameter.standardValue03 = this->getJsonValue(json.value("CalibStandardValue03"),QJsonValue(0)).toDouble();



}

QJsonValue EDeviceInfo::getJsonValue(QJsonValue value, QJsonValue init)
{
if(value==QJsonValue::Undefined)return init;
else return value;
}

QJsonArray EDeviceInfo::getQJsonArray(QList<int> list)
{
    QJsonArray array;
    for(int i=0;i<list.count();i++){
        array.append(list.at(i));
    }
    return array;
}

QList<int> EDeviceInfo::fromQJsonArray(QJsonArray array,int valueDefault)
{
    QList<int> _list;
    for(int i=0;i<array.count();i++){
          _list.append(array.at(i).toInt(valueDefault));
    }
    return _list;
}

bool EDeviceInfo::saveDeviceInfo()
{
    QString _devName = QString("%1").arg(this->serial(), 8, 16, QLatin1Char( '0' ));
    //Show dialog file, get path of file
    QString m_fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/device/dev"+_devName,QObject::tr("STEMe files (*.dev)"));
    if(m_fileName.isEmpty())return false;
    //Open file
    if(!m_fileName.contains(".dev",Qt::CaseSensitive))m_fileName += ".dev";
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Save jsonDocument to file
    QJsonDocument *doc = new QJsonDocument(this->getJsonDevice());
    fileDev.write(doc->toJson());
    fileDev.close();
    return true;
}

bool EDeviceInfo::openDeviceInfo()
{
    //Show dialog file, get path of file
    QString m_fileName = QFileDialog::getOpenFileName(nullptr,QObject::tr("Open File"),QCoreApplication::applicationDirPath()+"/device",QObject::tr("STEMe files (*.dev)"));
    if(m_fileName.isEmpty())return false;

    //Open file
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }
    //get jsonDocument from file
    QJsonParseError jsonParseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileDev.readAll(),&jsonParseError);
    fileDev.close();
    if(jsonParseError.error != QJsonParseError::NoError)return false;
    //get All device from JsonDocument
    this->setJsonDevice(jsonDoc.object());
    return true;
}


