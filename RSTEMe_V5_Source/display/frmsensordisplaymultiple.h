#ifndef FRMSENSORDISPLAYMULTIPLE_H
#define FRMSENSORDISPLAYMULTIPLE_H

#include <QMainWindow>
#include "device/edevice.h"
#include "device/def/edeviceparameter.h"
#include "display/widsensordisplaydigital.h"
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QtCharts/QChart>
#include <QChartView>
#include <QVBoxLayout>
#include <QTimer>


namespace Ui {
class FrmSensorDisplayMultiple;
}

class FrmSensorDisplayMultiple : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmSensorDisplayMultiple(QWidget *parent = nullptr);
    ~FrmSensorDisplayMultiple();

    void addDevice(EDevice *dev);
    inline EDevice* device(){return m_edevice;}


protected:
    //void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;

private slots:
    void on_removeDevice(EDevice *dev);
    void on_toolButton_cancel_clicked();

    void on_spinBox_rowMax_valueChanged(int arg1);

private:
    Ui::FrmSensorDisplayMultiple *ui;


    QSize m_sizeWindow = QSize(1,1);
    QSize m_graphicView = QSize(1,1);
    QRect m_frameStatus = QRect(1,1,1,1);
    QRect m_buttonCancel = QRect(1,1,1,1);

    EDevice *m_edevice = nullptr;
    EDeviceParameter m_para;

    QList<EDevice*> m_listDevice;

    QList<WidSensorDisplayDigital*> m_listSensorDisplayDigital;
    WidSensorDisplayDigital* m_widSensorDisplayDigital = nullptr;

    QList<QColor> m_listColor = {QColor::fromRgb(0,128,128),Qt::red,Qt::green,Qt::blue,Qt::cyan,\
                                Qt::magenta,Qt::yellow,Qt::gray};

    int m_colorIndex = 0;
    int m_gridRowMax = 3;

    QGridLayout *m_gridLayout = nullptr;

    //remove
    void removeDevice();

    void removeDisplay(EDevice* dev);
    void refreshDisplay();

    //display
    void removeSensorDisplayDigital(EDevice *dev);
    WidSensorDisplayDigital *getSensorDisplayDigital(EDevice *dev);

};

#endif // FRMSENSORDISPLAYMULTIPLE_H
