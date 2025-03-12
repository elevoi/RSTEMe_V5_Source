#include "eaccountinfo.h"

EAccountInfo::EAccountInfo()
{
}

void EAccountInfo::updateType(AccountType var)
{
m_accountData.type = var;
if(var != EAccountInfo::ACC_ROOT)this->setDevices({0x10080000});
else {
    AccountData _ad;
    this->setDevices(_ad.devices);
}
}

QString EAccountInfo::typeText()
{
switch(m_accountData.type){
    case EAccountInfo::ACC_STUDENT:return "Học sinh";
    case EAccountInfo::ACC_TEACHER:return "Giáo viên";
    case EAccountInfo::ACC_ROOT:return "Quản trị";
    }
return "";
}

QJsonObject EAccountInfo::getJsonAccount()
{
this->updateJsonObject();
    return m_jsonObject;
}

void EAccountInfo::setJsonAccount(QJsonObject jsonObject)
{
    this->setJsonObject(jsonObject);
}



///////////////////////////////////////////////////////////////////////////////////////////////private functions
void EAccountInfo::updateJsonObject()
{
    //Parameter
    m_jsonObject.insert("Account",m_accountData.account);
    m_jsonObject.insert("Password",m_accountData.password);
    m_jsonObject.insert("Type",m_accountData.type);

    m_jsonObject.insert("Devices",getQJsonArray(m_accountData.devices));
}

void EAccountInfo::setJsonObject(QJsonObject json)
{
    //Parameter
    m_accountData.account = this->getJsonValue(json.value("Account"),QJsonValue("")).toString();
    m_accountData.password = this->getJsonValue(json.value("Password"),QJsonValue("")).toString();
    m_accountData.type = (EAccountInfo::AccountType)this->getJsonValue(json.value("Type"),QJsonValue(0)).toInt();

    m_accountData.devices = fromQJsonArray(this->getJsonValue(json.value("Devices"),QJsonValue("")).toArray(),0x0FF);
    if(m_accountData.devices.isEmpty())m_accountData.devices.append(0x100F0000);
}

QJsonValue EAccountInfo::getJsonValue(QJsonValue value, QJsonValue init)
{
if(value==QJsonValue::Undefined)return init;
else return value;
}

QJsonArray EAccountInfo::getQJsonArray(QList<int> list)
{
    QJsonArray array;
    for(int i=0;i<list.count();i++){
        array.append(list.at(i));
    }
    return array;
}
QList<int> EAccountInfo::fromQJsonArray(QJsonArray array,int valueDefault)
{
    QList<int> _list;
    for(int i=0;i<array.count();i++){
          _list.append(array.at(i).toInt(valueDefault));
    }
    return _list;
}
