#include "frmrepairmodbusconnection.h"
#include "ui_frmrepairmodbusconnection.h"
#include <QMessageBox>
#include <QVariant>

FrmRepairModbusConnection::FrmRepairModbusConnection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmRepairModbusConnection)
{
    ui->setupUi(this);

    m_sizeFormMain = this->size();
    m_sizePlainText = ui->plainTextEdit_Result->size();

    if(m_timerPoll)m_timerPoll->deleteLater();
    m_timerPoll = new QTimer(this);
    QObject::connect(m_timerPoll,&QTimer::timeout,this,&FrmRepairModbusConnection::on_timerPoll);
}

FrmRepairModbusConnection::~FrmRepairModbusConnection()
{
    delete ui;
}

void FrmRepairModbusConnection::setConnection(EConnection *connect)
{
    m_connection = connect;
    QObject::connect(m_connection,&EConnection::reply,this,&FrmRepairModbusConnection::on_reply);
    QObject::connect(m_connection,&EConnection::errorOccurred,this,&FrmRepairModbusConnection::on_errorOccurred);
}

void FrmRepairModbusConnection::closeEvent(QCloseEvent *event)
{
    if(m_connection){
        QObject::disconnect(m_connection,&EConnection::reply,this,&FrmRepairModbusConnection::on_reply);
        QObject::disconnect(m_connection,&EConnection::errorOccurred,this,&FrmRepairModbusConnection::on_errorOccurred);
    }
    if(m_timerPoll){
        m_timerPoll->deleteLater();
        m_timerPoll=nullptr;
    }
    event->accept();
}

void FrmRepairModbusConnection::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
       // Your code here.
    int del_h = this->size().height() - m_sizeFormMain.height();
    int del_w = this->size().width() - m_sizeFormMain.width();
    if(del_h<0)del_h=0;
    if(del_w<0)del_w=0;
    ui->plainTextEdit_Result->resize(m_sizePlainText.width()+del_w,m_sizePlainText.height()+del_h);
}

void FrmRepairModbusConnection::on_errorOccurred(ERequestUnit)
{
ui->plainTextEdit_Result->appendPlainText("Lỗi kết nối với cổng nối tiếp!!!");
}

void FrmRepairModbusConnection::on_reply(ERequestUnit request)
{
    if(request.slaveAddress()!=127)return;
    if(request.error()!=QModbusDevice::NoError){
        m_errorScan++;
        ui->label_ErrorScan->setText(QString::number(m_errorScan));
        return;
    }
    m_requestCount++;
    ui->label_Count->setText(QString::number(m_requestCount));
    m_newData = true;
    if((ui->spinBox_displayFrom->value()==0)&&(ui->spinBox_displayTo->value()==0))return;
    QString str="";
    str+= "Data: ";
    for(int i=0;i<QVariant(request.data().valueCount()).toInt();i++){
        if((i>=ui->spinBox_displayFrom->value())&&(i<=ui->spinBox_displayTo->value())){
            if(ui->radioButton_Hex->isChecked())str+=QString::number(i) + ":" + QString("%1").arg(request.data().value(i),4, 16, QLatin1Char( '0' ));
               else str+=QString::number(request.data().value(i));
            str+=" | ";
            }
    }
    ui->plainTextEdit_Result->appendPlainText(str);
    if(m_requestCount%50==0)ui->plainTextEdit_Result->clear();
}

void FrmRepairModbusConnection::on_timerPoll()
{
if(m_timeScan++>ui->spinBox_TimerScan->value()){
    this->start();
    }
}

void FrmRepairModbusConnection::on_pushButton_Start_clicked()
{
 if(m_isStart){
     this->stop();
     ui->pushButton_Start->setText("Bắt đầu");
     ui->pushButton_Start->setStyleSheet("");
     m_isStart = false;
 }
 else{
     this->start();
     m_requestCount=0;
     m_errorScan = 0;
     ui->label_ErrorScan->setText(QString::number(m_errorScan));
     ui->label_Count->setText(QString::number(m_requestCount));
     m_timerPoll->start(1);
     ui->pushButton_Start->setText("Dừng lại");
     ui->pushButton_Start->setStyleSheet("color: rgb(170, 0, 0);");
     m_isStart = true;
 }
}

void FrmRepairModbusConnection::start()
{
    if(!m_connection){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText("Lỗi cổng giao tiếp. Kiểm tra lại cáp và cổng truyền thông nối tiếp!");
        msg.setWindowTitle(this->windowTitle());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
        return;
    }

    auto _request = ERequestUnit::getRequestRead();
    m_isStart = true;
    auto _data = _request.data();
    if(ui->comboBox_typeRegister->currentIndex()==0)_data.setRegisterType(QModbusDataUnit::HoldingRegisters);
        else _data.setRegisterType(QModbusDataUnit::InputRegisters);
    _data.setStartAddress(ui->spinBox_StartRegister->value());
    _data.setValueCount(ui->spinBox_NumberRegister->value());
    _request.setData(_data);

    _request.setSlaveAddress(127);
    _request.setPriority(3);
    _request.setRetries(1);
    _request.setTimeout(ui->spinBox_TimerOut->value());

    m_newData = false;
    m_timeScan = 0;
    m_connection->sendRequest(_request);
}

void FrmRepairModbusConnection::stop()
{
m_timerPoll->stop();
}

