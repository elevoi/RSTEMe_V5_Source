#ifndef FRMLOGIN_H
#define FRMLOGIN_H

#include <QMainWindow>
#include <QVariant>
#include <root/eaccountlist.h>
#include "mainwindow.h"

namespace Ui {
class FrmLogin;
}

class FrmLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmLogin(QWidget *parent = nullptr);
    ~FrmLogin();

private slots:
    void on_pushButton_Login_clicked();
    void on_login();

    void on_comboBox_Account_currentIndexChanged(int index);
private:
    Ui::FrmLogin *ui;
    MainWindow *m_mainWindow = nullptr;

    EAccountList m_eaccountList;
    EAccountInfo m_eaccountInfo;
    QList<QString> m_comPort;


    void init();
    bool checkAccountText();
    bool checkPasswordText();
    bool checkAccount();
};

#endif // FRMLOGIN_H
