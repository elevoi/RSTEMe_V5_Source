//system
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QMouseEvent>
#include <QStyle>
#include <QLabel>

QList<EDevice*> m_listDeviceOnline;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(this->windowTitle() + " - " + EAccountList::currentAccount().account()+"("+EAccountList::currentAccount().typeText()+")");
    //Check device in list
    this->checkDeviceList();
    //get all size default of window
    m_deltaJumpWidgetDisplay = ui->frame_Display->geometry().x()-ui->listWidget_Type->geometry().x();
    this->loadSizeWindow();
    //load list of icon group to listWidgetGroup
    this->blinkTypeList();
    this->loadTypeList();
    //eventFilter
    ui->frame_Display->installEventFilter(this);
    //Manage Devices...............................
    if(m_manageDevice)delete m_manageDevice;
    m_manageDevice = new EManageDevice(this);
    QObject::connect(m_manageDevice,&EManageDevice::stateChange,this,&MainWindow::on_stateChange);
    QObject::connect(m_manageDevice,&EManageDevice::error,this,&MainWindow::on_error);
    m_manageDevice->connectModbusRTU();
}

MainWindow::~MainWindow()
{
    this->close();
    delete ui;
}

void MainWindow::close()
{
    if(m_manageDevice){
        m_manageDevice->deleteLater();
        m_manageDevice = nullptr;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có muốn thoát khỏi phần mềm \'" + this->windowTitle() + "\' không?\n");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() != QMessageBox::Yes) {
         event->ignore();
     } else {
         this->close();
         event->accept();
     }
}

void MainWindow::checkDeviceList()
{
    //m_edeviceInfoList.clear();
    EDeviceInfo dev;
    FrmAddSensor *_sensor;
    m_edeviceInfoList.load(true);
    dev.setSerial(0x10010000);
    if(m_edeviceInfoList.findDevice(dev)<0){
        dev.setAccount(EAccountInfo::ACC_ROOT);
        _sensor = new FrmAddSensor(this,dev);
        _sensor->addNewDevice();
        }
    dev.setSerial(0x10080000);
    if(m_edeviceInfoList.findDevice(dev)<0){
        dev.setAccount(EAccountInfo::ACC_STUDENT);
        _sensor = new FrmAddSensor(this,dev);
        _sensor->addNewDevice();
        }
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
       // Your code here.
    this->resizeWindow();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->frame_Display){
        if(event->type()==QEvent::MouseButtonPress)this->hideTypeList();
    }

return QMainWindow::eventFilter(watched, event);
}

void MainWindow::on_stateChange(ETypeDef::StateChange state)
{
    switch(state){
    case ETypeDef::StateChange::LIST_DEVICE:this->loadTypeList();
        break;
    case ETypeDef::StateChange::LIST_ONLINE:this->loadListDeviceOnline();
        break;
    case ETypeDef::StateChange::CONNECTION:this->statusConnectModbus(m_manageDevice->isConnectModbusRTU());
        break;
    }



}

void MainWindow::on_error(EDevice::Error error,EDevice *dev)
{
    if(error == EDevice::NoError)this->deviceConnectChanged(true,dev->deviceInfo());
        else this->deviceConnectChanged(false,dev->deviceInfo());
   /* switch(error){
        case EDevice::Error::NoError:
            this->deviceConnectChanged(true,dev->deviceInfo());
            qDebug()<<"NoError";
            break;
        case EDevice::Error::ErrorSetAddress:
            qDebug()<<"Error set Address!";
            break;
        case EDevice::Error::ErrorSerialNumber:
            qDebug()<<"Error check SerialNumber!";
            break;
        case EDevice::Error::ErrorRequestData:
            qDebug()<<"Error request data, check connect!";
            this->deviceConnectChanged(false,dev->deviceInfo());
            break;
        case EDevice::Error::ErrorStart:
            qDebug()<<"Error request data, check connect!";
            break;
    }*/
}

void MainWindow::deviceConnectChanged(bool status, EDeviceInfo dev)
{
    QString _style = "QToolButton{\
                    color: rgb(255, 255, 255);\
                    background-color: rgb(25, 149, 173);\
                    border: none;\
                    border-style: outset;\
                    border-width: 1px;\
                    border-radius: 10px;}\
                    QToolButton:hover{\
                    background-color: rgb(250, 255, 255);\
                    color: rgb(2, 87, 122);\
                    }";
    for(int i=0;i<m_edeviceOnlineList.count();i++) {
        if(m_edeviceOnlineList.at(i).serial()==dev.serial()){
            if(!status){
                _style = "QToolButton{\
                        color: rgb(255, 0, 0);\
                        background-color: rgb(25, 149, 173);\
                        border: none;\
                        border-style: outset;\
                        border-width: 1px;\
                        border-radius: 10px;}\
                        QToolButton:hover{\
                        background-color: rgb(250, 255, 255);\
                        color: rgb(2, 87, 122);\
                        }";
            }
            m_buttonOnlineList.at(i)->setStyleSheet(_style);
        }
}
}



