#ifndef FRMDEVICECONFIG_H
#define FRMDEVICECONFIG_H

#include <QMainWindow>
#include "device/def/esensor.h"
#include "device/edevice.h"
#include "device/def/edeviceparameter.h"

namespace Ui {
class FrmDeviceConfig;
}

class FrmDeviceConfig : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDeviceConfig(QWidget *parent = nullptr);
    ~FrmDeviceConfig();

    void setDevice(EDevice *dev);
    inline EDevice* device(){return m_edevice;}
    void setSensor(ESensor *sen);

private slots:
    void on_newData(int id);
    void on_pushButton_cancel_clicked();

    void on_toolButton_setZero_clicked();

    void on_toolButton_setSampleTime_clicked();

    void on_toolButton_clearZero_clicked();

    void on_comboBox_unit_currentIndexChanged(int index);

    void on_comboBox_resolution_currentIndexChanged(int index);

    void on_lineEdit_Zero_editingFinished();


    void on_checkBox_tempCompensation_toggled(bool checked);

private:
    Ui::FrmDeviceConfig *ui;
    EDevice *m_edevice = nullptr;
    ESensor *m_esensor = nullptr;
    EDeviceParameter m_para;
    bool m_initStatus = false;

    void init();
    void setValue();
};

#endif // FRMDEVICECONFIG_H
