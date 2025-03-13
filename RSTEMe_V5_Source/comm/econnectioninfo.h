#ifndef ECONNECTIONINFO_H
#define ECONNECTIONINFO_H
#include <QVariant>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

class EConnectionInfo
{
public:
    EConnectionInfo();

    struct ConnectionParameter{
        QString ModbusPort = "COM7";
        int ModbusBaud = 115200;
        QString NetworkIP  = "127.0.0.1";
    };

    QString modbusPort(){return m_connectPrarameter.ModbusPort;}
    void setModbusPort(QString var){m_connectPrarameter.ModbusPort = var;}

    int modbusBaud(){return m_connectPrarameter.ModbusBaud;}
    void setModbusBaud(int var){m_connectPrarameter.ModbusBaud = var;}

    QString networkIP(){return m_connectPrarameter.NetworkIP;}
    void setNetworkIP(QString var){m_connectPrarameter.NetworkIP = var;}

    void save();
    bool load();
private:
    ConnectionParameter m_connectPrarameter;
    QJsonObject m_jsonObject
    {
        {"name","EConnectionInfo"}
    };
    //Function
    void updateJsonObject();
    void setJsonObject(QJsonObject json);
    QJsonValue getJsonValue(QJsonValue value,QJsonValue init);

    //file
    void saveDocument();
    bool loadDocument();
};

#endif // ECONNECTIONINFO_H
