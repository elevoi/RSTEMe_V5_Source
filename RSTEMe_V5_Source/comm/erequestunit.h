#ifndef EREQUESTUNIT_H
#define EREQUESTUNIT_H

#include <QVariant>
#include <QModbusDataUnit>
#include <QModbusDevice>

class ERequestUnit
{
public:
    ERequestUnit();

    enum RequestType{
        Read,
        Write
    };

    struct RequestUnit{
        int     id=0;
        int     slaveAddress = 127;
        QString comPort = "COM1";
        int     baudRate = 115200;
        int     priority=3;
        int     retries = 1;
        int     timeout = 50;
        int     timeRequest = 0;
        QModbusDevice::Error error = QModbusDevice::NoError;
        QString errorString = "";
        RequestType type = RequestType::Read;
        QModbusDataUnit data;
    };
//QModbusDevice::NoError
//propeties

    inline int id() const {return m_requestUnit.id;}
    inline void setId(int var){m_requestUnit.id = var;}

    inline int slaveAddress() const {return m_requestUnit.slaveAddress;}
    inline void setSlaveAddress(int var){m_requestUnit.slaveAddress = var;}

    inline QString comPort() const {return m_requestUnit.comPort;}
    inline void setComport(QString var){m_requestUnit.comPort = var;}

    inline int baudRate() const {return m_requestUnit.baudRate;}
    inline void setBaudRate(int var){m_requestUnit.baudRate = var;}

    inline int priority() const {return m_requestUnit.priority;}
    inline void setPriority(int var){m_requestUnit.priority = var;}

    inline int retries() const {return m_requestUnit.retries;}
    inline void setRetries(int var){m_requestUnit.retries = var;}

    inline int timeout() const {return m_requestUnit.timeout;}
    inline void setTimeout(int var){m_requestUnit.timeout = var;}

    inline int timeRequest() const {return m_requestUnit.timeRequest;}
    inline void setTimeRequest(int var){m_requestUnit.timeRequest = var;}

    inline QModbusDevice::Error error() const {return m_requestUnit.error;}
    inline void setError(QModbusDevice::Error var){m_requestUnit.error = var;}

    inline QString errorString() const {return m_requestUnit.errorString;}
    inline void setErrorString(QString var){m_requestUnit.errorString = var;}

    inline RequestType type() const {return m_requestUnit.type;}
    inline void setType(RequestType var){m_requestUnit.type = var;}

    inline QModbusDataUnit data() const {return m_requestUnit.data;}
    inline void setData(QModbusDataUnit var){m_requestUnit.data = var;}


    static int requestID();
    static ERequestUnit getRequestRead();
    static ERequestUnit getRequestWrite();
private:
    RequestUnit m_requestUnit;

    static int m_requestID;
};

#endif // EREQUESTUNIT_H
