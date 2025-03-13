#include "frmdeviceselection.h"
#include "ui_frmdeviceselection.h"
#include <QDebug>
#include "device/frmaddsensor.h"
#include "root/eaccountlist.h"


FrmDeviceSelection::FrmDeviceSelection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDeviceSelection)
{
    ui->setupUi(this);
}


FrmDeviceSelection::~FrmDeviceSelection()
{
    delete ui;
}

void FrmDeviceSelection::setDevice(EDeviceInfo dev)
{
    m_deviceInfo = dev;
    this->setWindowTitle(dev.name() + "(@" + dev.serialHex() + ")");
    ui->label_Name->setText(dev.name());
    this->init();
    this->loadToolDisplay();
    this->loadToolPractice();
    this->loadToolControl();
}


void FrmDeviceSelection::closeEvent(QCloseEvent *event)
{
event->accept();
}
void FrmDeviceSelection::init()
{
    m_sizeWindow=this->size();
     m_sizeGroupDisplay=ui->groupBox_Display->size();
     m_sizeListDisplay=ui->listWidget_toolDisplay->size();

     m_sizeListControl = ui->listWidget_toolControl->geometry();
     m_rectGroupControl = ui->groupBox_Control->geometry();
     m_rectPushCancel = ui->pushButton_cancel->geometry();

}

void FrmDeviceSelection::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
       // Your code here.
    int del_h = this->size().height() - m_sizeWindow.height();
    int del_w = this->size().width() - m_sizeWindow.width();

    ui->groupBox_Display->resize(m_sizeGroupDisplay.width()+del_w,m_sizeGroupDisplay.height()+del_h);
    ui->listWidget_toolDisplay->resize(m_sizeListDisplay.width()+del_w,m_sizeListDisplay.height()+del_h);

    ui->groupBox_Control->setGeometry(QRect(m_rectGroupControl.x(),m_rectGroupControl.y()+del_h,m_rectGroupControl.width()+del_w,m_rectGroupControl.height()+del_h));
    ui->listWidget_toolControl->setGeometry(QRect(m_sizeListControl.x(),m_sizeListControl.y()+del_h,m_sizeListControl.width()+del_w,m_sizeListControl.height()+del_h));

    ui->pushButton_cancel->setGeometry(QRect(m_rectPushCancel.x()+del_w,m_rectPushCancel.y(),m_rectPushCancel.width(),m_rectPushCancel.height()));
}

void FrmDeviceSelection::showDevice(EDeviceInfo dev)
{
    emit this->selectDevice(dev);
    this->close();
}


void FrmDeviceSelection::loadToolDisplay()
{
    QList<EDeviceInfo> _ldev;
    m_deviceInfoList.load(false);
    FrmAddSensor sensor;
    foreach (int var, m_deviceInfo.toolDisplay()) {
        auto _dev = sensor.device(var);
        foreach (auto var, m_deviceInfoList.deviceList())if(var==_dev)_dev = var;
        if(_dev.account()<=(int)EAccountList::currentAccount().type())_ldev.append(_dev);
        }
    int _row=0,_colum=0;
    foreach (QToolButton *var, m_buttonListToolDisplay) {
            m_buttonListToolDisplay.removeOne(var);
            delete var;
        }
    for(int i=0;i<_ldev.count();i++){
        int _x,_y,_w=100,_h=75,_left=5,_top=1;
        QToolButton *_button = new QToolButton(ui->listWidget_toolDisplay);
        m_buttonListToolDisplay.append(_button);
        QString _style = "QToolButton#buttonSensor{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(250, 255, 255);\
                        border: none;\
                        border-color: rgb(210, 210, 210);\
                        border-style: outset;\
                        border-width: 1px;\
                        border-radius: 15px;}\
                        QToolButton#buttonSensor:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }";
        _button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        _button->setText(_ldev.at(i).name());
        QIcon my_icon;
        my_icon.addPixmap(QPixmap(_ldev.at(i).icon()), QIcon::Normal);
        my_icon.addPixmap(QPixmap(_ldev.at(i).iconOn()), QIcon::Active);
        _button->setIcon(my_icon);
        _button->setAutoRaise(true);
        _button->setIconSize(QSize(40,40));
        _button->setObjectName("buttonSensor");
        _button->setStyleSheet(_style);
        _button->setFont(QFont("Sequoe UI", 8, QFont::Bold));
        _x = _colum*(_left+_w)+_left;
        _y = _row*(_top+_h)+_top;
        _button->setGeometry(QRect(_x,_y,_w,_h));
        _button->show();
        EDeviceInfo dev = _ldev.at(i);
        QObject::connect(_button,&QToolButton::clicked,this,[dev,this](){
            this->showDevice(dev);
        });
        if(++_colum>5){
            _colum=0;
            _row++;
            }
        }
}

