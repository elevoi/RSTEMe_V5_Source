#ifndef ESENSOR_H
#define ESENSOR_H
#include <QObject>
#include "device/edevice.h"
#include "device/edeviceinfo.h"
#include "device/def/edef_v5.h"
#include <QList>
#include "elog.h"

#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QtCharts/QChart>

QT_CHARTS_USE_NAMESPACE

class ESensor : public QObject
{
    Q_OBJECT
public:
    ESensor(EDevice *dev);
    ESensor(QObject *parent = nullptr,EDevice *dev=nullptr);
    ~ESensor();
    /* Exported types ------------------------------------------------------------*/
    inline EDevice* device(){return m_edevice;}
    void setDevice(EDevice *dev);
    inline void setChart(QChart *var){m_chart = var;}
    inline QChart* chart(){return m_chart;}
    inline QList<QLineSeries*> series(){return m_listSeries;}
    inline QLineSeries* seriesValue(){return m_seriesValue;}
    inline QLineSeries* seriesTemperature(){return m_seriesTemperature;}

    inline int seriesMax(){return m_series_Max;}
    inline void setSeriesMax(int var){m_series_Max = var;}

    inline bool timeSync(){return m_timeSync;}
    inline void setTimeSync(bool var){m_timeSync = var;}

    /* Exported constants --------------------------------------------------------*/

    /* Exported macro ------------------------------------------------------------*/


    /* Exported properties -------------------------------------------------------*/
    inline EDeviceParameter parameter() const {return m_edeviceParameter;}
    void setParameter(EDeviceParameter var);
    /* Exported functions prototypes ---------------------------------------------*/
    void start();
    void start(uint32_t tick);
    void setTempCompensation(bool var);


    //communication function
    void setControl(uint16_t ctrl);
    void setZero(uint32_t zero);
    void setSampleTime(int time);
    inline uint32_t sampleTime(){return m_edeviceInfo.sampleTime();}
    void setSampleTime();
    void setTimeTick(uint32_t time);
    void setMeasurePeriodic();

    void setCalib(int p,uint32_t x, uint32_t y);
    //function
    void appendSeries(qreal tick);
    void replaceSeries(qreal interval,uint32_t &index,qreal max);

    EDeviceParameter devicePara(EDeviceInfo dev);
signals:
    void newData(int id);
    void newDataDevice(EDevice* dev);
    void error(EDevice::Error err);

private slots:
    void on_result(ERequestUnit request);
    void on_error(EDevice::Error err);

private:
    /* Private variables ---------------------------------------------------------*/

    /* Private functions prototypes -----------------------------------------------*/
    EDevice *m_edevice = nullptr;
    EDeviceInfo m_edeviceInfo;
    ERequestUnit m_requestUnit;

    EDeviceParameter m_edeviceParameter;
    EDef *m_edef = nullptr;
    ELog m_elog;
    void init();
    void destroy();


    //Chart
    QChart *m_chart = nullptr;
    QList<QLineSeries*> m_listSeries;
    QLineSeries *m_seriesValue = nullptr;
    QLineSeries *m_seriesTemperature = nullptr;
    int m_series_Max = 10000;

    qreal m_timeTickLast = 0;
    bool m_timeSync = false;
    /* Private functions of def -----------------------------------------------*/

    EDeviceParameter getDevicePara();
    void setDevicePara(EDeviceParameter para);

    void measureStart();
    void measureStart(uint32_t tick);
    void setRequest();

    //chart
    uint32_t elapsed(uint32_t now,uint32_t last);
    qreal elapsed(qreal now,qreal last);
    void initChart();
    void setTimeDefault(int time,uint32_t tick);
};

#endif // ESENSOR_H
