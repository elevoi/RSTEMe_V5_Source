#ifndef EACCOUNTINFO_H
#define EACCOUNTINFO_H
#include <QVariant>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>

class EAccountInfo
{
public:
    EAccountInfo();

    enum AccountType{
        ACC_STUDENT,
        ACC_TEACHER,
        ACC_ROOT
    };

    struct AccountData{
        QString account = "student";
        QString password = "";
        AccountType type = ACC_STUDENT;
        QList<int> devices = {0x10010000,0x10080000};
    };

    bool operator==(const EAccountInfo &info){return m_accountData.account == info.account();}
    bool operator!=(const EAccountInfo &info){return m_accountData.account != info.account();}


    inline void setAccountData(AccountData var){m_accountData = var;}
    inline AccountData accountData() const {return m_accountData;}

    inline void setAccount(QString var){m_accountData.account = var;}
    inline QString account() const {return m_accountData.account;}

    inline void setPassword(QString var){m_accountData.password = var;}
    inline QString password() const {return m_accountData.password;}

    void updateType(AccountType var);
    inline void setType(AccountType var){m_accountData.type = var;}
    inline AccountType type() const {return m_accountData.type;}
    QString typeText();

    inline void setDevices(QList<int> var){m_accountData.devices = var;}
    inline QList<int> devices() const {return m_accountData.devices;}

    //JsonObject
    QJsonObject getJsonAccount();
    void setJsonAccount(QJsonObject jsonObject);

private:
    AccountData m_accountData;

    QJsonObject m_jsonObject;
    //JsonObject
    void updateJsonObject();
    void setJsonObject(QJsonObject json);
    QJsonValue getJsonValue(QJsonValue value,QJsonValue init);
    QJsonArray getQJsonArray(QList<int> list);
    QList<int> fromQJsonArray(QJsonArray array,int valueDefault);
};

#endif // EACCOUNTINFO_H
