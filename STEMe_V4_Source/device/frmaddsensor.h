#ifndef FRMADDSENSOR_H
#define FRMADDSENSOR_H

#include <QMainWindow>
#include <device/edeviceinfo.h>
#include <device/edeviceinfolist.h>
#include <QMessageBox>
#include <device/frmdeviceicon.h>



namespace Ui {
class FrmAddSensor;
}

class FrmAddSensor : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmAddSensor(QWidget *parent = nullptr);
    FrmAddSensor(QWidget *parent,EDeviceInfo dev);
    ~FrmAddSensor();

    bool addNewDevice();
    EDeviceInfo device(int serial);
signals:
    void setup(EDeviceInfo info);

private slots:
    void on_pushButton_Cancel_clicked();
    void on_pushButton_addDevice_clicked();

    void on_comboBox_groupDevice_activated(int index);

    void on_comboBox_typeDevice_activated(int index);

    void on_spinBox_versioneDevice_valueChanged(int arg1);

    void on_lineEdit_serialNumber_textEdited(const QString &arg1);

    void on_comboBox_groupDevice_currentIndexChanged(int index);

    void on_comboBox_typeDevice_currentTextChanged(const QString &arg1);

    void on_pushButton_writeFile_clicked();

    void on_pushButton_openFile_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::FrmAddSensor *ui;
    EDeviceInfo m_deviceInfo;
    EDeviceInfoList m_edeviceInfoList;
    QMessageBox *m_msg = nullptr;
    FrmDeviceIcon *m_frmDeviceIcon = nullptr;

    QList<int> m_toolDisplaySensor = {0x00080000,0x000D0000,0x00090000,0x000A0000,0x000B0000,0x000C0000};
    QList<int> m_toolPracticeSensor = {};
    QList<int> m_toolControlSensor = {0x00070000};

    QList<int> m_toolDisplayModule;
    QList<int> m_toolPracticeModule;
    QList<int> m_toolControlModule;

    QList<int> m_toolDisplaySystem;
    QList<int> m_toolPracticeSystem;
    QList<int> m_toolControlSystem;

    int m_serialnumber=0;

    //resize
    QSize m_sizeGroupDescription;
    QSize m_sizeEditDescription;
    QSize m_sizeGroupInfo;

    QRect m_pointAddDevice;
    QRect m_pointCancel;
    QRect m_pointSave;
    QSize m_deviceSetup;


    void resizeEvent(QResizeEvent*);

    void init();
    bool getDevice(EDeviceInfo *dev);
    void setIcon(EDeviceInfo *dev);
    void showMessageBox(QString text, QMessageBox::Icon icon);
    void updateSerialNumber();
    void loadDeviceInfo();
    void setTool(EDeviceInfo *dev);

};

#endif // FRMADDSENSOR_H
