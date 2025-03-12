#ifndef WIDSENSORTOOLDIGITAL_H
#define WIDSENSORTOOLDIGITAL_H

#include <QWidget>
#include "device/def/esensor.h"
#include "device/edevice.h"
#include "device/def/edeviceparameter.h"
#include "device/frmaddsensor.h"
#include "control/frmdeviceconfig.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QValueAxis>

namespace Ui {
class WidSensorToolDigital;
}

class WidSensorToolDigital : public QWidget
{
    Q_OBJECT

public:
    explicit WidSensorToolDigital(QWidget *parent = nullptr);
    ~WidSensorToolDigital();

    struct EvaluateParameter{
        int sample = 0;     //number of samples
        double sum = 0;
        double max = 0;     //maximum
        double min = 0;     //minimum
        double avr = 0;     //average
        double var = 0;     //variance
        double std = 0;     //standard deviation
        QList<double> buff;
    };

    void setDevice(EDevice *dev);
    inline EDevice* device(){return m_edevice;}

    inline ESensor* sensor(){return m_esensor;}

    inline bool isConnect(){return m_isConnect;}
    inline qreal value(){return m_para.value();}

    inline int sampleTimeLast(){return m_sampleTimeLast;}
    void setSampleTime(int time);
    QSplineSeries *newSeries();
    QSplineSeries *series();
    inline QList<QSplineSeries*> listSeries(){return m_listSeries;}
    QValueAxis *axisY();
    void resizeAxisY(qreal val);
    void resetAxisY();
    void removeSeries();

    void setDisplayColor(QColor c);
    inline EvaluateParameter evaluate(){return m_evaluatePara;}
    void updateEvaluate(double val);
    void resetEvaluate();

signals:
    void removeDevice(EDevice* dev);
    void updatePoint(QtCharts::QSplineSeries *series,qreal value);

private slots:
    void on_newData(int id);
    void on_error(EDevice::Error err);


    void on_toolButton_info_clicked();

    void on_toolButton_close_clicked();

    void on_toolButton_setup_clicked();

private:
    Ui::WidSensorToolDigital *ui;
    EDevice *m_edevice = nullptr;
    ESensor *m_esensor = nullptr;
    EDeviceParameter m_para;
    bool m_isConnect = false;
    int m_sampleTimeLast = 0;
    EvaluateParameter m_evaluatePara;

    FrmAddSensor *m_frmAddSensor = nullptr;
    FrmDeviceConfig *m_frmDeviceConfig = nullptr;

    //Chart
    QSplineSeries *m_series = nullptr;
    QValueAxis *m_axisY = nullptr;
    QList<QSplineSeries*> m_listSeries;

    qreal m_axisY_Max = -999999;
    qreal m_axisY_Min = 999999;

    void initDisplay();
    void setValue();
};

#endif // WIDSENSORTOOLDIGITAL_H