void MainWindow::loadSizeWindow()
{
    m_sizeWindowDefault.window = this->geometry();
    m_sizeWindowDefault.listGroup = ui->listWidget_Group->geometry();
    m_sizeWindowDefault.listType = ui->listWidget_Type->geometry();
    m_sizeWindowDefault.listTool = ui->listWidget_online->geometry();
    m_sizeWindowDefault.widgetDisplay = ui->frame_Display->geometry();
    m_sizeWindowDefault.pushLogin = ui->toolButton_login->geometry();
    m_sizeWindowDefault.pushClear = ui->toolButton_clearDevice->geometry();
}

void MainWindow::resizeWindow()
{
    int deltaHeight = this->size().height() - m_sizeWindowDefault.window.height();
    int deltaWidth = this->size().width() - m_sizeWindowDefault.window.width();

    ui->listWidget_Group->resize(QSize(m_sizeWindowDefault.listGroup.width(),m_sizeWindowDefault.listGroup.height()+deltaHeight));
    ui->listWidget_Type->resize(QSize(m_sizeWindowDefault.listType.width(),m_sizeWindowDefault.listType.height()+deltaHeight));
    ui->listWidget_online->resize(QSize(m_sizeWindowDefault.listTool.width()+deltaWidth,m_sizeWindowDefault.listTool.height()));
    ui->frame_Display->resize(QSize(m_sizeWindowDefault.widgetDisplay.width()+deltaWidth,m_sizeWindowDefault.widgetDisplay.height()+deltaHeight));
    ui->toolButton_login->setGeometry(QRect(m_sizeWindowDefault.pushLogin.x(),m_sizeWindowDefault.pushLogin.y()+deltaHeight,m_sizeWindowDefault.pushLogin.width(),m_sizeWindowDefault.pushLogin.height()));
    ui->toolButton_clearDevice->setGeometry(QRect(m_sizeWindowDefault.pushClear.x()+deltaWidth,m_sizeWindowDefault.pushClear.y(),m_sizeWindowDefault.pushClear.width(),m_sizeWindowDefault.pushClear.height()));


    //reDefault
    this->loadSizeWindow();
}

void MainWindow::statusConnectModbus(bool isConnect)
{
    if(isConnect){
        ui->toolButton_groupConnection->setStyleSheet("QToolButton#toolButton_groupConnection{\
                                                      color: rgb(2, 87, 122);\
                                                      background-color: rgb(50, 200 ,90);\
                                                      border: none;\
                                                      border-style: outset;\
                                                      border-width: 0px;\
                                                      border-radius: 20px;\
                                                      }\
                                                      QToolButton#toolButton_groupConnection:hover{\
                                                      background-color: rgb(25, 149, 173);\
                                                      color: rgb(255, 255, 255);\
                                                      }");
        QIcon my_icon;
        my_icon.addPixmap(QPixmap(":/icon/group/iconSoftwareConnect_on"), QIcon::Normal);
        my_icon.addPixmap(QPixmap(":/icon/group/iconSoftwareConnect_Active"), QIcon::Active);
        ui->toolButton_groupConnection->setIcon(my_icon);
    }
        else {
        ui->toolButton_groupConnection->setStyleSheet("QToolButton#toolButton_groupConnection{\
                                                      color: rgb(2, 87, 122);\
                                                      background-color: rgb(240, 30 ,40);\
                                                      border: none;\
                                                      border-style: outset;\
                                                      border-width: 0px;\
                                                      border-radius: 20px;\
                                                      }\
                                                      QToolButton#toolButton_groupConnection:hover{\
                                                      background-color: rgb(25, 149, 173);\
                                                      color: rgb(255, 255, 255);\
                                                      }");
        QIcon my_icon;
        my_icon.addPixmap(QPixmap(":/icon/group/iconSoftwareConnect_off"), QIcon::Normal);
        my_icon.addPixmap(QPixmap(":/icon/group/iconSoftwareConnect_Active"), QIcon::Active);
        ui->toolButton_groupConnection->setIcon(my_icon);
    }
}


