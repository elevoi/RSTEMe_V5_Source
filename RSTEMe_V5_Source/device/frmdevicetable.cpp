#include "frmdevicetable.h"
#include "ui_frmdevicetable.h"
#include <QMessageBox>
#include "root/eaccountlist.h"

FrmDeviceTable::FrmDeviceTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDeviceTable)
{
    ui->setupUi(this);
    this->loadSizeWindow();
    m_buttonGroupClick = 1;
    this->loadTypeList();
}

FrmDeviceTable::~FrmDeviceTable()
{
    delete ui;
}

void FrmDeviceTable::setSelectType(SelectType var)
{
m_selectType = var;
QList<int> _list;
m_deviceSelectList.clear();
switch (m_selectType) {
    case FrmDeviceTable::SLT_SINGLE:
        ui->pushButton_selectDevice->setText("Chọn thiết bị");
        break;
    case FrmDeviceTable::SLT_MULTIPLE:
        _list = EAccountList::currentAccount().devices();
        m_edeviceInfoList.load(false);
        foreach (auto var, _list) {
            bool ok=false;
            auto _dev = m_edeviceInfoList.getDevice(var,&ok);
            if(ok)m_deviceSelectList.append(_dev);
        }
        this->loadTypeList();
        ui->pushButton_selectDevice->setText("Chọn danh sách thiết bị");
        break;
    default:
        break;
    }
}

void FrmDeviceTable::setDisableSoftwareType(bool st)
{
    ui->toolButton_groupSoftware->setEnabled(!st);
}

void FrmDeviceTable::setEnable(EDeviceInfo::GroupType type)
{
    ui->toolButton_groupSoftware->setEnabled(false);
    ui->toolButton_groupSensor->setEnabled(false);
    ui->toolButton_groupModule->setEnabled(false);
    ui->toolButton_groupSystem->setEnabled(false);
    switch(type){
        case EDeviceInfo::GroupType::GROUP_SOFTWARE:ui->toolButton_groupSoftware->setEnabled(true);m_buttonGroupClick = 0;
            break;
        case EDeviceInfo::GroupType::GROUP_SENSOR:ui->toolButton_groupSensor->setEnabled(true);m_buttonGroupClick = 1;
            break;
        case EDeviceInfo::GroupType::GROUP_MODULE:ui->toolButton_groupModule->setEnabled(true);m_buttonGroupClick = 2;
            break;
        case EDeviceInfo::GroupType::GROUP_SYSTEM:ui->toolButton_groupSystem->setEnabled(true);m_buttonGroupClick = 3;
            break;
        case EDeviceInfo::GroupType::GROUP_TOOL:
            break;
    }
    this->loadTypeList();
}

void FrmDeviceTable::setEnable(EDeviceInfo dev)
{
this->setEnable((EDeviceInfo::GroupType)dev.serial(EDeviceInfo::SERIAL_GROUP));
}

void FrmDeviceTable::closeEvent(QCloseEvent *)
{

}

void FrmDeviceTable::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
       // Your code here.
    this->resizeWindow();
}

void FrmDeviceTable::loadSizeWindow()
{
    m_sizeWindowDefault.window = this->geometry();
    m_sizeWindowDefault.listGroup = ui->listWidget_Group->geometry();
    m_sizeWindowDefault.listType = ui->listWidget_Type->geometry();
    m_sizeWindowDefault.pushSelect = ui->pushButton_selectDevice->geometry();
    m_sizeWindowDefault.pushCancel = ui->pushButton_Cancel->geometry();
}

void FrmDeviceTable::resizeWindow()
{
    int deltaHeight = this->size().height() - m_sizeWindowDefault.window.height();
    int deltaWidth = this->size().width() - m_sizeWindowDefault.window.width();

    ui->listWidget_Group->resize(QSize(m_sizeWindowDefault.listGroup.width(),m_sizeWindowDefault.listGroup.height()+deltaHeight));
    ui->listWidget_Type->resize(QSize(m_sizeWindowDefault.listType.width()+deltaWidth,m_sizeWindowDefault.listType.height()+deltaHeight));
    ui->pushButton_selectDevice->setGeometry(QRect(m_sizeWindowDefault.pushSelect.x()+deltaWidth,m_sizeWindowDefault.pushSelect.y()+deltaHeight,m_sizeWindowDefault.pushSelect.width(),m_sizeWindowDefault.pushSelect.height()));
    ui->pushButton_Cancel->setGeometry(QRect(m_sizeWindowDefault.pushCancel.x()+deltaWidth,m_sizeWindowDefault.pushCancel.y()+deltaHeight,m_sizeWindowDefault.pushCancel.width(),m_sizeWindowDefault.pushCancel.height()));

    //reDefault
    this->loadSizeWindow();
    this->loadTypeList();
}

