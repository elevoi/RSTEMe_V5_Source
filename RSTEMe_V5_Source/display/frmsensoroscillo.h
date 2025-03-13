#ifndef FRMSENSOROSCILLO_H
#define FRMSENSOROSCILLO_H

#include <QMainWindow>
#include "device/edevice.h"
#include "device/def/esensor.h"
#include "device/def/edeviceparameter.h"
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QtCharts/QChart>
#include <chart/echartview.h>
#include <QVBoxLayout>
#include <QTimer>
#include <QLineEdit>
#include <QMenu>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class FrmSensorOscillo;
}

class FrmSensorOscillo : public QMainWindow
{
    Q_OBJECT
    struct ETypeDef_ChartParameter{     //chart
        EChartView *chartView = nullptr;
        QChart *chart = nullptr;
        QLineSeries *lineSeries = nullptr;
        QValueAxis *axisX = nullptr;
        QValueAxis *axisY = nullptr;
        int axisX_Tick = 11;
        qreal axisX_Min = 0;
        qreal axisX_Max = 1;
        int axisY_Tick = 11;
        qreal axisY_Min = 0;
        qreal axisY_Max = 1;
        qreal interval = 0.002;//adc_time_poll
        uint32_t timeIndex = 0;
        //control
        bool play = false;

    };
    struct ETypeDef_Oscillo{        //oscillo
        int timePoll = 2;//millisecond
        int scope=0;
        QList<QString> scopeText = {"10 ms/div","20 ms/div","50 ms/div","100 ms/div","200 ms/div","500 ms/div","1 s/div","2 s/div","5 s/div","10 s/div"};
        QList<qreal> scopeMax = {0.01,0.02,0.05,0.1,0.2,0.5,1,2,5,10};
    };

public:
    explicit FrmSensorOscillo(QWidget *parent = nullptr);
    ~FrmSensorOscillo();
    void setDevice(EDevice *dev);
    void removeDevice(EDevice *dev);

    inline EDevice* device(){return m_edevice;}

protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;

private slots:
    void on_newDataDevice(EDevice* dev);

    //button
    void on_toolButton_toolCrosshair_clicked();

    void on_toolButton_toolCallout_clicked();

    void on_toolButton_toolPlay_clicked();

    void on_toolButton_toolPause_clicked();

    void on_toolButton_toolClear_clicked();
    void on_toolButton_plus_clicked();

    void on_toolButton_minus_clicked();

private:
    Ui::FrmSensorOscillo *ui;
    struct ETypeDef_FormResize{
        QSize window = QSize(1,1);
        QSize graphicView = QSize(1,1);
        QSize frameToolTrack = QSize(1,1);
        QSize frameToolSetup = QSize(1,1);
        QRect framePlay = QRect(1,1,1,1);
        QRect frameControl = QRect(1,1,1,1);
    }m_formResize;



    EDevice *m_edevice = nullptr;
    ESensor *m_esensor = nullptr;
    EDeviceParameter m_para;
    //sensor
    void removeSensor();
    void newDataSensor(ESensor* sen);

    //control
    void setToolControl(bool play);

    //Chart
    ETypeDef_ChartParameter m_chartPara;

    void chartInit();
    void chartViewUpdate();
    void chartUpdate(ESensor* sen);
    void chartRemove(ESensor* sen);
    void chartClear();
    void chartSetTrackLine(EChartView::ETrackLine track);

    //oscillo
    ETypeDef_Oscillo m_oscilloPara;
    void setScope(int var);
};

#endif // FRMSENSOROSCILLO_H
