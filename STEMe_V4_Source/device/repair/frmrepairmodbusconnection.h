#ifndef FRMREPAIRMODBUSCONNECTION_H
#define FRMREPAIRMODBUSCONNECTION_H

#include <QMainWindow>
#include <comm/econnection.h>
#include <device/edevice.h>
#include <device/edeviceinfo.h>
#include <device/edeviceinfolist.h>
#include <device/edevice.h>
#include <QTimer>
#include <QVector>

namespace Ui {
class FrmRepairModbusConnection;
}

class FrmRepairModbusConnection : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmRepairModbusConnection(QWidget *parent = nullptr);
    ~FrmRepairModbusConnection();


    void setConnection(EConnection *connect);




protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent*) override;

private slots:
    void on_reply(ERequestUnit request);
    void on_errorOccurred(ERequestUnit request);
    void on_timerPoll();
    void on_pushButton_Start_clicked();

private:
    Ui::FrmRepairModbusConnection *ui;
    QSize m_sizeFormMain = QSize(1,1);
    QSize m_sizePlainText = QSize(1,1);

    EConnection *m_connection = nullptr;
    QTimer *m_timerPoll = nullptr;
    int m_timeScan = 0;
    uint64_t m_requestCount=0;
    uint64_t m_errorScan = 0;
    bool m_isStart = false;
    bool m_newData = false;

    void start();
    void stop();

};

#endif // FRMREPAIRMODBUSCONNECTION_H
