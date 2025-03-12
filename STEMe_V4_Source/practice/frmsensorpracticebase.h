#ifndef FRMSENSORPRACTICEBASE_H
#define FRMSENSORPRACTICEBASE_H

#include <QMainWindow>
#include "device/edevice.h"
#include "device/def/edeviceparameter.h"
#include "device/frmdevicetable.h"
#include "display/widsensortooldigital.h"
#include <QVBoxLayout>
#include <QTimer>
#include <QtCharts/QChart>
#include <chart/echartview.h>
#include <QtCharts/QSplineSeries>
#include <QTableWidgetItem>
#include "widget/econtainer.h"
#include <QMenu>
#include "practice/eparameter_practicebase.h"
#include "practice/frmpracticebaseinfo.h"
#include "file/efile_basepractice.h"

namespace Ui {
class FrmSensorPracticeBase;
}

class FrmSensorPracticeBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmSensorPracticeBase(QWidget *parent = nullptr);
    ~FrmSensorPracticeBase();

    struct ToolTableType{
        bool widgetTableBlink = false;
    };

    struct WindowSizeBase{
        QSize window = QSize(1,1);
        QSize graphicView = QSize(1,1);
        QSize frameToolHeader = QSize(1,1);
        QSize frameToolTrack = QSize(1,1);
        QRect frameToolSetup = QRect(1,1,1,1);
        QRect frameToolDevice = QRect(1,1,1,1);
        QRect frameToolData = QRect(1,1,1,1);
        QRect framePlay = QRect(1,1,1,1);
        QRect toolButtonMenu = QRect(1,1,1,1);
        QSize frameToolDeviceFix = QSize(1,1);
        QSize sensorToolDigitalFix = QSize(1,1);
        QRect dataWidget = QRect(1,1,1,1);
        QRect dataEvaluate = QRect(1,1,1,1);
    };

    enum PracticeProcess{
        PPS_idle,
        PPS_setup,
        PPS_play,
        PPS_pause,
        PPS_finish
    };

    enum SampleType{
        SPT_auto,
        SPT_manual
    };
    enum LineType{
        LTP_lineDot,
        LTP_line
    };
    enum AxisType{
        ATP_single,
        ATP_multiple
    };
    enum LogaritType{
        LGT_none,
        LGT_logarit
    };

    void addDevice(EDevice *dev);
    inline EDevice* device(){return m_edevice;}


protected:
    //void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;
signals:
    void replySelectDeviceInfo(EDeviceInfo dev);

private slots:
    void on_removeDevice(EDevice *dev);
    void on_replySelectDeviceInfo(EDeviceInfo dev);
    void on_timerPoll();
    void on_updatePoint(QtCharts::QSplineSeries *series,qreal val);

    void on_toolButton_toolPlay_clicked();
    void on_toolButton_toolPause_clicked();
    void on_toolButton_menuSelect_clicked();


    void on_toolButton_toolTable_clicked();

    void on_comboBox_sampleTime_currentIndexChanged(int index);

    void on_lineEdit_playTime_editingFinished();

    void on_toolButton_toolClear_clicked();

    void on_toolButton_toolCallout_clicked();

    void on_toolButton_toolCrosshair_clicked();

    void on_tableWidget_DataTable_cellClicked(int row, int column);

    void on_comboBox_sampleType_currentIndexChanged(int index);

    void on_toolButton_toolManual_clicked();

    void on_toolButton_toolLineDot_clicked();

    void on_toolButton_toolLine_clicked();

    void on_tableWidget_dataEvaluate_cellClicked(int row, int column);

    void on_toolButton_toolMultiY_clicked();

    void on_toolButton_toolSingleY_clicked();

    void on_toolButton_toolLogarit_clicked();

    void on_toolButton_exportFile_clicked();

    void on_toolButton_saveFile_clicked();

    void on_toolButton_openFile_clicked();

    void on_toolButton_toolHideSeries_clicked();

private:
    Ui::FrmSensorPracticeBase *ui;
    FrmDeviceTable *m_frmDeviceTable = nullptr;
    QTimer *m_timerPoll = nullptr;

    void initDisplay();
    void updateParameter();
    void setSampleTime(int time);
    void setLineType(LineType var);
    void setAxisType(AxisType var);
    void setLogaritType(LogaritType var);

    EDevice *m_edevice = nullptr;
    EDeviceParameter m_para;
    QList<WidSensorToolDigital*> m_listWidSensorToolDigital;
    WidSensorToolDigital *m_widSensorToolDigital = nullptr;
    void removeSensorToolDigital(EDevice *dev);
    WidSensorToolDigital *getSensorToolDigital(EDevice *dev);
    void refreshToolDevice();


    WindowSizeBase m_widowSizeBase;
    void getSizeWindow();
    void updateSizeWindow(int del_w, int del_h);


    //Practice
    PracticeProcess m_practiceProcess = PPS_idle;
    EParameter_PracticeBase m_practiceParameter;
    EParameter_PracticeBase::PracticeType m_practiceType;
    void setSampleType(int type);
    void setPlay(bool status);
    void playManualPoll();
    void playAutoPoll();
    bool processAutoSetup();
    bool processAutoPlay();
    void processAutoPause();
    void processUpdate(QtCharts::QSplineSeries *series,QPointF p);
    void manualUpdate();
    void updateClock(qreal val);
    void updateClockWise(qreal val);
    bool getTimePractice();

    //chart
    QValueAxis *m_axisX = nullptr;
    QValueAxis *m_axisY = nullptr;
    qreal m_axisX_Max = 1;
    qreal m_axisY_Max = -999999;
    qreal m_axisY_Min = 999999;
    QChart *m_chart = nullptr;

    QSplineSeries *m_series = nullptr;
    QList <QSplineSeries*> m_listSeries;
    EChartView *m_echartView = nullptr;

    QIcon m_logaritIcon;


    void initChart();
    void updateChart(WidSensorToolDigital *sen);
    void removeChart(WidSensorToolDigital *sen);
    void removeList(QSplineSeries *series);
    void updateTrackLine(EChartView::ETrackLine track);
    void clearChart();
    void resizeAxisY(qreal val);
    void resetAxisY();

    //Table
    EContainer *m_containerTable = nullptr;
    ToolTableType m_toolTableType;
    QTableWidgetItem *m_tableItem = nullptr;
    void refreshToolTable();
    void initTable();
    void appendTableColumn(QSplineSeries *series);
    void removeTableColumn(int column);
    void setTableRow(int row,int column,QTableWidgetItem *item);
    void setSelectTable(QSplineSeries *series,QPointF p);
    void removeTableRow();
    void updateEvaluate(WidSensorToolDigital *sen, double val,int index);
    void setEvaluateTableRow(int row,int column,QString val);

    //File export
   // QMenu *m_menuExportFile = nullptr;
    FrmPracticeBaseInfo *m_frmPracticeBaseInfo = nullptr;
    EFile_BasePractice m_fileBasePractice;
    void fileGetParameter();
    void fileSetParameter();
    void fileSave();
    void fileOpen();
    void fileExportExcel();
    void fileExportReport();
    //fileChart
    void fileInitChart();
    void fileUpdateChart(int num);

};

#endif // FRMSENSORPRACTICEBASE_H
