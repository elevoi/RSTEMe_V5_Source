#include "eaccountlist.h"



EAccountInfo EAccountList::m_currentAccount;
EAccountList::EAccountList()
{
this->loadAccountList();
}


void EAccountList::save()
{
    this->saveAccountList();
}

void EAccountList::load()
{
    this->loadAccountList();
}

void EAccountList::clear()
{
    this->clearAccountList();
}

void EAccountList::reset()
{
    this->clearAccountList();
    this->clearRecent();
    EAccountInfo acc;

    acc.setAccount("student");
    acc.setPassword("");
    acc.updateType(EAccountInfo::ACC_STUDENT);
    this->insertAccount(acc);
    this->updateRecent(acc);

    acc.setAccount("teacher");
    acc.setPassword("12345678");
    acc.updateType(EAccountInfo::ACC_TEACHER);
    this->insertAccount(acc);
    this->updateRecent(acc);

    acc.setAccount("steme");
    acc.setPassword("12345678");
    acc.updateType(EAccountInfo::ACC_ROOT);
    this->insertAccount(acc);
    this->updateRecent(acc);

    acc.setAccount("root");
    acc.setPassword("1q2w3e4r5t6y7u8i9o0p");
    acc.updateType(EAccountInfo::ACC_ROOT);
    this->insertAccount(acc);
    this->updateRecent(acc);
}

bool EAccountList::isEmpty()
{
    this->loadAccountList();
    return m_listAccountInfo.isEmpty();
}


void EAccountList::insertAccount(EAccountInfo acc)
{
    int i = this->findAccount(acc);
    if(i<0) m_listAccountInfo.append(acc);
        else m_listAccountInfo.replace(i,acc);
    this->saveAccountList();
}

bool EAccountList::replaceAccount(EAccountInfo acc)
{
int i = this->findAccount(acc);
if(i>=0){
    m_listAccountInfo.replace(i,acc);
    this->saveAccountList();
    return true;
}
return false;
}

bool EAccountList::removeAccount(EAccountInfo acc)
{
    int i = this->findAccount(acc);
    if(i<0)return false;
    m_listAccountInfo.removeAt(i);
    this->saveAccountList();
    return true;
}

int EAccountList::findAccount(EAccountInfo acc)
{
    this->loadAccountList();
    for(int i=0;i<m_listAccountInfo.count();i++){
        if(acc.account() == m_listAccountInfo.value(i).account())return i;
    }
    return -1;
}

bool EAccountList::checkAccount(EAccountInfo acc)
{
int i = this->findAccount(acc);
if(i<0)return false;
EAccountInfo var = m_listAccountInfo.at(i);
//check acc
if(var.account()!=acc.account())return false;
//check pass
if(var.password()!=acc.password())return false;
return true;
}

void EAccountList::updateRecent(EAccountInfo acc)
{
    this->loadRecent();
    foreach (auto var, m_listAccountRecent) {
        if(var.account()==acc.account())return;
    }
    if(m_listAccountRecent.count()>=5){
        m_listAccountRecent.removeFirst();
    }
    m_listAccountRecent.append(acc);
    this->saveRecent();
}

void EAccountList::removeRecent(EAccountInfo acc)
{
    this->loadRecent();
    foreach (auto var, m_listAccountRecent) {
        if(acc==var)m_listAccountRecent.removeOne(var);
    }
    this->saveRecent();
}

void EAccountList::clearRecent()
{
    QSettings settings("ELEVOI","STEME");
    settings.beginWriteArray("EAccountRecentList");
    settings.remove("");
    settings.endArray();
}

QList<EAccountInfo> EAccountList::getRecent()
{
    this->loadRecent();
    return m_listAccountRecent;
}

bool EAccountList::checkAccount(EAccountInfo *acc)
{
int i = this->findAccount(*acc);
if(i<0)return false;
EAccountInfo var = m_listAccountInfo.at(i);
//check acc
if(var.account()!=acc->account())return false;
//check pass
if(var.password()!=acc->password())return false;
*acc = var;
return true;
}

void EAccountList::saveDocument(QList<EAccountInfo> list,QString name)
{
    QJsonArray jsDevice;
    QJsonDocument jsDoc;
    EAccountInfo acc;

    foreach (EAccountInfo var,list) {
        jsDevice.append(var.getJsonAccount());
        }
//return false;
    QSettings settings("ELEVOI","STEME");
    settings.beginWriteArray(name);
    settings.remove("");
    jsDoc.setArray(jsDevice);
    settings.setArrayIndex(0);
    settings.setValue("Account",jsDoc.toJson());
    settings.endArray();
}

QList<EAccountInfo> EAccountList::loadDocument(QString name)
{
    QList<EAccountInfo> list;
    QSettings settings("ELEVOI","STEME");
    QJsonArray jsDevice;
    QJsonDocument jsDoc;

    //get data from setting file.
    settings.beginWriteArray(name);
    settings.setArrayIndex(0);
    QString _device = settings.value("Account","").toString();
    settings.endArray();
    jsDoc = QJsonDocument::fromJson(_device.toUtf8());
    jsDevice = jsDoc.array();
    //encoder data
    //get devices
    foreach (auto var, jsDevice) {
        EAccountInfo acc;
        acc.setJsonAccount(var.toObject());
        list.append(acc);
    }
    return list;
}

void EAccountList::saveAccountList()
{
    this->saveDocument(m_listAccountInfo,"EAccountInfoList");
}

void EAccountList::loadAccountList()
{
    m_listAccountInfo = this->loadDocument("EAccountInfoList");
}

void EAccountList::clearAccountList()
{
    QSettings settings("ELEVOI","STEME");
    settings.beginWriteArray("EAccountInfoList");
    settings.remove("");
    settings.endArray();
}

void EAccountList::loadRecent()
{
    m_listAccountRecent = this->loadDocument("EAccountRecentList");
}

void EAccountList::saveRecent()
{
    this->saveDocument(m_listAccountRecent,"EAccountRecentList");
}