void FrmDeviceTable::loadTypeList()
{
    if(m_buttonGroupClick<0)return;
    int _w=100,_h=75,_space=10;
    m_edeviceInfoList.load(false);
    QList<EDeviceInfo> _ldev;
    //Check type of account: student, teacher, root
    foreach (auto var, m_edeviceInfoList.groupList(m_buttonGroupClick)) {
        if(var.account()<=(int)EAccountList::currentAccount().type()){
            _ldev.append(var);
            }
        }
    //clear button list
    foreach (QToolButton *var, m_buttonTypeList) {
            m_buttonTypeList.removeOne(var);
            delete var;
        }
    if(m_gridLayout)delete m_gridLayout;
        m_gridLayout = new QGridLayout(ui->listWidget_Type);
        int colum_max = ui->listWidget_Type->size().width()/(_w+_space);
        int row_max = ui->listWidget_Type->size().height()/(_h+_space);
        if(row_max<1)row_max=1;
        if(colum_max<1)colum_max=1;
        m_gridLayout->setRowStretch(row_max,1);
        m_gridLayout->setColumnStretch(colum_max,1);
        m_gridLayout->setSpacing(_space);
    for(int i=0;i<_ldev.count();i++){
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
        _button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        _button->setText(_ldev.at(i).name());
        QIcon my_icon;
        my_icon.addPixmap(QPixmap(_ldev.at(i).icon()), QIcon::Normal);
        my_icon.addPixmap(QPixmap(_ldev.at(i).iconOn()), QIcon::Active);
        _button->setAutoRaise(true);
        _button->setIconSize(QSize(50,50));
        _button->setObjectName("buttonSensor");
        _button->setStyleSheet(_style);
        _button->setFont(QFont("Sequoe UI", 7, QFont::Bold));
        _button->resize(QSize(_w,_h));
        //_button->setGeometry(QRect(_x,_y,_w,_h));
        int _row = i/colum_max;
        int _colum = i%colum_max;
        m_gridLayout->addWidget(_button,_row,_colum,Qt::AlignLeft|Qt::AlignTop);
        //
        _button->show();
        _dev = _ldev.at(i);
        if(this->m_selectType!=FrmDeviceTable::SLT_SINGLE){
            foreach (auto var, m_deviceSelectList) {
                if(var==_dev)my_icon.addPixmap(my_icon.pixmap(_button->iconSize().width(),QIcon::Disabled,QIcon::On));
                }
            }
        _button->setIcon(my_icon);
        QObject::connect(_button,&QToolButton::clicked,this,[_button,_dev,this](){
            if((_dev.serial(EDeviceInfo::SERIAL_GROUP)==0x0)&&((_dev.serial(EDeviceInfo::SERIAL_DEVICE)==0x001)||(_dev.serial(EDeviceInfo::SERIAL_DEVICE)==0x008)))return;
            if(this->m_selectType==FrmDeviceTable::SLT_SINGLE){
                this->m_deviceInfo = _dev;
                foreach (auto var, m_buttonTypeList) {
                    if(!var->isEnabled())var->setEnabled(true);
                    }
                _button->setEnabled(false);
                }
                else{
                    bool isDev = false;
                    foreach (auto var, m_deviceSelectList) {
                        if(var==_dev){
                            isDev = true;
                            m_deviceSelectList.removeOne(_dev);
                            }
                        }
                    QIcon _icon;
                    _icon.addPixmap(QPixmap(_dev.icon()), QIcon::Normal);
                    if(!isDev){
                        _icon.addPixmap(_icon.pixmap(_button->iconSize().width(),QIcon::Disabled,QIcon::On));
                        m_deviceSelectList.append(_dev);
                        }
                    _icon.addPixmap(QPixmap(_dev.iconOn()), QIcon::Active);
                    _button->setIcon(_icon);
                    }
        });
        /*
        bool _have = false;
        if(this->m_selectType!=FrmDeviceTable::SLT_SINGLE){
            foreach (auto var, m_deviceSelectList) {
                if(var==_dev)_have=true;
                }
            }
        //
        if(!_have)my_icon.addPixmap(my_icon.pixmap(_button->iconSize().width(),QIcon::Disabled,QIcon::On));
        _button->setIcon(my_icon);
        QObject::connect(_button,&QToolButton::clicked,this,[_button,_dev,this](){
            if(this->m_selectType==FrmDeviceTable::SLT_SINGLE){
                this->m_deviceInfo = _dev;
                foreach (auto var, m_buttonTypeList) {
                    if(!var->isEnabled())var->setEnabled(true);
                    }
                _button->setEnabled(false);
                }
                else{
                    bool isDev = false;
                    foreach (auto var, m_deviceSelectList) {
                        if(var==_dev){
                            isDev = true;
                            if(_dev.serial()!=0x100F0000)m_deviceSelectList.removeOne(_dev);
                            }
                        }
                    QIcon _icon;
                    _icon.addPixmap(QPixmap(_dev.icon()), QIcon::Normal);
                    _icon.addPixmap(QPixmap(_dev.iconOn()), QIcon::Active);
                    if(!isDev){

                        if(_dev.serial()!=0x100F0000)m_deviceSelectList.append(_dev);
                        }
                        else _icon.addPixmap(_icon.pixmap(_button->iconSize().width(),QIcon::Disabled,QIcon::On));
                    _button->setIcon(_icon);
                    }
        });
         */
}
}

