#ifndef FRMSENSORDISPLAYDIGITAL_H
#define FRMSENSORDISPLAYDIGITAL_H

#include <QMainWindow>
#include "device/def/esensor.h"
#include "device/edevice.h"
#include "device/def/edeviceparameter.h"
#include "device/frmaddsensor.h"
#include "control/frmdeviceconfig.h"
#include <QCloseEvent>

namespace Ui {
class FrmSensorDisplayDigital;
}

class FrmSensorDisplayDigital : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmSensorDisplayDigital(QWidget *parent = nullptr);
    ~FrmSensorDisplayDigital();

    void setDevice(EDevice *dev);
    inline EDevice* device(){return m_edevice;}

protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_newData(int id);
    void on_pushButton_cancel_clicked();

    void on_comboBox_unit_currentIndexChanged(int index);

    void on_comboBox_resolution_currentIndexChanged(int index);

    void on_toolButton_info_clicked();

    void on_toolButton_config_clicked();

private:
    Ui::FrmSensorDisplayDigital *ui;
    EDevice *m_edevice = nullptr;
    ESensor *m_esensor = nullptr;
    EDeviceParameter m_para;

    FrmAddSensor *m_frmAddSensor = nullptr;
    FrmDeviceConfig *m_frmDeviceConfig = nullptr;

    void initDisplay();
    void setValue();
};


#endif // FRMSENSORDISPLAYDIGITAL_H
