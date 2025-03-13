#ifndef ELOG_H
#define ELOG_H
#include <QDebug>
#include <QVariant>
#include <device/edevice.h>
#include <device/edeviceinfo.h>
#include <device/def/edeviceparameter.h>
#include <comm/econnection.h>
#include <comm/emodbus.h>

class ELog : public QObject
{
    Q_OBJECT
public:
    explicit ELog(QObject *parent = nullptr);
    enum DataTypeLog{
        DATA_REG_DEC,
        DATA_REG_HEX
    };

    static void log(const QVariant var);
    static void log(ERequestUnit unit);
    static void log(EDeviceInfo dev,ERequestUnit unit);
    static void log(EDevice::Error error);
signals:


private:
    static DataTypeLog m_dataTypeLog;

};

#endif // ELOG_H
