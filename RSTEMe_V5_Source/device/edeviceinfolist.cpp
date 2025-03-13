#include "edeviceinfolist.h"
#include <QFile>
#include <QFileDialog>
#include <QCoreApplication>
#include <QMessageBox>
#include <QDebug>

int EDeviceInfoList::m_address = 128;
int EDeviceInfoList::m_addressOnline = 1;

EDeviceInfoList::EDeviceInfoList()
{
    this->load(false);
}

QList<EDeviceInfo> EDeviceInfoList::groupList(int i)
{
QList<EDeviceInfo> _list;
foreach (EDeviceInfo var, m_listDeviceInfo) {
    if(var.serial(EDeviceInfo::SERIAL_GROUP)==i)_list.append(var);
}
std::sort(_list.begin(),_list.end(),this->deviceSort);
return _list;
}

QList<EDeviceInfo> EDeviceInfoList::groupList(int i, QList<EDeviceInfo> list)
{
    QList<EDeviceInfo> _list;
    foreach (EDeviceInfo var, list) {
        if(var.serial(EDeviceInfo::SERIAL_GROUP)==i)_list.append(var);
    }
    std::sort(_list.begin(),_list.end(),this->deviceSort);
    return _list;
}

ETypeDef::TypeDevice EDeviceInfoList::group(EDeviceInfo dev)
{
    ETypeDef::TypeDevice _type {0,"Không biết"};
    foreach (auto var, m_etypeDef.listGroupDevice()) {
        if(dev.serial(EDeviceInfo::SERIAL_GROUP)==var.id){
            _type = var;
            break;
        }
    }
    return _type;
}

int EDeviceInfoList::group(int id)
{
    for(int i=0;i< m_etypeDef.listGroupDevice().count();i++){
        if(id==m_etypeDef.listGroupDevice().at(i).id)return i;
    }
return 0;
}

ETypeDef::TypeDevice EDeviceInfoList::type(EDeviceInfo dev)
{
    ETypeDef::TypeDevice _type {0,"Không biết"};
    QList<ETypeDef::TypeDevice> _list = this->type(this->group(dev).id);
    foreach (auto var, _list) {
        if(dev.serial(EDeviceInfo::SERIAL_DEVICE)==var.id){
            _type = var;
            break;
        }
    }
    return _type;
}

QList<ETypeDef::TypeDevice> EDeviceInfoList::type(int group)
{
    QList<ETypeDef::TypeDevice> _list;
    switch(group){
    case 0:
        _list = m_etypeDef.listTypeSoftware();
        break;
    case 1:
        _list = m_etypeDef.listTypeSensor();
        break;
    case 2:
        _list = m_etypeDef.listTypeModule();
        break;
    case 3:
        _list = m_etypeDef.listTypeSystem();
        break;
    case 4:
        _list = m_etypeDef.listTypeTool();
        break;
    }
    return _list;
}

int EDeviceInfoList::type(int id,QList<ETypeDef::TypeDevice> list)
{
    for(int i=0;i< list.count();i++){
        if(id==list.at(i).id)return i;
    }
return 0;
}

QList<EDeviceInfo> EDeviceInfoList::typeDevice(int group)
{
    QList<EDeviceInfo> _list;
    foreach (EDeviceInfo var, m_listDeviceInfo) {
        if(var.serial(EDeviceInfo::SERIAL_GROUP)==group)_list.append(var);
    }
    return _list;
}


EDeviceInfo EDeviceInfoList::getDevice(int serial, bool *ok)
{
    EDeviceInfo var;
    foreach (auto var, m_listDeviceInfo) {
        if(serial == var.serial()){
            *ok=true;
            return var;
        }
    }
    *ok=false;
    return var;
}

