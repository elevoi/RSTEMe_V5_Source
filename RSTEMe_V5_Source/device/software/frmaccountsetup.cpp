#include "frmaccountsetup.h"
#include "ui_frmaccountsetup.h"
#include <QMessageBox>


FrmAccountSetup::FrmAccountSetup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmAccountSetup)
{
    ui->setupUi(this);
    m_currentAccount = EAccountList::currentAccount();
    tabRefresh();
}

FrmAccountSetup::~FrmAccountSetup()
{
    delete ui;
}

void FrmAccountSetup::on_toolBox_currentChanged(int index)
{
    m_tabCurrentIndex = index;
    tabRefresh();
}

void FrmAccountSetup::tabRefresh()
{
    switch (m_tabCurrentIndex) {
    case 0:
        ui->label_Info_Account->setText(m_currentAccount.account());
        ui->label_Info_Type->setText(m_currentAccount.typeText());
        break;
    case 1:
        ui->lineEdit_NewAccount->setText("");
        ui->lineEdit_NewPassword->setText("");
        ui->lineEdit_NewRePassword->setText("");
        break;
    case 2:
        ui->lineEdit_ChangePassword->setText("");
        ui->lineEdit_ChangeNewPassword->setText("");
        ui->lineEdit_ChangeRePassword->setText("");
        break;
    case 3:
        ui->comboBox_RemoveAccount->clear();
        m_accountList.load();
        foreach (auto var, m_accountList.accounts()) {
            ui->comboBox_RemoveAccount->addItem(var.account());
        }
        ui->lineEdit_RemovePassword->setText("");
        ui->lineEdit_RemoveRePassword->setText("");
        break;
    case 4:
        if(m_accountList.currentAccount().account()!="root")ui->pushButton_RemoveDefault->setEnabled(false);
        break;
    default:
        break;
    }
}


bool FrmAccountSetup::checkAccountText(QString str)
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setWindowIcon(this->windowIcon());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
//check space word
    if(str.count()<3){
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản phải có độ dài tối thiểu là 3 kí tự.");
        msg.exec();
        return false;
    }
//check space word
    foreach (auto var, str) {
        if(!var.isDigit()&&!var.isLetter()){
            msg.setText("Có lỗi xảy ra!\n  - Tài khoản chỉ bao gồm các kí tự chữ và số.");
            msg.exec();
            return false;
        }
    }
//Check first word
    if(!str.at(0).isLetter()){
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản phải bắt đầu bằng một kí tự từ A->Z hoặc a->z.");
        msg.exec();
        return false;
    }
    return true;
}

bool FrmAccountSetup::checkAccountAvailable(QString str)
{
    m_accountList.load();
    foreach (auto var, m_accountList.accounts()) {
        if(var.account()==str)return true;
    }
    return false;
}


bool FrmAccountSetup::checkPasswordText(QString str)
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setWindowIcon(this->windowIcon());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
//check space word
    foreach (auto var, str) {
        if(!var.isDigit()&&!var.isLetter()){
            msg.setText("Có lỗi xảy ra!\n  - Mật khẩu chỉ bao gồm các kí tự chữ và số.");
            msg.exec();
            return false;
        }
    }
    return true;
}

bool FrmAccountSetup::checkAccountType()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setWindowIcon(this->windowIcon());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
    switch(m_currentAccount.type()){
    case EAccountInfo::ACC_STUDENT:
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản \"Học sinh\" không được cấp quyền tạo tài khoản.");
        msg.exec();
        return false;
    case EAccountInfo::ACC_TEACHER:
        if(ui->comboBox_NewType->currentIndex()>0){
            msg.setText("Có lỗi xảy ra!\n  - Tài khoản \"Giáo viên\" chỉ được cấp quyền tạo tài khoản \"Học sinh\".");
            msg.exec();
            return false;
        }
        break;
    case EAccountInfo::ACC_ROOT:
        break;
    }
    return true;
}

bool FrmAccountSetup::checkRePassword(QString str1, QString str2)
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setWindowIcon(this->windowIcon());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
    if(str1!=str2){
        msg.setText("Có lỗi xảy ra!\n  - Mật khẩu nhập lại không giống nhau.");
        msg.exec();
        return false;
    }
    return true;
}

void FrmAccountSetup::creatAccount()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setWindowIcon(this->windowIcon());
    msg.setWindowIcon(this->windowIcon());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
//check acc
    if(!this->checkAccountText(ui->lineEdit_NewAccount->text()))return;
    if(this->checkAccountAvailable(ui->lineEdit_NewAccount->text())){
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản đã tồn tại.");
        msg.exec();
        return;
    }
//check pass
    if(!this->checkPasswordText(ui->lineEdit_NewPassword->text()))return;
//check rePass
    if(!this->checkPasswordText(ui->lineEdit_NewRePassword->text()))return;
