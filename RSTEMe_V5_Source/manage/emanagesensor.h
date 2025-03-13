#ifndef EMANAGESENSOR_H
#define EMANAGESENSOR_H

#include <QObject>
#include <device/edevice.h>
#include <device/edeviceinfo.h>
#include "device/frmdeviceselection.h"

class EManageSensor : public QObject
{
    Q_OBJECT
public:
    explicit EManageSensor(QObject *parent = nullptr);
    ~EManageSensor();
    //select device
    void selectDevice(EDevice *dev);
signals:
    void replySelectDevice(EDeviceInfo dev,EDevice *edev);

private slots:
    void on_replySelectDeviceInfo(EDeviceInfo dev);
    void on_finished();
private:
    EDevice *m_device= nullptr;

    FrmDeviceSelection *m_frmDeviceSelection = nullptr;
    void close();
};

#endif // EMANAGESENSOR_H
