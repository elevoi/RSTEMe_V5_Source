#ifndef EMANAGEDEVICE_H
#define EMANAGEDEVICE_H

#include <QObject>
#include <QTimer>
#include <comm/econnectioninfo.h>
#include "comm/econnection.h"
#include "device/edevicelist.h"
//manage
#include "manage/emanagemodule.h"
#include "manage/emanagesensor.h"
#include "manage/emanagesoftware.h"
#include "manage/emanagesystem.h"
#include "manage/emanagetool.h"

#include "etypedef.h"



class EManageDevice : public QObject
{
    Q_OBJECT
public:
    explicit EManageDevice(QObject *parent = nullptr);
    ~EManageDevice();

    void connectModbusRTU();
    bool isConnectModbusRTU();

    //select device
    void selectDeviceInfo(EDeviceInfo dev);
    void selectDevice(EDeviceInfo dev,EDevice *edev);
    void removeDevice(EDevice *dev);
    void removeDeviceAll();

    void close();
signals:
    void stateChange(ETypeDef::StateChange state);
    void connectChanged(bool status,EDeviceInfo dev);
    void error(EDevice::Error error,EDevice *dev);

private slots:
    void on_connectChanged(bool status);
    void on_stateChange(ETypeDef::StateChange state);
    void on_replySelectDeviceInfo(EDeviceInfo dev);
    void on_replySelectDevice(EDeviceInfo dev,EDevice *edev);
    void on_error(EDevice::Error error,EDevice *dev);

private:
    //Form manage
    EManageSoftware *m_emanageSoftware = nullptr;
    EManageSensor *m_emanageSensor = nullptr;
    EManageModule *m_emanageModule = nullptr;
    EManageSystem *m_emanageSystem  = nullptr;
    EManageTool *m_emanageTool  = nullptr;
    //Form Type of Software...............................................

    FrmDeviceTable *m_frmDeviceTable = nullptr;

    //Connection........................
    EConnectionInfo m_econnectionInfo;
    EConnection *m_econnection = nullptr;
    EDevice *m_edevice= nullptr;
    EDeviceInfoList m_edeviceInfoList;
    EDeviceList m_edeviceList;

    void connectModbus(EConnection::SerialPort para);

    EDevice* getListDevice(EDeviceInfo dev);

    void selectDeviceTable(EDeviceInfo devInfo);
};

#endif // EMANAGEDEVICE_H
