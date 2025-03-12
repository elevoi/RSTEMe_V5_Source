#ifndef FRMACCOUNTSETUP_H
#define FRMACCOUNTSETUP_H

#include <QMainWindow>
#include <QVariant>
#include <root/eaccountlist.h>

namespace Ui {
class FrmAccountSetup;
}

class FrmAccountSetup : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmAccountSetup(QWidget *parent = nullptr);
    ~FrmAccountSetup();

private slots:
    void on_toolBox_currentChanged(int index);

    void on_pushButton_Cancel_clicked();

    void on_pushButton_ChangePassword_NewCreat_clicked();

    void on_pushButton_ChangePassword_clicked();

    void on_pushButton_Remove_clicked();

    void on_comboBox_RemoveAccount_currentIndexChanged(int index);

    void on_pushButton_RemoveDefault_clicked();

private:
    Ui::FrmAccountSetup *ui;

    EAccountInfo m_currentAccount;
    EAccountList m_accountList;
    int m_tabCurrentIndex = 0;

    void tabRefresh();
    bool checkAccountText(QString str);
    bool checkAccountAvailable(QString str);
    bool checkPasswordText(QString str);
    bool checkAccountType();
    bool checkRePassword(QString str1,QString str2);
    void creatAccount();
    void changePassword();
    void removeAccount();
};

#endif // FRMACCOUNTSETUP_H
