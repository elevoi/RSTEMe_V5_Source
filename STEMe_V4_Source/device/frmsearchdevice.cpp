#include "frmsearchdevice.h"
#include "ui_frmsearchdevice.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <elog.h>
#include <QtSerialPort/QSerialPortInfo>
#include <device/frmaddsensor.h>
#include <QVector>


FrmSearchDevice::FrmSearchDevice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmSearchDevice)
{
    ui->setupUi(this);
    this->init();
}

FrmSearchDevice::~FrmSearchDevice()
{
    delete ui;
}

void FrmSearchDevice::init()
{
    ui->pushButton_addNew->setEnabled(false);
    ui->frame->hide();
    m_sizeFormMain = this->size();
    if(m_timerPoll)m_timerPoll->deleteLater();
    m_timerPoll = new QTimer(this);
    QObject::connect(m_timerPoll,&QTimer::timeout,this,&FrmSearchDevice::on_timerPoll);

}

void FrmSearchDevice::setConnection(EConnection *connect)
{
    m_connection = connect;
    QObject::connect(m_connection,&EConnection::reply,this,&FrmSearchDevice::on_reply);
}

void FrmSearchDevice::search()
{
this->start();
}

void FrmSearchDevice::closeEvent(QCloseEvent *event)
{
    if(m_connection){
        QObject::disconnect(m_connection,&EConnection::reply,this,&FrmSearchDevice::on_reply);
    }
    if(m_timerPoll){
        m_timerPoll->deleteLater();
        m_timerPoll=nullptr;
    }
    if(m_frmAddSensor)delete m_frmAddSensor;
    event->accept();
}

void FrmSearchDevice::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
       // Your code here.
  //  int del_h = this->size().height() - m_sizeFormMain.height();
   // int del_w = this->size().width() - m_sizeFormMain.width();
   // if(del_h<0)del_h=0;
    // if(del_w<0)del_w=0;
}

void FrmSearchDevice::on_error(EDevice::Error err)
{
    ELog::log(err);
if(err == EDevice::NoError||err == EDevice::ErrorRequestData)m_errorScan = false;
else m_errorScan = true;
m_statusSearchNew = false;
}

void FrmSearchDevice::on_reply(ERequestUnit request)
{
    if(request.slaveAddress()!=127)return;
    if(!m_statusSearchNew)return;
    if(request.error()!=QModbusDevice::NoError)return;
    m_newData = true;
    m_timerPoll->stop();
    int _serial = (request.data().value(0)<<16)&0xFFFF0000;
    _serial |= request.data().value(1)&0xFFFF;
    FrmAddSensor sensor;
    m_deviceInfo = sensor.device(_serial);
    m_deviceInfo.setAddress(EDeviceInfoList::getAddressInc());
    ELog::log(EDeviceInfo::serialHex(_serial));
    this->loadTypeList(m_deviceInfo);
    m_statusSearchNew = false;
}


void FrmSearchDevice::on_timerPoll()
{
  this->searchPoll();
}





void FrmSearchDevice::finished()
{
    m_timerPoll->stop();
    this->searchNew();
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    if(m_listButton.count()>0){
        QString str = "Đã tìm thấy " + QString::number(m_listButton.count()) + " thiết bị\nNhấn chuột trái vào thiết bị để kết nối.";
        msg.setText(str);
        msg.setIcon(QMessageBox::Information);
        }
        else{
            msg.setText("Không tìm thấy thiết bị!");
            msg.setIcon(QMessageBox::Warning);
        }
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
    ui->pushButton_Search->setEnabled(true);
}

void FrmSearchDevice::on_pushButton_Cancel_clicked()
{
    this->close();
}


void FrmSearchDevice::on_pushButton_Search_clicked()
{
    this->start();
}