void MainWindow::blinkTypeList()
{
    //show/hide listType
        if(m_buttonGroupClick == -1){
            ui->frame_Display->setGeometry(ui->frame_Display->geometry().x()-m_deltaJumpWidgetDisplay,ui->frame_Display->geometry().y(),ui->frame_Display->geometry().width()+m_deltaJumpWidgetDisplay,ui->frame_Display->geometry().height());
            m_sizeWindowDefault.widgetDisplay = ui->frame_Display->geometry();
            return;
            }
            else ui->frame_Display->setGeometry(ui->frame_Display->geometry().x()+m_deltaJumpWidgetDisplay,ui->frame_Display->geometry().y(),ui->frame_Display->geometry().width()-m_deltaJumpWidgetDisplay,ui->frame_Display->geometry().height());
        m_sizeWindowDefault.widgetDisplay = ui->frame_Display->geometry();
}

void MainWindow::hideTypeList()
{
    if(m_buttonGroupClick != -1){
        m_buttonGroupClick = -1;
        blinkTypeList();
        }
}
/*For List Group------------------------------------------------------------------------------------------------------------------*/
void MainWindow::loadTypeList()
{
    if(m_buttonGroupClick<0)return;
    m_edeviceInfoList.load(false);
    QList<EDeviceInfo> _ldev;
    int _row=0,_colum=0;
    //Check type of account: student, teacher, root
    foreach (auto var, m_edeviceInfoList.groupList(m_buttonGroupClick,m_edeviceInfoList.deviceList(EAccountList::currentAccount()))){
            _ldev.append(var);
        }
    //clear button list
    foreach (QToolButton *var, m_buttonTypeList) {
            m_buttonTypeList.removeOne(var);
            delete var;
        }
    for(int i=0;i<_ldev.count();i++){
        int _x,_y,_w=100,_h=75,_space=5;
        _w = (ui->listWidget_Type->width()-(3*_space))/2;
        EDeviceInfo _dev;
        QToolButton *_button = new QToolButton(ui->listWidget_Type);
        m_buttonTypeList.append(_button);
        QString _style = "QToolButton{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(250, 255, 255);\
                        border: none;\
                        border-style: outset;\
                        border-width: 0px;\
                        border-radius: 15px;}\
                        QToolButton:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }";
        /*QString _style = "QToolButton{\
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
                        }";*/
        _button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        _dev = _ldev.at(i);
        if(m_showDeviceSerial)_button->setText(_dev.name() + "\n(" + _dev.serialHex() + ")");
            else _button->setText(_dev.name());

        QIcon my_icon;
        my_icon.addPixmap(QPixmap(_ldev.at(i).icon()), QIcon::Normal);
        my_icon.addPixmap(QPixmap(_ldev.at(i).iconOn()), QIcon::Active);
        _button->setIcon(my_icon);
        _button->setAutoRaise(true);
        _button->setIconSize(QSize(50,50));
        _button->setObjectName("buttonSensor");
        _button->setStyleSheet(_style);
        _button->setFont(QFont("Sequoe UI", 7, QFont::Bold));
        _x = _colum*(_space+_w)+_space;
        _y = _row*(_space+_h)+_space;
        _button->setGeometry(QRect(_x,_y,_w,_h));
        _button->show();
        QObject::connect(_button,&QToolButton::clicked,this,[_button,_dev,this](){
            this->m_manageDevice->selectDeviceInfo(_dev);
            //check device is online
            foreach (auto edev, EDeviceList::deviceOnlineList()) {
                if((edev->deviceInfo()==_dev)&&(this->m_buttonGroupClick!=0))_button->setEnabled(false);
            }
        });
        if(++_colum>1){
            _colum=0;
            _row++;
            }
    }
}


