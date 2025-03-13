#ifndef ECONNECTION_H
#define ECONNECTION_H

#include <QObject>
#include "comm/emodbus.h"
#include <QTimer>
#include <QList>
#include <QThread>
#include "device/edeviceinfolist.h"

class EConnection : public QObject
{
    Q_OBJECT
public:

    explicit EConnection(QObject *parent = nullptr);

    ~EConnection();

    /* Exported types ------------------------------------------------------------*/

    /* Exported constants --------------------------------------------------------*/
    struct SerialPort{
        QString port = "COM1";
        int baudRate = 115200;
    };

    /* Exported macro ------------------------------------------------------------*/


    /* Exported properties -------------------------------------------------------*/
    inline SerialPort serialPort() const {return m_serialPort;}
    inline void setSerialPort(SerialPort var){m_serialPort = var;}
    /* Exported functions prototypes ---------------------------------------------*/

    EConnection(SerialPort port);
    inline bool isConnect(){return m_isConnect;}
    void searchSlave();
    int setConnect(SerialPort port);
    bool sendRequest(ERequestUnit request);
    int sendRequestId(ERequestUnit request);

    //Test

signals:
    void reply(ERequestUnit request);
    void modbusRequest(ERequestUnit request);
    void connectChanged(bool status);
    void errorOccurred(ERequestUnit request);
    void error(QModbusDevice::Error error);

private slots:
    void on_timerPoll();
    void on_connected(bool status);
    void on_error(QModbusDevice::Error error);
    void on_reply(ERequestUnit request);


private:
    EDeviceInfoList m_edeviceInfoList;
    SerialPort m_serialPort;
    EModbus *m_emodbus = nullptr;
    QThread *m_thread = nullptr;
    ERequestUnit m_requestUnit;

    QList<ERequestUnit> m_requestQueueRTU;

    bool m_stateRequest = false;
    bool m_isConnect = false;
    int m_errorSerialPort = 0;
    bool m_resetSlaveAddress = false;
    bool m_slaveReseting = false;

    void init();
    bool insertRequestModbusRTU(ERequestUnit request);//insert request into queue
    bool getRequestModbusRTU(ERequestUnit *request);                     //get unit from queue
    bool checkRequestModbusRTU(ERequestUnit request);

    void modbusRequestPoll();
    void resetSlaveAddress();
    void getSlaveAddress(ERequestUnit request);
    //TimerTest
    QTimer *m_timerPoll = nullptr;
};

#endif // ECONNECTION_H
