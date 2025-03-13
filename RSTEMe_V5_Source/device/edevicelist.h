#ifndef EDEVICELIST_H
#define EDEVICELIST_H

#include <QList>
#include <QFile>
#include <QSettings>
//#include "device/edeviceinfo.h"
#include <QJsonArray>
#include "device/edevice.h"

class EDeviceList
{
public:
    EDeviceList();


    static QList<EDevice*> deviceOnlineList(){return m_listEDeviceOnline;}
    static void setDeviceOnlineList(QList<EDevice*> ldev){m_listEDeviceOnline = ldev;}
    static bool removeDeviceOnlineList(EDevice *dev);
    static void appendDeviceOnlineList(EDevice *dev);

private:
    static QList<EDevice*> m_listEDeviceOnline;


};

#endif // EDEVICELIST_H
