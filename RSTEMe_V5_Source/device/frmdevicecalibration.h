#ifndef FRMDEVICECALIBRATION_H
#define FRMDEVICECALIBRATION_H

#include <QMainWindow>
#include "device/edevice.h"
#include "device/edevicelist.h"
#include "device/def/esensor.h"
#include "device/def/edeviceparameter.h"
#include "device/frmdevicetable.h"
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QtCharts/QChart>
#include <chart/echartview.h>
#include <QVBoxLayout>
#include <QTimer>
#include <QLineEdit>
#include <QMenu>
#include <QMessageBox>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class FrmDeviceCalibration;
}

class FrmDeviceCalibration : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDeviceCalibration(QWidget *parent = nullptr);
    ~FrmDeviceCalibration();

    enum CalibPoint{
        CAL_pointOne,
        CAL_pointTwo,
        CAL_pointThree
    };
    enum CalibAccuracyType{
        ACC_accordingValue,
        ACC_accordingReading,               //accuracy according to value
        ACC_accordingFullScale
    };
    enum CalibMethodType{
        CMT_standardSample,               //accuracy according to value
        CMT_referenceSample
    };
    enum EvaluateMethodType{
        EMT_accuracy,               //accuracy according to value
        EMT_standardDeviation
    };
    struct CalibParameter{
        int calibTime = 10;
        int sampleTime = 100;
        int sampleNumber = 10;
        CalibPoint  calibpoint = CAL_pointOne;
        CalibAccuracyType   accuracyType = ACC_accordingValue;
        qreal accuracyValue = 1;
        qreal RangeMin = 0;
        qreal RangeMax = 100;
        CalibMethodType methodType = CMT_standardSample;
        qreal standardValue = 0;
        qreal standardValue01 = 0;
        qreal standardValue02 = 0;
        qreal standardValue03 = 0;
        qreal referenceValue = 0;
        EvaluateMethodType evaluateType = EMT_accuracy;
    };
    struct EvaluateParameter{
        bool isFail = true;
        qreal calibValue = 0;
        QList<qreal> calibBuffer;
        qreal referenceValue = 0;
        QList<qreal> referenceBuffer;
        QList<qreal> rawBuffer;
        qreal calX = 0;
        qreal calY = 0;
    };

    //properties
    inline CalibParameter calibParameter(){return m_calibParameter;}
    void setCalibParameter(CalibParameter var);



    void setDevice(EDevice *dev);
    inline EDevice* device(){return m_edevice;}

protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;
signals:
    void replySelectDeviceInfo(EDeviceInfo dev);

private slots:
    void on_newDataDevice(EDevice* dev);
    void on_newDataDeviceReference(EDevice* dev);
    void on_errorDeviceReference(EDevice::Error err);
    void on_replySelectDeviceInfo(EDeviceInfo dev);
    void on_timerPoll();

    void on_comboBox_theme_currentIndexChanged(int index);

    void on_checkBox_antiAliasing_toggled(bool checked);

    void on_comboBox_legend_currentIndexChanged(int index);

    void on_toolButton_toolCrosshair_clicked();

    void on_toolButton_toolCallout_clicked();

    void on_toolButton_toolPlay_clicked();

    void on_toolButton_toolPause_clicked();

    void on_radioButton_standardSample_toggled(bool checked);

    void on_spinBox_calibTime_valueChanged(int arg1);

    void on_spinBox_sampleTime_valueChanged(int arg1);

    void on_spinBox_sampleNumber_valueChanged(int arg1);

    void on_comboBox_calibPointSelect_currentIndexChanged(int index);

    void on_lineEdit_standardValue_editingFinished();

    void on_comboBox_accuracySelect_currentIndexChanged(int index);

    void on_lineEdit_accuracy_textChanged(const QString &arg1);

    void on_lineEdit_standardValue_textChanged(const QString &arg1);

    void on_spinBox_rangeMax_valueChanged(int arg1);

    void on_spinBox_rangeMin_valueChanged(int arg1);

    void on_comboBox_unit_currentIndexChanged(int index);

    void on_pushButton_clearCalibOne_clicked();

    void on_pushButton_clearCalibTwo_clicked();

    void on_pushButton_clearCalibThree_clicked();

    void on_pushButton_addDeviceRef_clicked();

private:
    Ui::FrmDeviceCalibration *ui;
    QTimer *m_timePoll = nullptr;

    QSize m_sizeWindow = QSize(1,1);
    QSize m_graphicView = QSize(1,1);
    QSize m_frameHeader = QSize(1,1);
    QSize m_frameToolTrack = QSize(1,1);
    QRect m_frameToolControl = QRect(1,1,1,1);

    EDevice *m_edevice = nullptr;
    ESensor *m_esensor = nullptr;

    EDeviceInfo m_deviceInfo;
    EDevice *m_edeviceReference = nullptr;
    ESensor *m_esensorReference = nullptr;

    EDeviceParameter m_para;
    FrmDeviceTable *m_frmDeviceTable = nullptr;

    uint32_t m_timeTickSingle = 0;

    //Chart
    QValueAxis *m_axisX = nullptr;
    QValueAxis *m_axisY = nullptr;
    qreal m_axisX_Max = 0;
    qreal m_axisY_Max = 0;
    qreal m_axisY_Min = 0;
    int m_indexScroll = 0;
    QChart *m_chart = nullptr;

    QLineSeries *m_lineSeriesReference = nullptr;
    QLineSeries *m_lineSeriesValue = nullptr;
    QLineSeries *m_lineSeriesHigher = nullptr;
    QLineSeries *m_lineSeriesLower= nullptr;

    QList <QLineSeries*> m_listSeris;
    EChartView *m_echartView = nullptr;

    bool m_chartPlay = false;
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





    //Calib
    int m_sampleTimeLast = 100;
    CalibParameter m_calibParameter,m_calibParameterDefault;
    EvaluateParameter m_evaluateParameter,m_evaluateParameterDefault;
    QMessageBox  *m_msg = nullptr;
    void setMessage(QString text, QMessageBox::Icon icon);
    bool getCalibParameter();
    void updateCalibParameter(CalibParameter para);
    void setCalibText(EDeviceParameter para);

    qreal getAccuracyMax();
    qreal getAccuracyMin();
    void initLineBarrier(); //use for accuracy
    void updateLineBarrier(); //use for accuracy
    void updateChartError();

    qreal precision(qreal val,int res);
    void initCalib();
    void startCalib();
    void stopCalib();
    void updateCalib(QPointF point);
    void evaluate();
    void clearCalib(int p);

    //device reference
    enum DeviceReferenceConnect{
        DRC_FindDevice,
        DRC_CheckConnect,
        DRC_Poll
    };
    DeviceReferenceConnect m_drcConnect;
    QList<double> m_drcBufferError;
    bool m_isConnectDeviceParameter = false;
    int m_referenceConnectTimeOut = 0;
    void checkReferenceConnect();
    void newDataSensorReferece(ESensor* sen);
};

#endif // FRMDEVICECALIBRATION_H
