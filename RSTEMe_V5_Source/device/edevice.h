#ifndef EDEVICE_H
#define EDEVICE_H

#include <QObject>
#include <comm/econnection.h>
#include <QTimer>
#include <QList>
#include <device/edeviceinfo.h>
class EDevice : public QObject
{
    Q_OBJECT
public:
    /* Contructor -------------------------------------------------------*/
    explicit EDevice(QObject *parent = nullptr);
    EDevice(EConnection *conn);
    ~EDevice();

    /* Exported types ------------------------------------------------------------*/

    enum Error{
        NoError,
        ErrorSetAddress,
        ErrorSerialNumber,
        ErrorRequestData,
        ErrorStart
    };

    struct RequestSingle{
        bool status = false;
        ERequestUnit  request;
    };
    struct RequestPeriodic{
        ERequestUnit  request;
    };

    enum MeasureStatus{
        MsIdle,
        MsSingle,
        MsPeriodic
    };
    enum StartStatus{
        StIdle,
        StStarting,
        StStarted,
    };

    /* Exported constants --------------------------------------------------------*/


    /* Exported macro ------------------------------------------------------------*/

    /* Public Static variables ---------------------------------------------------*/

    /* Exported properties -------------------------------------------------------*/
    EDeviceInfo deviceInfo(){return m_deviceInfo;}
    void setDeviceInfo(EDeviceInfo info){m_deviceInfo = info;}

    /* Public Static Function ----------------------------------------------------*/


    EConnection *connection(){return m_connection;}
    void setConnection(EConnection *conn);

    /* Public Function -----------------------------------------------------------*/
    bool start();
    bool start(bool res);
    bool stop();
    StartStatus isStart() const {return m_isStart;}
    inline int reConnectNumber() const {return m_reConnectNumber;}
    //Measure
    MeasureStatus isMeasure() const {return m_isMeasure;}
    bool MeasureRequest(ERequestUnit request);
    bool MeasureSingleShot(ERequestUnit request);
    bool MeasurePeriodic(ERequestUnit request);

signals:
    void result(ERequestUnit request);
    void error(EDevice::Error err);
    void connectChanged(bool status);
    void finished();

private slots:
    void on_connectChanged(bool status);
    void on_reply(ERequestUnit request);
    void on_errorOccurred(ERequestUnit request);
    void on_modbusRequest(ERequestUnit request);
    void on_timerPoll();


private:
    struct DeviceReply{
        bool reply = false;
        bool request = false;
        ERequestUnit unit;
    };
    enum DeviceREG{
        Device_SN1 = 0,
        Device_SN2 = 1,
        Device_ID = 2,
        INPUT_OFFSET = 30001,
        HOLDING_OFFSET = 40001
    };

    enum StartProcess{
        SpIdle,
        SpSetAddress,
        SpGetAddress,
        SpCheckSN,
        SpGetSN,
        SpStarted,
        SpError
    };

    enum MeasureType{
        MSingleShot,
        MPeriodic
    };
    enum RequestProcess{
        MIdle,
        MSendRequest,
        MMeasureSingle,
        MMeasurePeriodic,
        MGetData,
        MCheckTime,
        MCheckType,
        MError
    };

    EDeviceInfo m_deviceInfo;
    QTimer *m_timerPoll;
    EConnection *m_connection = nullptr;
    ERequestUnit m_requestUnit;


    volatile StartProcess m_connectionStart = StartProcess::SpIdle;
    DeviceReply m_deviceReply;



    //Measure
    volatile RequestProcess   m_requestProcess = RequestProcess::MIdle;
    MeasureType     m_measureType = MeasureType::MSingleShot;
    RequestSingle     m_requestSingle;
    RequestPeriodic   m_requestPeriodic;

    MeasureStatus m_isMeasure = MeasureStatus::MsIdle;
    StartStatus m_isStart = StartStatus::StIdle;
    bool m_startPoll = false;
    bool m_connectChanged = false;

    int m_requestID_Read=0;
    int m_requestID_Write=0;

    int m_measureRetries = 0;
    int m_modbusRtuTimeTick=0;
    int m_modbusRtuSampleTime=0;
    QList <int> m_modbusTimeOut;
    int m_modbusTimeOutCount=0;
    int m_modbusTimeRequestCount=0;

    int m_requestAddressNumber = 0;

    int m_reConnectNumber = 0;
    /* Private variables ---------------------------------------------------------*/

    /* Private functions prototypes -----------------------------------------------*/

    //device
    void init();
    //Measure
    int getRequestID(ERequestUnit::RequestType type);
    bool checkRequestID(ERequestUnit::RequestType type,int id);
    bool Measure();
    bool measurePoll();
    //modbus Function
    bool modbusRtuStart();
    void deviceStart();
    bool modbusRtuSetAddress();
    bool modbusRtuGetAddress();
    bool modbusRtuRequestSerialNumber();
    bool modbusRtuGetSerialNumber();
    bool modbusRtuRequestSingle();
    bool modbusRtuRequestPeriodic();
    bool modbusRtuGetData();
    int calculateTimeOut();
};

#endif // EDEVICE_H
