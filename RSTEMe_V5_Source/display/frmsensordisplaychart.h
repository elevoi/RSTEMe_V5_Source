#ifndef FRMSENSORDISPLAYCHART_H
#define FRMSENSORDISPLAYCHART_H

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
class FrmSensorDisplayChart;
}

class FrmSensorDisplayChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmSensorDisplayChart(QWidget *parent = nullptr);
    ~FrmSensorDisplayChart();

    void setDevice(EDevice *dev);
    void removeDevice(EDevice *dev);

    inline EDevice* device(){return m_edevice;}

protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;

private slots:
    void on_newDataDevice(EDevice* dev);

    void on_comboBox_theme_currentIndexChanged(int index);

    void on_checkBox_antiAliasing_toggled(bool checked);

    void on_comboBox_legend_currentIndexChanged(int index);

    void on_toolButton_toolCrosshair_clicked();

    void on_toolButton_toolCallout_clicked();

    void on_toolButton_toolPlay_clicked();

    void on_toolButton_toolPause_clicked();

    void on_toolButton_toolClear_clicked();

private:
    Ui::FrmSensorDisplayChart *ui;

    QSize m_sizeWindow = QSize(1,1);
    QSize m_graphicView = QSize(1,1);
    QSize m_frameHeader = QSize(1,1);
    QSize m_frameToolTrack = QSize(1,1);
    QRect m_frameToolControl = QRect(1,1,1,1);

    EDevice *m_edevice = nullptr;
    ESensor *m_esensor = nullptr;
    EDeviceParameter m_para;

    uint32_t m_timeTickSingle = 0;

    //Chart
    QValueAxis *m_axisX = nullptr;
    QValueAxis *m_axisY = nullptr;
    qreal m_axisX_Max = 0;
    qreal m_axisY_Max = 0;
    qreal m_axisY_Min = 0;
    int m_indexScroll = 0;
    QChart *m_chart = nullptr;
    QLineSeries *m_lineSeries = nullptr;

    QList <QLineSeries*> m_listSeris;
    EChartView *m_echartView = nullptr;

    bool m_chartPlay = true;
    void initChart();

    void updateChartView();
    void updateChart(ESensor* sen);

    //remove

    void removeChart(ESensor* sen);
    void removeSensor();

    //data
    uint32_t elapsed(uint32_t now,uint32_t last);
    uint32_t different(uint32_t now,uint32_t last);
    void newDataSensor(ESensor* sen);
    bool checkTimeSync(ESensor* sen);
    void resetParameter();
    void checkIndexScroll(ESensor* sen);

    //chart tool
    void clearChart();
    void setToolControl(bool play);
    void updateTrackLine(EChartView::ETrackLine track);

    //theme
    void initTheme();
    void initLegend();
    void updateTheme(int index);
    void updateLegend(int index);
    void updateAntiAliasing(bool checked);

};

#endif // FRMSENSORDISPLAYCHART_H
