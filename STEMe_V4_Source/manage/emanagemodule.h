#ifndef EMANAGEMODULE_H
#define EMANAGEMODULE_H

#include <QObject>
#include <device/edevice.h>
#include <device/edeviceinfo.h>

class EManageModule : public QObject
{
    Q_OBJECT
public:
    explicit EManageModule(QObject *parent = nullptr);
    //select device
    void setSelectDevice(EDeviceInfo dev);
    void setSelectDevice(EDevice *dev);
    void setDevice(EDevice *dev);

signals:
    void replyDevices(EDeviceInfo dev,EDevice *edev);
private slots:
    void on_selectDevice(EDeviceInfo dev);
private:
    EDevice *m_device= nullptr;
};

#endif // EMANAGEMODULE_H
