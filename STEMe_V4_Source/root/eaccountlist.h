#ifndef EACCOUNTLIST_H
#define EACCOUNTLIST_H
#include <QVariant>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>
#include <root/eaccountinfo.h>

class EAccountList
{
public:
    EAccountList();
    //Properties
    inline static EAccountInfo currentAccount(){return m_currentAccount;}
    inline static void setCurrentAccount(EAccountInfo var){m_currentAccount = var;}

    inline QList<EAccountInfo> accounts() const {return m_listAccountInfo;}

    //Functions
    void load();
    void save();
    void clear();
    void reset();
    bool isEmpty();
    void insertAccount(EAccountInfo acc);
    bool replaceAccount(EAccountInfo acc);
    bool removeAccount(EAccountInfo acc);
    int findAccount(EAccountInfo acc);
    bool checkAccount(EAccountInfo *acc);
    bool checkAccount(EAccountInfo acc);

    void updateRecent(EAccountInfo acc);
    void removeRecent(EAccountInfo acc);
    void clearRecent();
    QList<EAccountInfo> getRecent();

private:
    static EAccountInfo m_currentAccount;
    QList<EAccountInfo> m_listAccountInfo;
    QList<EAccountInfo> m_listAccountRecent;

    //JsonArray
    void saveDocument(QList<EAccountInfo> list,QString name);
    QList<EAccountInfo> loadDocument(QString name);
    void saveAccountList();
    void loadAccountList();
    void clearAccountList();

    void loadRecent();
    void saveRecent();
};

#endif // EACCOUNTLIST_H