void FrmDeviceTable::selectDevice()
{
    if(m_deviceInfo.serial()==0){
        QMessageBox  msg1;
        msg1.setStandardButtons(QMessageBox::Ok);
        msg1.setText("Chưa chọn thiết bị trong danh sách!");
        msg1.setWindowTitle(this->windowTitle());
        msg1.setParent(nullptr);
        msg1.setIcon(QMessageBox::Warning);
        msg1.setWindowIcon(this->windowIcon());
        msg1.exec();
        return;
    }
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Thiết bị đã được chọn là \"" + m_deviceInfo.name() + " (@" + m_deviceInfo.serialHex() + "\".\n Bạn có muốn tiếp tục không?");
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() == QMessageBox::Yes){
         emit this->replySelectDeviceInfo(m_deviceInfo);
         this->close();
     }
}

void FrmDeviceTable::selectDeviceList()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Danh sách thiết bị được chọn sẽ được lưu vào tài khoản \"" + EAccountList::currentAccount().account() + "\".\n Bạn có muốn tiếp tục không?");
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() == QMessageBox::Yes){
         QList<int> _list;
         foreach (auto var, m_deviceSelectList) {
             _list.append(var.serial());
         }
         EAccountInfo _acc = EAccountList::currentAccount();
         _acc.setDevices(_list);
         EAccountList::setCurrentAccount(_acc);
         EAccountList _lst;
         _lst.insertAccount(_acc);
         this->close();
     }
}

void FrmDeviceTable::on_toolButton_groupSoftware_clicked()
{
    if(m_buttonGroupClick!=0)m_buttonGroupClick=0;
        else m_buttonGroupClick = -1;
        this->loadTypeList();
}


void FrmDeviceTable::on_toolButton_groupSensor_clicked()
{
    if(m_buttonGroupClick!=1)m_buttonGroupClick=1;
        else m_buttonGroupClick = -1;
        this->loadTypeList();
}


void FrmDeviceTable::on_toolButton_groupModule_clicked()
{
    if(m_buttonGroupClick!=2)m_buttonGroupClick=2;
        else m_buttonGroupClick = -1;
        this->loadTypeList();
}


void FrmDeviceTable::on_toolButton_groupSystem_clicked()
{
    if(m_buttonGroupClick!=3)m_buttonGroupClick=3;
        else m_buttonGroupClick = -1;
        this->loadTypeList();
}


void FrmDeviceTable::on_pushButton_Cancel_clicked()
{
    this->close();
}


void FrmDeviceTable::on_pushButton_selectDevice_clicked()
{
    switch (m_selectType) {
    case FrmDeviceTable::SLT_SINGLE:this->selectDevice();
        break;
    case FrmDeviceTable::SLT_MULTIPLE:this->selectDeviceList();
        break;
    default:
        break;
    }
}

