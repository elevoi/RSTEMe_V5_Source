#ifndef EMANAGESOFTWARE_H
#define EMANAGESOFTWARE_H

#include <QObject>
#include <device/edevice.h>
#include <device/edeviceinfo.h>
#include <comm/econnection.h>
//Form
#include <comm/frmconnectionsetup.h>
#include "device/frmdevicesetup.h"
#include "device/software/frmsetupserial.h"
#include "device/repair/frmrepairmodbusconnection.h"
#include "device/frmsearchdevice.h"
#include "device/frmaddsensor.h"
#include "device/software/frmaccountsetup.h"
#include "device/frmdevicetable.h"
//calib
#include "device/frmdevicecalibration.h"


class EManageSoftware : public QObject
{
    Q_OBJECT
public:
    explicit EManageSoftware(QObject *parent = nullptr);
    ~EManageSoftware();
    //select device
    void setSelectDevice(EDeviceInfo devInfo,EDevice *edev);

    inline void setConnection(EConnection *var){m_econnection = var;}
signals:
    void replySelectDeviceInfo(EDeviceInfo dev);
    void replySelectDevice(EDeviceInfo dev,EDevice *edev);
    void stateChange(ETypeDef::StateChange state);

private slots:
    void on_replySelectDeviceInfo(EDeviceInfo dev);
    void on_stateChange(ETypeDef::StateChange state);

private:
    EConnection *m_econnection = nullptr;
    EDeviceInfo m_edeviceInfo;

    //Form
    FrmAccountSetup *m_frmAccountSetup = nullptr;
    FrmDeviceSetup *m_frmDeviceSetup = nullptr;
    FrmSetupSerial *m_frmSetupSerial = nullptr;
    FrmSearchDevice *m_frmSearchDevice = nullptr;
    FrmConnectionSetup *m_frmConnectionSetup = nullptr;
    FrmDeviceTable *m_frmDeviceTable = nullptr;
    //set connection
    FrmRepairModbusConnection *m_frmRepairModbusConnection = nullptr;

    //Form Control
    FrmAddSensor *m_frmAddSensor = nullptr;

    //calib
    FrmDeviceCalibration *m_frmDeviceCalibration = nullptr;
    QList<FrmDeviceCalibration*> m_listDeviceCalibration ;
    FrmDeviceCalibration* getDeviceCalibration(EDevice *dev);


    void close();
};

#endif // EMANAGESOFTWARE_H
