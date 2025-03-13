#ifndef EPARAMETER_PRACTICEBASE_H
#define EPARAMETER_PRACTICEBASE_H
#include <QVariant>
#include <QtCharts/QChart>
#include <QtCharts/QSplineSeries>
#include <QtCharts>
#include <QtCharts/QValueAxis>
#include "device/edeviceinfo.h"
#include <QSettings>
#include <QDataStream>

class EParameter_PracticeBase
{
public:
    EParameter_PracticeBase();

    struct PracticeType{
        bool play= false;//pause
        double timeOut = 10;
        double timeCount = 0;
        double timeManual = 0;
        int sampleTime = 1000;
        int sampleType = 0;
        int lineType = 0;
        int axisType = 1;
        int logaritType = 0;
        QList<EDeviceInfo> devices;
        QList<QtCharts::QSplineSeries*> series;
        QList<QtCharts::QValueAxis*> axis;
        int numberOf = 0;//number of practices
    };

    struct PracticeInfo{
        //teacher
        QString header="";
        QString subject = "";
        QString teacher="";
        //student
        QString unit="";
        QString student="";
        QString classroom = "";
        QString group = "";
        QString date="";
        QString description="";
        QString parameter="";
    };

    //parameter for practice process
    inline void setPracticeType(PracticeType var){m_practiceType = var;}
    inline PracticeType practiceType() const {return m_practiceType;}

    //info for report and datafile
    inline void setPracticeInfo(PracticeInfo var){m_practiceInfo = var;}
    inline PracticeInfo practiceInfo() const {return m_practiceInfo;}

    //save parameter
    void saveInfo();
private:
    PracticeType m_practiceType;
    PracticeInfo m_practiceInfo;

    //info file
    void writeInfoFile();
    void readInfoFile();
};
Q_DECLARE_METATYPE(EParameter_PracticeBase)
#endif // EPARAMETER_PRACTICEBASE_H
