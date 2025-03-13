#ifndef WIDSENSORDISPLAYDIGITAL_H
#define WIDSENSORDISPLAYDIGITAL_H

#include <QWidget>
#include "device/def/esensor.h"
#include "device/edevice.h"
#include "device/def/edeviceparameter.h"

namespace Ui {
class WidSensorDisplayDigital;
}

class WidSensorDisplayDigital : public QWidget
{
    Q_OBJECT

public:
    explicit WidSensorDisplayDigital(QWidget *parent = nullptr);
    ~WidSensorDisplayDigital();

    inline int tempFrameSize(){return m_tempFrameSize;}
    inline QSize currentSize(){return m_currentSize;}

    void setDevice(EDevice *dev);
    inline EDevice* device(){return m_edevice;}

signals:
    void removeDevice(EDevice* dev);
private slots:
    void on_newData(int id);
    void on_toolButton_cancel_clicked();

    void on_comboBox_unit_currentIndexChanged(int index);

    void on_comboBox_resolution_currentIndexChanged(int index);

private:
    Ui::WidSensorDisplayDigital *ui;
    EDevice *m_edevice = nullptr;
    ESensor *m_esensor = nullptr;
    EDeviceParameter m_para;

    int m_tempFrameSize = 60;
    QSize m_currentSize = QSize(1,1);

    void initDisplay();
    void setValue();

};

#endif // WIDSENSORDISPLAYDIGITAL_H
