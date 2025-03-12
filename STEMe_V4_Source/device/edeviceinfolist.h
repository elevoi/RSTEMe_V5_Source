#ifndef EDEVICEINFOLIST_H
#define EDEVICEINFOLIST_H
#include <QList>
#include <QFile>
#include <QSettings>
#include "device/edeviceinfo.h"
#include "root/eaccountlist.h"

#include <QJsonArray>
#include <etypedef.h>

class EDeviceInfoList
{
public:
    EDeviceInfoList();

/*properties----------------------------------------------*/
    int size() const {return m_listDeviceInfo.size();}

    //get device
    inline QList<EDeviceInfo> deviceList()const {return m_listDeviceInfo;}
    QList<EDeviceInfo> groupList(int i);
    QList<EDeviceInfo> groupList(int i,QList<EDeviceInfo> list);
    inline QList<ETypeDef::TypeDevice> groups() const {return m_etypeDef.listGroupDevice();}
    ETypeDef::TypeDevice group(EDeviceInfo dev);
    int group(int id);
    inline QList<ETypeDef::TypeDevice> sensors() const {return m_etypeDef.listTypeSensor();}
    inline QList<ETypeDef::TypeDevice> modules() const {return m_etypeDef.listTypeModule();}
    inline QList<ETypeDef::TypeDevice> systems() const {return m_etypeDef.listTypeSystem();}
    inline QList<ETypeDef::TypeDevice> software() const {return m_etypeDef.listTypeSoftware();}
    inline QList<ETypeDef::TypeDevice> tools() const {return m_etypeDef.listTypeSoftware();}
    ETypeDef::TypeDevice type(EDeviceInfo dev);
    QList<ETypeDef::TypeDevice> type(int group);
    int type(int id,QList<ETypeDef::TypeDevice> list);
    QList<EDeviceInfo> typeDevice(int group);


    EDeviceInfo getDevice(int serial,bool *ok);
    bool checkDevice(EDeviceInfo dev);
    EDeviceInfo getDevice(int i);


    bool insertDevice(EDeviceInfo dev);
    bool replaceDevice(EDeviceInfo dev);
    bool removeDevice(EDeviceInfo dev);
    int findDevice(EDeviceInfo dev);

    QList<EDeviceInfo> deviceList(EAccountInfo acc);
    //save jsonDocument to textFile
    static int getAddressInc();
    static int getAddressOnlineInc();
    static int getAddressOnlineInc(EDeviceInfo *dev, EDeviceInfoList *list);
    bool load(bool add);
    bool save();
    void clear();


    //file
    bool saveFile();
    bool openFile();

private:
    EDeviceInfo m_deviceInfo;
    QList<EDeviceInfo> m_listDeviceInfo;

    ETypeDef m_etypeDef;
    static int m_address;
    static int m_addressOnline;




QFile m_fileName;

bool saveDocument();
bool loadDocument(bool add);
static bool deviceSort(EDeviceInfo &v1,EDeviceInfo &v2);

//file
bool saveListDevice();
bool openListDevice();
};

#endif // EDEVICEINFOLIST_H