void FrmDeviceSelection::loadToolPractice()
{
    QList<EDeviceInfo> _ldev;
    m_deviceInfoList.load(false);
    FrmAddSensor sensor;
    foreach (int var, m_deviceInfo.toolPractice()) {
        auto _dev = sensor.device(var);
        foreach (auto var, m_deviceInfoList.deviceList())if(var==_dev)_dev = var;
        if(_dev.account()<=(int)EAccountList::currentAccount().type())_ldev.append(_dev);
        }
    int _row=0,_colum=0;
    foreach (QToolButton *var, m_buttonListToolPractice) {
            m_buttonListToolPractice.removeOne(var);
            delete var;
        }
    for(int i=0;i<_ldev.count();i++){
        int _x,_y,_w=120,_h=75,_left=5,_top=1;
        QToolButton *_button = new QToolButton(ui->listWidget_toolPractice);
        m_buttonListToolPractice.append(_button);
        QString _style = "QToolButton#buttonSensor{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(250, 255, 255);\
                        border: none;\
                        border-color: rgb(210, 210, 210);\
                        border-style: outset;\
                        border-width: 1px;\
                        border-radius: 15px;}\
                        QToolButton#buttonSensor:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }";
        _button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        _button->setText(_ldev.at(i).name());
        QIcon my_icon;
        my_icon.addPixmap(QPixmap(_ldev.at(i).icon()), QIcon::Normal);
        my_icon.addPixmap(QPixmap(_ldev.at(i).iconOn()), QIcon::Active);
        _button->setIcon(my_icon);
        _button->setAutoRaise(true);
        _button->setIconSize(QSize(40,40));
        _button->setObjectName("buttonSensor");
        _button->setStyleSheet(_style);
        _button->setFont(QFont("Sequoe UI", 8, QFont::Bold));
        _x = _colum*(_left+_w)+_left;
        _y = _row*(_top+_h)+_top;
        _button->setGeometry(QRect(_x,_y,_w,_h));
        _button->show();
        EDeviceInfo dev = _ldev.at(i);
        QObject::connect(_button,&QToolButton::clicked,this,[dev,this](){
            this->showDevice(dev);
        });
        if(++_colum>5){
            _colum=0;
            _row++;
            }
        }
}

void FrmDeviceSelection::loadToolControl()
{
    QList<EDeviceInfo> _ldev;
    m_deviceInfoList.load(false);
    FrmAddSensor sensor;
    foreach (int var, m_deviceInfo.toolControl()) {
        auto _dev = sensor.device(var);
        foreach (auto var, m_deviceInfoList.deviceList())if(var==_dev)_dev = var;
        if(_dev.account()<=(int)EAccountList::currentAccount().type())_ldev.append(_dev);
    }
    int _row=0,_colum=0;
    foreach (QToolButton *var, m_buttonListToolControl) {
            m_buttonListToolControl.removeOne(var);
            delete var;
        }
    for(int i=0;i<_ldev.count();i++){
        int _x,_y,_w=100,_h=75,_left=10,_top=10;
        QToolButton *_button = new QToolButton(ui->listWidget_toolControl);
        m_buttonListToolControl.append(_button);
        QString _style = "QToolButton#buttonSensor{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(250, 255, 255);\
                        border: none;\
                        border-color: rgb(210, 210, 210);\
                        border-style: outset;\
                        border-width: 1px;\
                        border-radius: 15px;}\
                        QToolButton#buttonSensor:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }";
        _button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        _button->setText(_ldev.at(i).name());
        QIcon my_icon;
        my_icon.addPixmap(QPixmap(_ldev.at(i).icon()), QIcon::Normal);
        my_icon.addPixmap(QPixmap(_ldev.at(i).iconOn()), QIcon::Active);
        _button->setIcon(my_icon);
        _button->setAutoRaise(true);
        _button->setIconSize(QSize(40,40));
        _button->setObjectName("buttonSensor");
        _button->setStyleSheet(_style);
        _button->setFont(QFont("Sequoe UI", 8, QFont::Bold));
        _x = _colum*(_left+_w)+_left;
        _y = _row*(_top+_h)+_top;
        _button->setGeometry(QRect(_x,_y,_w,_h));
        _button->show();
        EDeviceInfo dev = _ldev.at(i);
        QObject::connect(_button,&QToolButton::clicked,this,[dev,this](){
            this->showDevice(dev);
        });
        if(++_colum>5){
            _colum=0;
            _row++;
            }
    }

}

void FrmDeviceSelection::on_pushButton_cancel_clicked()
{
    foreach (QToolButton *var, m_buttonListToolControl) {
            m_buttonListToolControl.removeOne(var);
            delete var;
        }
    foreach (QToolButton *var, m_buttonListToolDisplay) {
            m_buttonListToolDisplay.removeOne(var);
            delete var;
        }
    foreach (QToolButton *var, m_buttonListToolControl) {
            m_buttonListToolControl.removeOne(var);
            delete var;
        }
    this->close();
}

