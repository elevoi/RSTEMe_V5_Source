#ifndef FRMSEARCHDEVICE_H
#define FRMSEARCHDEVICE_H

#include <QMainWindow>
#include <comm/econnection.h>
#include <device/edevice.h>
#include <device/edevicelist.h>
#include <device/edeviceinfo.h>
#include <device/edeviceinfolist.h>
#include <device/edevice.h>
#include <device/frmaddsensor.h>
#include <root/eaccountlist.h>
#include <QTimer>
#include <QVector>
#include <QToolButton>

namespace Ui {
class FrmSearchDevice;
}

class FrmSearchDevice : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmSearchDevice(QWidget *parent = nullptr);
    ~FrmSearchDevice();


    void setConnection(EConnection *connect);
    void search();

protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;

signals:
    void selectDevice(EDeviceInfo dev);

private slots:
    void on_error(EDevice::Error err);
    void on_reply(ERequestUnit request);

    void on_timerPoll();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Search_clicked();

    void on_pushButton_addNew_clicked();

private:
    Ui::FrmSearchDevice *ui;

    enum PollProcess{
        POLL_IDLE,
        POLL_POLL,
        POLL_UPDATE,
        POLL_NEXT,
        POLL_WAIT,
        POLL_FINISH
    };


    QSize m_sizeFormMain = QSize(1,1);
    QList<QString> m_comPort;
    //setbutton
    QToolButton *m_buttonDevice = nullptr;
    QList<QToolButton*> m_listButton;
    int m_buttonRow=0;

    EConnection *m_connection = nullptr;
    QTimer *m_timerPoll = nullptr;
    EDeviceInfo m_deviceInfo;
    EDeviceInfo m_deviceInfoNew;
    EDeviceInfoList m_edeviceInfoList;
    QList<EDeviceInfo> m_deviceSearchList;
    QList<EDeviceInfo> m_deviceFoundList;
    EDevice *m_edevice = nullptr;
    int m_edeviceInfoListCount = 0;
    FrmAddSensor *m_frmAddSensor=nullptr;

    PollProcess m_pollProcess = POLL_IDLE;

    int m_addressInc = 1;
    int m_timeScan = 0;
    uint64_t m_requestCount=0;
    uint64_t m_errorScan = 0;
    ERequestUnit m_requestUnit;
    bool m_newData = false;
    bool m_isStart = false;
    bool m_statusSearchNew = false;

    void init();
    void start();
    void finished();
    void loadTypeList(EDeviceInfo dev);
    void searchPoll();
    void searchNew();
    int getAddressInc(EDeviceInfo dev);
};

#endif // FRMSEARCHDEVICE_H