bool EDeviceInfoList::checkDevice(EDeviceInfo dev)
{
if(dev.serial(EDeviceInfo::SERIAL_GROUP)>=this->groups().count())return false;
switch(dev.serial(EDeviceInfo::SERIAL_GROUP)){
    case EDeviceInfo::GROUP_SOFTWARE:if(dev.serial(EDeviceInfo::SERIAL_DEVICE)>=this->software().count())return false;
        break;
    case EDeviceInfo::GROUP_SENSOR:if(dev.serial(EDeviceInfo::SERIAL_DEVICE)>=this->sensors().count())return false;
        break;
    case EDeviceInfo::GROUP_MODULE:if(dev.serial(EDeviceInfo::SERIAL_DEVICE)>=this->modules().count())return false;
        break;
    case EDeviceInfo::GROUP_SYSTEM:if(dev.serial(EDeviceInfo::SERIAL_DEVICE)>=this->systems().count())return false;
        break;
}
return true;
}



EDeviceInfo EDeviceInfoList::getDevice(int i)
{
 EDeviceInfo _dev;
 if(i<m_listDeviceInfo.count()){
     return m_listDeviceInfo.at(i);
 }
 return _dev;
}

bool EDeviceInfoList::insertDevice(EDeviceInfo dev)
{
    int i = this->findDevice(dev);
    if(i<0){
        dev.setAddress(this->getAddressInc());
        m_listDeviceInfo.append(dev);
    }
    else {
        dev.setAddress(i);
        m_listDeviceInfo.replace(i,dev);
    }
    if(!this->save())return false;
    return this->load(false);
}

bool EDeviceInfoList::replaceDevice(EDeviceInfo dev)
{
int i = this->findDevice(dev);
if(i>=0)m_listDeviceInfo.replace(i,dev);
if(!this->save())return false;
return this->load(false);
}

bool EDeviceInfoList::removeDevice(EDeviceInfo dev)
{
    int i = this->findDevice(dev);
    if(i<0)return false;
    m_listDeviceInfo.removeAt(i);
    if(!this->save())return false;
    return this->load(false);
}

int EDeviceInfoList::findDevice(EDeviceInfo dev)
{
    for(int i=0;i<m_listDeviceInfo.count();i++){
        if(dev.serial() == m_listDeviceInfo.value(i).serial())return i;
    }
    return -1;
}

QList<EDeviceInfo> EDeviceInfoList::deviceList(EAccountInfo acc)
{
    QList<EDeviceInfo> _list;
    this->load(false);
    foreach (auto var, acc.devices()) {
        bool ok=false;
        auto _dev = this->getDevice(var,&ok);
        if(ok)_list.append(_dev);
    }
    if(acc.account()=="root")_list = m_listDeviceInfo;
    return _list;
}

int EDeviceInfoList::getAddressInc()
{
    if(m_address<128)m_address=128;
    return m_address++;
}

int EDeviceInfoList::getAddressOnlineInc()
{
    if(m_addressOnline<1)m_addressOnline=1;
    return m_addressOnline++;
}

int EDeviceInfoList::getAddressOnlineInc(EDeviceInfo *dev, EDeviceInfoList *list)
{
    //load data new
    list->load(false);
    foreach (auto var, list->deviceList()){
        if(*dev == var)*dev = var;
    }
    if(dev->address()>=127){
        int add = EDeviceInfoList::getAddressOnlineInc();
        for (int i=0;i<list->deviceList().count();i++) {
            if(add == list->deviceList().at(i).address()){
                add = EDeviceInfoList::getAddressOnlineInc();
                i=-1;
                }
        }
        dev->setAddress(add);
        list->replaceDevice(*dev);
        }
    return dev->address();
}



bool EDeviceInfoList::save()
{
    return this->saveDocument();
}

bool EDeviceInfoList::load(bool add)
{
return this->loadDocument(add);
}

void EDeviceInfoList::clear()
{
    QSettings settings("ELEVOI","STEME");
    settings.beginWriteArray("EDeviceInfoList");
    settings.remove("");
    settings.endArray();
}

bool EDeviceInfoList::saveFile()
{
    return this->saveListDevice();
}

bool EDeviceInfoList::openFile()
{
    return this->openListDevice();
}

