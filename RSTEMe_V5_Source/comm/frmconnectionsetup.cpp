#include "frmconnectionsetup.h"
#include "ui_frmconnectionsetup.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>


FrmConnectionSetup::FrmConnectionSetup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmConnectionSetup)
{
    ui->setupUi(this);
    ui->pushButton_ConnectComPort->setEnabled(false);
    this->searchComPort();
}

FrmConnectionSetup::~FrmConnectionSetup()
{
    delete ui;
}

void FrmConnectionSetup::setConnection(EConnection *connect)
{
    if(m_connection){
        QObject::disconnect(m_connection,&EConnection::connectChanged,this,&FrmConnectionSetup::on_connectChanged);
    }
    m_connection = connect;
    QObject::connect(m_connection,&EConnection::connectChanged,this,&FrmConnectionSetup::on_connectChanged);
}

void FrmConnectionSetup::on_connectChanged(bool status)
{
    if(m_requestId==0)return;
    m_requestId=0;
    if(status){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
        msg.setText("Đã kết nối cổng nối tiếp. Bạn có muốn lưu lại tên cổng không?");
        msg.setWindowTitle(this->windowTitle());
        msg.setWindowIcon(this->windowIcon());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
        if (msg.result() == QMessageBox::Yes) {
            m_connectionInfo.setModbusPort(m_comPort.at(ui->comboBox_ComPort->currentIndex()));
            m_connectionInfo.save();
            emit this->stateChange(ETypeDef::StateChange::CONNECTION);
        }
        this->close();
    }
    else{
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText("Không kết nối được cổng nối tiếp!");
        msg.setWindowTitle(this->windowTitle());
        msg.setWindowIcon(this->windowIcon());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
    }
}

void FrmConnectionSetup::on_pushButton_Active_clicked()
{
    this->searchComPort();
}

void FrmConnectionSetup::searchComPort()
{
    //Com port
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();
    QList<QSerialPortInfo>::iterator p;
    QString str = "";
    ui->comboBox_ComPort->clear();
    m_comPort.clear();
    for (p = list.begin(); p != list.end(); ++p)
        {
        if(p->portName()!="COM1"){
            ui->comboBox_ComPort->addItem(p->description()+"("+p->portName()+")");
            m_comPort.append(p->portName());
            }
            else str = p->description()+"("+p->portName()+")";
        }
   if(str!="") {
       ui->comboBox_ComPort->addItem(str);
       m_comPort.append("COM1");
   }
   if(m_comPort.count()>0)ui->pushButton_ConnectComPort->setEnabled(true);
}

void FrmConnectionSetup::on_pushButton_ConnectComPort_clicked()
{
    if(!m_connection)return;
    auto para = m_connection->serialPort();
    para.port = m_comPort.at(ui->comboBox_ComPort->currentIndex());
    m_requestId = m_connection->setConnect(para);
}


void FrmConnectionSetup::on_pushButton_Cancel_clicked()
{
    this->close();
}

