#include "frmlogin.h"
#include "ui_frmlogin.h"
#include <QMessageBox>
#include <QtSerialPort/QSerialPortInfo>

FrmLogin::FrmLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmLogin)
{
    ui->setupUi(this);
    //m_eaccountList.clear();
    //m_eaccountList.clearRecent();
    this->init();
}

FrmLogin::~FrmLogin()
{
    delete ui;
}

void FrmLogin::init()
{
    //check account list
        if(m_eaccountList.isEmpty())m_eaccountList.reset();
    //update combobox
        ui->comboBox_Account->clear();
        QList<EAccountInfo> _recent = m_eaccountList.getRecent();
        for(int i=0;i<_recent.count();i++){
            ui->comboBox_Account->addItem(_recent.at(i).account());
            }
}

bool FrmLogin::checkAccountText()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
    QString _str = ui->comboBox_Account->currentText();
//check space word
    if(_str.count()<3){
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản phải có độ dài tối thiểu là 3 kí tự.");
        msg.exec();
        return false;
    }
//check space word
    foreach (auto var, _str) {
        if(!var.isDigit()&&!var.isLetter()){
            msg.setText("Có lỗi xảy ra!\n  - Tài khoản chỉ bao gồm các kí tự chữ và số.");
            msg.exec();
            return false;
        }
    }
//Check first word
    if(!_str.at(0).isLetter()){
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản phải bắt đầu bằng một kí tự từ A->Z hoặc a->z.");
        msg.exec();
        return false;
    }
    return true;
}

bool FrmLogin::checkPasswordText()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());
    QString _str = ui->lineEdit_Password->text();
//check space word
    foreach (auto var, _str) {
        if(!var.isDigit()&&!var.isLetter()){
            msg.setText("Có lỗi xảy ra!\n  - Mật khẩu chỉ bao gồm các kí tự chữ và số.");
            msg.exec();
            return false;
        }
    }
    return true;
}

bool FrmLogin::checkAccount()
{
    if(!checkAccountText())return false;
    if(!checkPasswordText())return false;
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowIcon(this->windowIcon());

    m_eaccountInfo.setAccount(ui->comboBox_Account->currentText());
    m_eaccountInfo.setPassword(ui->lineEdit_Password->text());
    //check acc
    if(m_eaccountList.findAccount(m_eaccountInfo)<0){
        msg.setText("Có lỗi xảy ra!\n  - Tài khoản không tồn tại.");
        msg.exec();
        return false;
        }
    //check pass
    if(!m_eaccountList.checkAccount(&m_eaccountInfo)){
        msg.setText("Có lỗi xảy ra!\n  - Mật khẩu không đúng.");
        msg.exec();
        return false;
        }
    return true;
}


void FrmLogin::on_pushButton_Login_clicked()
{
if(!checkAccount())return;
//update recent and current acc
EAccountList::setCurrentAccount(m_eaccountInfo);
m_eaccountList.updateRecent(m_eaccountInfo);

if(m_mainWindow){
    m_mainWindow->deleteLater();
    m_mainWindow = nullptr;
    }
m_mainWindow = new MainWindow();
QObject::connect(m_mainWindow,&MainWindow::login,this,&FrmLogin::on_login);
m_mainWindow->show();
this->close();
}

void FrmLogin::on_login()
{
if(m_mainWindow){
    m_mainWindow->deleteLater();
    m_mainWindow = nullptr;
    }
this->init();
this->show();
}


void FrmLogin::on_comboBox_Account_currentIndexChanged(int)
{
ui->lineEdit_Password->clear();
}

