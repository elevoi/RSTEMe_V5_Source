#ifndef FRMCONNECTIONSETUP_H
#define FRMCONNECTIONSETUP_H

#include <QMainWindow>
#include <comm/econnection.h>
#include <comm/econnectioninfo.h>
#include "etypedef.h"

namespace Ui {
class FrmConnectionSetup;
}

class FrmConnectionSetup : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmConnectionSetup(QWidget *parent = nullptr);
    ~FrmConnectionSetup();

    void setConnection(EConnection *connect);

signals:
    void stateChange(ETypeDef::StateChange state);

private slots:
    void on_connectChanged(bool status);
    void on_pushButton_Active_clicked();

    void on_pushButton_ConnectComPort_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::FrmConnectionSetup *ui;
    EConnection *m_connection = nullptr;
    EConnectionInfo m_connectionInfo;

    QList<QString> m_comPort;

    int m_requestId = 0;
    void searchComPort();
};

#endif // FRMCONNECTIONSETUP_H
