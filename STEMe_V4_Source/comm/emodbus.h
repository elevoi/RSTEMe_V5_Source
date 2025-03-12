#ifndef EMODBUS_H
#define EMODBUS_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QModbusRtuSerialMaster>
#include <comm/erequestunit.h>

class EModbus : public QObject
{
    Q_OBJECT
public:
    explicit EModbus(QObject *parent = nullptr);
    ~EModbus();

    /* Exported types ------------------------------------------------------------*/

    /* Exported constants --------------------------------------------------------*/

    /* Exported macro ------------------------------------------------------------*/

    /* Private variables ---------------------------------------------------------*/

    /* Exported properties -------------------------------------------------------*/
signals:
    void connected(bool status);
    void reply(ERequestUnit request);
    void error(QModbusDevice::Error error);

public slots:
    void on_modbusRequest(ERequestUnit request);

private slots:
    void on_ReadReady();
    void on_WriteReady();
    void on_errorOccurred(QModbusDevice::Error error);


private:
    /* Private variables ---------------------------------------------------------*/
    QModbusClient *m_modbusDevice=nullptr;

    int m_request_ID=0;
    ERequestUnit m_requestUnit;

    /* Private functions prototypes -----------------------------------------------*/
    bool connectModbus(ERequestUnit request);
    bool readRequestModbus(ERequestUnit request);
    bool writeRequestModbus(ERequestUnit request);

};

#endif // EMODBUS_H
