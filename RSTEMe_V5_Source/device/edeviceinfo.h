#ifndef EDEVICEINFO_H
#define EDEVICEINFO_H
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class EDeviceInfo
{

public:
    EDeviceInfo();
    EDeviceInfo(QJsonObject object);
    enum ConnectionType{
        ModbusRTU,
        ModbusTCP
    };
    enum SerialType{
        SERIAL_GROUP,       //group of device, sensor, module, system...
        SERIAL_DEVICE,      //type of device, temperature, humidity...
        SERIAL_VERSION,
        SERIAL_ID,           //device identifier, Unique code for each device
        SERIAL_WINDOW
    };

    enum GroupType{
        GROUP_SOFTWARE,
        GROUP_SENSOR,
        GROUP_MODULE,
        GROUP_SYSTEM,
        GROUP_TOOL
    };
    struct CalibParameter{
        int calibTime = 10;
        int sampleTime = 100;
        int sampleNumber = 10;
        int accuracyType = 0;
        qreal accuracyValue = 1;
        qreal RangeMin = 0;
        qreal RangeMax = 100;
        int methodType = 0;
        qreal standardValue01 = 0;
        qreal standardValue02 = 0;
        qreal standardValue03 = 0;
        int evaluateType = 0;
    };

    struct DeviceParameter{
        int Address=1;
        int AddressDefault=127;
        int SerialNumber = 0x00000000;
        int SampleTime = 1000;
        ConnectionType TypeConnect = ModbusRTU;
        int Priority = 3;
        int Retries = 3;
        int TimeOut = 100;
        int RegStart = 40004;
        int RegNumber = 100;
        //display
        QList<int> ToolDisplay;
        QList<int> ToolPractice;
        QList<int> ToolControl;
        qreal RangeMin = 0;
        qreal RangeMax = 100;

    };

    struct DeviceInfo{
        int Account = 0;            //0:student, 1:teacher, 2:root
        QString Name="";
        QString Description="";
        QString Icon="";
        QString IconOn="";
    };

     /*Operator-----------------------------------------*/
    bool operator==(const EDeviceInfo &info){return m_deviceParameter.SerialNumber == info.serial();}
    bool operator!=(const EDeviceInfo &info){return m_deviceParameter.SerialNumber != info.serial();}


    QJsonObject getJsonDevice();
    void setJsonDevice(QJsonObject jsonObject);
    /*properties-----------------------------------------*/
    inline int serial() const {return m_deviceParameter.SerialNumber;}
    static QString serialHex(int var);
    static QString serialHex(quint16 hi,quint16 lo);
    static int serialDec(QString var,bool *ok);
    QString serialHex();
    void setSerial(int var){m_deviceParameter.SerialNumber = var;}
    int serial(SerialType type) const;
    void setSampleTime(int var){m_deviceParameter.SampleTime = var;}
    inline int sampleTime() const {return m_deviceParameter.SampleTime;}

    inline int addressDefault()const {return m_deviceParameter.AddressDefault;}
    void setAddressDefault(int add){m_deviceParameter.AddressDefault = add;}

    inline int account() const {return m_deviceInfo.Account;}
    void setAccount(int var){m_deviceInfo.Account = var;}

    inline QString name() const {return m_deviceInfo.Name;}
    void setName(QString name){m_deviceInfo.Name = name;}

    QString objectName();

    inline QString icon() const {return m_deviceInfo.Icon;}
    void setIcon(QString icon){m_deviceInfo.Icon = icon;}
    inline QString iconOn() const {return m_deviceInfo.IconOn;}
    void setIconOn(QString icon){m_deviceInfo.IconOn = icon;}

    inline QString description() const {return m_deviceInfo.Description;}
    void setDescription(QString des){m_deviceInfo.Description = des;}

    inline QList<int> toolDisplay() const {return m_deviceParameter.ToolDisplay;}
    void setToolDisplay(QList<int> var){m_deviceParameter.ToolDisplay = var;}

    inline QList<int> toolPractice() const {return m_deviceParameter.ToolPractice;}
    void setToolPractice(QList<int> var){m_deviceParameter.ToolPractice = var;}

    inline QList<int> toolControl() const {return m_deviceParameter.ToolControl;}
    void setToolControl(QList<int> var){m_deviceParameter.ToolControl = var;}

    inline bool selectTool(){return m_isSelectTool;}
    inline void setSelectTool(bool var){m_isSelectTool = var;}

    void setTypeConnect(ConnectionType var){m_deviceParameter.TypeConnect = var;}
    inline ConnectionType typeConnect() const {return m_deviceParameter.TypeConnect;}

    inline int address()const {return m_deviceParameter.Address;}
    void setAddress(int add){m_deviceParameter.Address = add;}

    inline int priority()const {return m_deviceParameter.Priority;}
    void setPriority(int var){m_deviceParameter.Priority = var;}

    inline int retries()const {return m_deviceParameter.Retries;}
    void setRetries(int var){m_deviceParameter.Retries = var;}

    inline int timeOut()const {return m_deviceParameter.TimeOut;}
    void setTimeOut(int var){m_deviceParameter.TimeOut = var;}

    inline int regStart()const {return m_deviceParameter.RegStart;}
    void setRegStart(int var){m_deviceParameter.RegStart = var;}

    inline int regNumber()const {return m_deviceParameter.RegNumber;}
    void setRegNumber(int var){m_deviceParameter.RegNumber = var;}

    inline qreal rangeMin()const {return m_deviceParameter.RangeMin;}
    void setRangeMin(qreal var){m_deviceParameter.RangeMin = var;}

    inline qreal rangeMax()const {return m_deviceParameter.RangeMax;}
    void setRangeMax(qreal var){m_deviceParameter.RangeMax = var;}

    //calib
    inline CalibParameter calibParameter(){return m_calibParameter;}
    inline void setCalibParameter(CalibParameter var){m_calibParameter = var;}
    //function
    bool openFile();
    bool saveFile();

private:
    DeviceParameter m_deviceParameter;
    DeviceInfo      m_deviceInfo;
    CalibParameter m_calibParameter;


    QJsonObject m_jsonObject
    {
        //DeviceParameter
        {"Address",1},
        {"AddressDefault",127},
        {"SerialNumber",0},

        //DeviceInfo
        {"Name",""},
        {"Description",""}
    };

    bool m_isSelectTool = true;

    //Function
    void updateJsonObject();
    void setJsonObject(QJsonObject json);
    QJsonValue getJsonValue(QJsonValue value,QJsonValue init);

    //file
    QJsonArray getQJsonArray(QList<int> list);
    QList<int> fromQJsonArray(QJsonArray array,int valueDefault);
    bool saveDeviceInfo();
    bool openDeviceInfo();
};

#endif // EDEVICEINFO_H