void FrmSearchDevice::loadTypeList(EDeviceInfo dev)
{
        int _x=5,_y=5,_w=200,_h=40;
        //check
        foreach (auto var, m_deviceFoundList) {
            if(var.serial()==dev.serial())return;
        }
        m_deviceFoundList.append(dev);
        _w=ui->listWidget->width()-(_x*2);
        m_buttonDevice = new QToolButton(ui->listWidget);
        m_listButton.append(m_buttonDevice);
        QString _style = "QToolButton#buttonSensor{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(250, 255, 255);\
                        border: none;\
                        border-style: outset;\
                        border-width: 1px;\
                        border-radius: 10px;}\
                        QToolButton#buttonSensor:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }";
        m_buttonDevice->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        QString name = dev.name()+"("+dev.serialHex()+")";
        bool ok;
        m_edeviceInfoList.getDevice(dev.serial(),&ok);
        if(!ok){
            name += " -> Thiết bị mới!)";
            m_deviceInfoNew = dev;
            ui->pushButton_addNew->setEnabled(true);
        }
        m_buttonDevice->setText(name);
        QIcon my_icon;
        my_icon.addPixmap(QPixmap(dev.icon()), QIcon::Normal);
        my_icon.addPixmap(QPixmap(dev.iconOn()), QIcon::Active);
        m_buttonDevice->setIcon(my_icon);
        m_buttonDevice->setAutoRaise(true);
        m_buttonDevice->setIconSize(QSize(30,30));
        m_buttonDevice->setObjectName("buttonSensor");
        m_buttonDevice->setStyleSheet(_style);
        _y = m_buttonRow*(_x+_h)+_y;
        m_buttonRow++;
        m_buttonDevice->setGeometry(QRect(_x,_y,_w,_h));
        m_buttonDevice->setToolTip("Nhấn chuột trái để kết nối thiết bị.");
        m_buttonDevice->show();
        QObject::connect(m_buttonDevice,&QToolButton::clicked,this,[dev,this](){
            emit this->selectDevice(dev);
        });
}
void FrmSearchDevice::start()
{
    if(!m_connection){
        QMessageBox  msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText("Lỗi cổng giao tiếp!");
        msg.setWindowTitle(this->windowTitle());
        msg.setParent(nullptr);
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowIcon(this->windowIcon());
        msg.exec();
        return;
    }
    if(!m_connection->isConnect())return;
    m_edeviceInfoList.load(false);
    m_deviceSearchList.clear();
    foreach (EDeviceInfo var, m_edeviceInfoList.deviceList(EAccountList::currentAccount())) {
        if(var.serial(EDeviceInfo::SERIAL_GROUP)>0){
            m_deviceSearchList.append(var);
        }
    }
    foreach (QToolButton *var, m_listButton) {
        m_listButton.removeOne(var);
        delete var;
    }
    m_deviceFoundList.clear();
    m_edeviceInfoListCount = 0;
    m_statusSearchNew = false;
    m_buttonRow = 0;
    m_pollProcess = POLL_IDLE;
    m_addressInc = 1;
    ui->pushButton_addNew->setEnabled(false);
    ui->pushButton_Search->setEnabled(false);
    m_timerPoll->start(1);

    //set progress
    ui->progressBar_search->setMinimum(0);
    ui->progressBar_search->setMaximum(m_deviceSearchList.count());
    ui->frame->show();
}
void FrmSearchDevice::searchPoll()
{
switch(m_pollProcess){
    case PollProcess::POLL_IDLE:
        if(m_edeviceInfoListCount<m_deviceSearchList.count()){
            m_deviceInfo = m_deviceSearchList.at(m_edeviceInfoListCount);
            m_edeviceInfoListCount++;
            ui->label_search->setText("searching for (@" + m_deviceInfo.serialHex() + ") "+m_deviceInfo.name()+"...");
            ui->progressBar_search->setValue(m_edeviceInfoListCount);
            //Check deviceOnline
            auto _listDeviceOnline = EDeviceList::deviceOnlineList();
            foreach (auto var, _listDeviceOnline) {
                if(var->deviceInfo()==m_deviceInfo){
                    if(var->isStart()==EDevice::StStarted)m_pollProcess = POLL_UPDATE;
                    return;
                }
            }
            m_edevice = new EDevice(m_connection);
            QObject::connect(m_edevice,&EDevice::error,this,&FrmSearchDevice::on_error);
            m_deviceInfo.setAddress(getAddressInc(m_deviceInfo));
            m_edevice->setDeviceInfo(m_deviceInfo);
            m_edevice->start(false);
            m_timeScan = 0;
            m_errorScan = false;
            m_pollProcess = POLL_POLL;
            }
            else{
               m_pollProcess = POLL_FINISH;
                }
        break;
    case PollProcess::POLL_POLL:
        if(m_edevice->isStart()==EDevice::StStarted)m_pollProcess = POLL_UPDATE;
        //Error set address
        if(m_errorScan)m_pollProcess = POLL_NEXT;
        //timeOut
        if(m_timeScan++>1000)m_pollProcess = POLL_NEXT;
        break;
    case PollProcess::POLL_UPDATE:
        m_edeviceInfoList.replaceDevice(m_deviceInfo);
        this->loadTypeList(m_deviceInfo);
        m_pollProcess = POLL_NEXT;
        break;
    case PollProcess::POLL_NEXT:
        if(m_edevice){
         //   QObject::disconnect(m_edevice,&EDevice::result,this,&FrmSearchDevice::on_result);
            QObject::disconnect(m_edevice,&EDevice::error,this,&FrmSearchDevice::on_error);
            m_edevice->stop();
            m_edevice->deleteLater();
            m_edevice = nullptr;
            }
        m_timeScan = 0;
        m_pollProcess = POLL_WAIT;
        break;
    case PollProcess::POLL_WAIT:
        if(m_timeScan++>10)m_pollProcess = POLL_IDLE;
        break;
    case PollProcess::POLL_FINISH:
        this->finished();
        ui->frame->hide();
        break;
}
}

void FrmSearchDevice::searchNew()
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
    m_statusSearchNew = true;
    auto _request = ERequestUnit::getRequestRead();
    auto _data = _request.data();
    _data.setRegisterType(QModbusDataUnit::HoldingRegisters);
    _data.setStartAddress(EDeviceParameter::HOLDING_REG_OFFSET);
    _data.setValueCount(2);
    _request.setData(_data);

    _request.setSlaveAddress(127);
    _request.setPriority(1);
    _request.setRetries(1);
    _request.setTimeout(300);

    m_isStart = true;
    m_newData = false;
    m_timeScan = 0;
    m_connection->sendRequest(_request);

}

int FrmSearchDevice::getAddressInc(EDeviceInfo dev)
{
    if(dev.address()<127)return dev.address();
    int i=0;
    m_edeviceInfoList.load(false);
    for(i=0;i<m_edeviceInfoList.deviceList().count();i++) {
        if(m_addressInc == m_edeviceInfoList.deviceList().at(i).address()){
            m_addressInc++;
            i=-1;
            }
    }
    return m_addressInc++;
}


void FrmSearchDevice::on_pushButton_addNew_clicked()
{
    if(m_frmAddSensor)delete m_frmAddSensor;
    m_frmAddSensor = new FrmAddSensor(this,m_deviceInfoNew);
    m_frmAddSensor->show();
}