//check type
    if(!this->checkAccountType())return;
    if(!checkRePassword(ui->lineEdit_NewPassword->text(),ui->lineEdit_NewRePassword->text()))return;

    EAccountInfo _acc;
    _acc.setAccount(ui->lineEdit_NewAccount->text());
    _acc.setPassword(ui->lineEdit_NewPassword->text());
    _acc.updateType((EAccountInfo::AccountType)ui->comboBox_NewType->currentIndex());
    m_accountList.insertAccount(_acc);
    this->tabRefresh();
    msg.setIcon(QMessageBox::Information);
    msg.setText("Đã tạo tài khoản thành công.");
    msg.exec();
}

void FrmAccountSetup::changePassword()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setWindowIcon(this->windowIcon());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
    //check oldPass
        if(!this->checkPasswordText(ui->lineEdit_ChangePassword->text()))return;
        if(ui->lineEdit_ChangePassword->text()!=m_currentAccount.password()){
            msg.setText("Có lỗi xảy ra!\n  - Mật khẩu cũ không đúng.");
            msg.exec();
            return;
            }
    //check pass
        if(!this->checkPasswordText(ui->lineEdit_ChangeNewPassword->text()))return;
    //check rePass
        if(!this->checkPasswordText(ui->lineEdit_ChangeRePassword->text()))return;
        if(!this->checkRePassword(ui->lineEdit_ChangeNewPassword->text(),ui->lineEdit_ChangeRePassword->text()))return;

    m_currentAccount.setPassword(ui->lineEdit_ChangeNewPassword->text());
    m_accountList.insertAccount(m_currentAccount);
    EAccountList::setCurrentAccount(m_currentAccount);
    this->tabRefresh();
    msg.setIcon(QMessageBox::Information);
    msg.setText("Đổi mật khẩu thành công.");
    msg.exec();
}

void FrmAccountSetup::removeAccount()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setWindowIcon(this->windowIcon());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
    if(ui->comboBox_RemoveAccount->currentText()==m_currentAccount.account()){
        msg.setText("Có lỗi xảy ra!\n  - Không thể xóa tài khoản đang sử dụng.");
        msg.exec();
        return;
    }
    //check pass
        if(!this->checkPasswordText(ui->lineEdit_RemovePassword->text()))return;
    //check rePass
        if(!this->checkPasswordText(ui->lineEdit_RemoveRePassword->text()))return;
        if(!this->checkRePassword(ui->lineEdit_RemovePassword->text(),ui->lineEdit_RemoveRePassword->text()))return;

    EAccountInfo _acc;
    _acc.setAccount(ui->comboBox_RemoveAccount->currentText());
    _acc.setPassword(ui->lineEdit_RemovePassword->text());
    if(!m_accountList.checkAccount(&_acc)){
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản không tồn tại hoặc mật khẩu không đúng.");
        msg.exec();
        return;
    }

    switch(m_currentAccount.type()){
    case EAccountInfo::ACC_STUDENT:
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản \"Học sinh\" không được cấp quyền xóa tài khoản.");
        msg.exec();
        return;
    case EAccountInfo::ACC_TEACHER:
        if((int)_acc.type()>0){
            msg.setText("Có lỗi xảy ra!\n  - Tài khoản \"Giáo viên\" chỉ được cấp quyền xóa tài khoản \"Học sinh\".");
            msg.exec();
            return;
        }
        break;
    case EAccountInfo::ACC_ROOT:
        break;
    }
    m_accountList.removeAccount(_acc);
    m_accountList.removeRecent(_acc);
    this->tabRefresh();
    msg.setIcon(QMessageBox::Information);
    msg.setText("Đã xóa tài khoản.");
    msg.exec();
}
void FrmAccountSetup::on_pushButton_Cancel_clicked()
{
    this->close();
}


void FrmAccountSetup::on_pushButton_ChangePassword_NewCreat_clicked()
{
    this->creatAccount();
}


void FrmAccountSetup::on_pushButton_ChangePassword_clicked()
{
    this->changePassword();
}


void FrmAccountSetup::on_pushButton_Remove_clicked()
{
    this->removeAccount();
}


void FrmAccountSetup::on_comboBox_RemoveAccount_currentIndexChanged(int)
{
    ui->lineEdit_RemovePassword->setText("");
    ui->lineEdit_RemoveRePassword->setText("");
}


void FrmAccountSetup::on_pushButton_RemoveDefault_clicked()
{
    if(m_accountList.currentAccount().account()!="root")return;
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có chắc chắn muốn thiết lập các tài khoản về mặc định không?");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() == QMessageBox::Yes) {
         m_accountList.reset();
         msg.setStandardButtons(QMessageBox::Ok);
         msg.setText("Đã thiết lập các tài khoản về mặc định.");
         msg.setWindowTitle(this->windowTitle());
         msg.setParent(nullptr);
         msg.setIcon(QMessageBox::Information);
         msg.setWindowIcon(this->windowIcon());
         msg.exec();
     }
}

