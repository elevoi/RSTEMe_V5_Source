#ifndef EJSONFILE_H
#define EJSONFILE_H
#include <QVariant>
#include <QSettings>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QtCharts>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QList>


class QString;
class EJsonFile
{
public:
    EJsonFile();
    //properties
    inline QJsonObject jsonObject() const {return m_jsonObject;}
    inline void setJsonObject(QJsonObject var) {m_jsonObject=var;}
    inline bool empty() const {return m_jsonObject.empty();}
    inline bool isEmpty() const {return m_jsonObject.isEmpty();}

    //function
    void setValue(QString key,QJsonValue var);
    QString value(QString key,QString valueDefault);
    int value(QString key,int valueDefault);
    double value(QString key,double valueDefault);
    QJsonArray value(QString key,QJsonArray valueDefault);

    QJsonArray getJsonArray(QList<int> list);
    QJsonArray getJsonArray(QList<double> list);
    QJsonArray getJsonArray(QList<QJsonObject> list);

    QList<int> fromJsonArray(QJsonArray array,int valueDefault);
    QList<double> fromJsonArray(QJsonArray array,double valueDefault);
    QList<QJsonObject>  fromJsonArray(QJsonArray array,QJsonObject valueDefault);
    void clear();

    //QSpline
    QJsonObject getJsonObject(QtCharts::QSplineSeries *series);
    bool fromJsonObject(QJsonObject obj,QtCharts::QSplineSeries* series,QValueAxis *axis);
    //file
    void write(const QString &organization, const QString &application, const QString &key);
    bool read(const QString &organization, const QString &application, const QString &key);

    //saveAs
    bool saveFile(QString fileName,QString extension,QJsonObject obj);
    bool openFile(QString extension,QJsonObject &obj);
private:
    //Function
    QJsonObject m_jsonObject;
    QJsonValue getJsonValue(QJsonValue value,QJsonValue init);
    QSplineSeries* m_series;
};
#endif // EJSONFILE_H
