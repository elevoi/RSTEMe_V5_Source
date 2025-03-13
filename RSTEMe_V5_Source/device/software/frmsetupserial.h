#ifndef FRMSETUPSERIAL_H
#define FRMSETUPSERIAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <comm/econnection.h>
#include <device/edevice.h>
#include "device/edeviceinfolist.h"
#include <elog.h>
#include <QTimer>
#include <QVector>

namespace Ui {
class FrmSetupSerial;
}

class FrmSetupSerial : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmSetupSerial(QWidget *parent = nullptr);
    ~FrmSetupSerial();

    enum SetupSnPoll{
        SSP_Idle,
        SSP_Write,
        SSP_Wait
    };


    void setConnection(EConnection *connect);

private slots:
    void on_reply(ERequestUnit request);
    void on_errorOccurred(ERequestUnit request);
    void on_timerPoll();

    void on_spinBox_versioneDevice_valueChanged(int arg1);

    void on_comboBox_groupDevice_activated(int index);

    void on_comboBox_typeDevice_activated(int index);

    void on_lineEdit_id_textEdited(const QString &arg1);

    void on_pushButton_Cancel_clicked();

    void on_comboBox_groupDevice_currentIndexChanged(int index);

    void on_lineEdit_serialNumber_editingFinished();

    void on_pushButton_writeSerial_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::FrmSetupSerial *ui;
    EDeviceInfoList m_edeviceInfoList;
    EConnection *m_connection = nullptr;
    QTimer *m_timerPoll=nullptr;


    int m_timerOut = 0;
    bool m_errorRequest = false;
    bool m_newData = false;
    int m_serialNumber=0;
    bool m_statusWriteSerial = false;
    int m_requestId = 0;
    ERequestUnit m_request;
    SetupSnPoll m_setupSnPoll = SSP_Idle;

    void init();
    bool checkTimerOut();
    bool checkData();
    void updateSerialNumber();
    bool loadDeviceInfo();

    void poll();
    void writeSerialNumber();
};

#endif // FRMSETUPSERIAL_H