void MainWindow::loadListDeviceOnline()
{
    int _colum=0;
    QList<EDevice*> _ldev = EDeviceList::deviceOnlineList();
    foreach (auto *var, m_buttonOnlineList) {
            m_buttonOnlineList.removeOne(var);
            delete var;
        }
    m_edeviceOnlineList.clear();
    for(int i=0;i<_ldev.count();i++){
        int _x,_y=5,_w=100,_h=40,_left=5;
        _w = (ui->listWidget_online->width()/_ldev.count())-_left;
        if(_w>200)_w=200;
        if(_w<25)_w=25;
        EDevice *_dev;
        QToolButton *_button = new QToolButton(ui->listWidget_online);
        QStyle *_styleIcon = this->style();
        QIcon _icon = _styleIcon->standardIcon(QStyle::SP_TitleBarCloseButton);
        QToolButton *_btClose = new QToolButton(_button);
        _btClose->setIcon(_icon);
        _btClose->setToolButtonStyle(Qt::ToolButtonIconOnly);
        m_buttonOnlineList.append(_button);
        m_edeviceOnlineList.append(_ldev.at(i)->deviceInfo());
        QString _style = "QToolButton{\
                        color: rgb(255, 255, 255);\
                        background-color: rgb(25, 149, 173);\
                        border: none;\
                        border-style: outset;\
                        border-width: 1px;\
                        border-radius: 10px;}\
                        QToolButton:hover{\
                        background-color: rgb(250, 255, 255);\
                        color: rgb(2, 87, 122);\
                        }";
        _button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        _dev = _ldev.at(i);
        if(m_showDeviceSerial)_button->setText(_dev->deviceInfo().name() + "\n(" + _dev->deviceInfo().serialHex() + ")");
            else _button->setText(_dev->deviceInfo().name());
        QIcon my_icon;
        my_icon.addPixmap(QPixmap(_ldev.at(i)->deviceInfo().icon()), QIcon::Active);
        my_icon.addPixmap(QPixmap(_ldev.at(i)->deviceInfo().iconOn()), QIcon::Normal);
        _button->setIcon(my_icon);
        _button->setAutoRaise(true);
        _button->setIconSize(QSize(30,30));
        _button->setObjectName("buttonSensor");
        _button->setStyleSheet(_style);
        _button->setFont(QFont("Sequoe UI", 8, QFont::Bold));
        _x = _colum*(_left+_w)+_left;
        _button->setGeometry(QRect(_x,_y,_w,_h));
        _btClose->setGeometry(QRect(_button->size().width()-35,5,30,30));
        _button->show();
        _btClose->show();
        QObject::connect(_button,&QToolButton::clicked,this,[_dev,this](){
            this->m_manageDevice->selectDeviceInfo(_dev->deviceInfo());
            this->hideTypeList();
        });
        QObject::connect(_btClose,&QToolButton::clicked,this,[_dev,this](){
            this->m_manageDevice->removeDevice(_dev);
            this->loadListDeviceOnline();
            this->loadTypeList();
        });
        _colum++;
}
}

void MainWindow::on_toolButton_groupSoftware_clicked()
{
    int last = m_buttonGroupClick;
    if(m_buttonGroupClick!=0)m_buttonGroupClick=0;
        else m_buttonGroupClick = -1;
    if((last == -1)||(last==0))blinkTypeList();
        this->loadTypeList();
}


void MainWindow::on_toolButton_groupSensor_clicked()
{
    int last = m_buttonGroupClick;
    if(m_buttonGroupClick!=1)m_buttonGroupClick=1;
        else m_buttonGroupClick = -1;
    if((last == -1)||(last==1))blinkTypeList();
        this->loadTypeList();
}


void MainWindow::on_toolButton_groupModule_clicked()
{
    int last = m_buttonGroupClick;
    if(m_buttonGroupClick!=2)m_buttonGroupClick=2;
        else m_buttonGroupClick = -1;
    if((last == -1)||(last==2))blinkTypeList();
        this->loadTypeList();
}


void MainWindow::on_toolButton_groupSystem_clicked()
{
    int last = m_buttonGroupClick;
    if(m_buttonGroupClick!=3)m_buttonGroupClick=3;
        else m_buttonGroupClick = -1;
    if((last == -1)||(last==3))blinkTypeList();
        this->loadTypeList();
}


void MainWindow::on_pushButton_TypeList_clicked()
{
    //this->hideTypeList();
    m_showDeviceSerial = !m_showDeviceSerial;
    this->loadListDeviceOnline();
    this->loadTypeList();
}


void MainWindow::on_toolButton_groupSearch_clicked()
{
EDeviceInfo dev;
FrmAddSensor sensor;
bool ok;
int _serial = QString("10050001").toUInt(&ok,16);
dev = m_edeviceInfoList.getDevice(_serial,&ok);
if(!ok){
    dev = sensor.device(_serial);
}
this->m_manageDevice->selectDeviceInfo(dev);
}


void MainWindow::on_toolButton_groupConnection_clicked()
{
    EDeviceInfo dev;
    FrmAddSensor sensor;
    bool ok;
    int _serial = QString("10060001").toUInt(&ok,16);
    dev = m_edeviceInfoList.getDevice(_serial,&ok);
    if(!ok){
        dev = sensor.device(_serial);
    }
    this->m_manageDevice->selectDeviceInfo(dev);
}


void MainWindow::on_toolButton_login_clicked()
{
    m_manageDevice->removeDeviceAll();
    emit this->login();
}


void MainWindow::on_toolButton_clearDevice_clicked()
{
    if(m_manageDevice){
        m_manageDevice->removeDeviceAll();
        this->loadListDeviceOnline();
        this->loadTypeList();
    }
}