bool EDeviceInfoList::saveDocument()
{
    /*
     EDeviceInfoList {
         Array[0]:"Group",jsGroup
         Array[1]:"Device",JsDevice
    }
     */
    QJsonArray jsDevice;
    QJsonDocument jsDoc;
    EDeviceInfo dev;

    foreach (EDeviceInfo var,m_listDeviceInfo) {
        jsDevice.append(var.getJsonDevice());
        }
//return false;
    QSettings settings("ELEVOI","STEME");
    settings.beginWriteArray("EDeviceInfoList");
    settings.remove("");
    jsDoc.setArray(jsDevice);
    settings.setArrayIndex(0);
    settings.setValue("Device",jsDoc.toJson());
    settings.endArray();
    return true;
}
bool variantLessThan(const QVariant &v1, const QVariant &v2)
 {
     return v1.toString() < v2.toString();
 }

 bool EDeviceInfoList::deviceSort(EDeviceInfo &v1, EDeviceInfo &v2)
 {
     return (v1.serial(EDeviceInfo::SERIAL_DEVICE)<v2.serial(EDeviceInfo::SERIAL_DEVICE));
 }

 bool EDeviceInfoList::saveListDevice()
 {
     QString _devName = "devices";
     //Show dialog file, get path of file
     QString m_fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/device/"+_devName,QObject::tr("STEMe files (*.ldev)"));
     if(m_fileName.isEmpty())return false;
     //Open file
     if(!m_fileName.contains(".ldev",Qt::CaseSensitive))m_fileName += ".ldev";
     QFile fileDev(m_fileName);
     if(!fileDev.open(QIODevice::WriteOnly)){
         QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
         return false;
     }

     //Save jsonDocument to file
     QJsonArray jsDevice;
     foreach (EDeviceInfo var,m_listDeviceInfo) {
         jsDevice.append(var.getJsonDevice());
         }
     QJsonDocument *doc = new QJsonDocument(jsDevice);
     fileDev.write(doc->toJson());
     fileDev.close();
     return true;
 }

 bool EDeviceInfoList::openListDevice()
 {
     //Show dialog file, get path of file
     QString m_fileName = QFileDialog::getOpenFileName(nullptr,QObject::tr("Open File"),QCoreApplication::applicationDirPath()+"/device",QObject::tr("STEMe files (*.ldev)"));
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
     QJsonArray jsDevice = jsonDoc.array();
     if(jsDevice.isEmpty())return false;
     m_listDeviceInfo.clear();
     for(int i=0;i<jsDevice.count();i++){
         EDeviceInfo var;
         var.setJsonDevice(jsDevice.at(i).toObject());
         m_listDeviceInfo.append(var);
         }
     std::sort(m_listDeviceInfo.begin(),m_listDeviceInfo.end(),this->deviceSort);
     return true;
 }
bool EDeviceInfoList::loadDocument(bool add)
{
    QSettings settings("ELEVOI","STEME");
    QJsonArray jsDevice;
    QJsonDocument jsDoc;

    //get data from setting file.
    settings.beginWriteArray("EDeviceInfoList");
    settings.setArrayIndex(0);
    QString _device = settings.value("Device","").toString();
    settings.endArray();
    jsDoc = QJsonDocument::fromJson(_device.toUtf8());
    jsDevice = jsDoc.array();
    //encoder data
    //get devices
    m_listDeviceInfo.clear();
    if(jsDevice.isEmpty()){
        //set device default
       /* EDeviceInfo var;
        var.setSerial(0x20000001);
        var.setName("Cài đặt thiết bị");
        m_listDeviceInfo.append(var);*/
        return false;
    }
    else{
        if(add)m_address = 128;
        for(int i=0;i<jsDevice.count();i++){
            EDeviceInfo var;
            var.setJsonDevice(jsDevice.at(i).toObject());
            if(var.serial(EDeviceInfo::SERIAL_GROUP)>0){
                if(add)var.setAddress(this->getAddressInc());
            }
            m_listDeviceInfo.append(var);
            }
        if(add)this->saveDocument();
        std::sort(m_listDeviceInfo.begin(),m_listDeviceInfo.end(),this->deviceSort);
    }
    return true;
}


