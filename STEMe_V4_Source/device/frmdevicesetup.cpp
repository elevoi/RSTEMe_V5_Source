#include "frmdevicesetup.h"
#include "ui_frmdevicesetup.h"
#include <QDebug>

FrmDeviceSetup::FrmDeviceSetup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDeviceSetup)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon/software/iconSoftware01_off"));
    //getSize
    m_sizeTreeViewDevice = ui->treeWidgetDevice->size();
    m_sizeframeDevice = ui->frameDevice->size();
    m_sizeEditDescription = ui->textEditDescription->size();
    m_deviceSetup = this->size();

    m_pointFrameCancel = ui->frameCancel->geometry();
    m_pointRemove = ui->pushButton_remove->geometry();
    m_pointSave = ui->pushButton_save->geometry();
    m_pointSaveList = ui->pushButton_saveList->geometry();
    m_pointOpenList = ui->pushButton_openList->geometry();

    for(int i=0;i<m_edeviceInfoList.groups().count();i++)m_treeExpandedStatus.append(false);
this->setTreeView();
}

FrmDeviceSetup::~FrmDeviceSetup()
{
    delete ui;
}

void FrmDeviceSetup::on_setup(EDeviceInfo dev)
{
    m_deviceInfo = dev;
    this->refresh();
}


void FrmDeviceSetup::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
       // Your code here.
    int del_h = this->size().height() - m_deviceSetup.height();
    int del_w = this->size().width() - m_deviceSetup.width();
    if(del_h<0)del_h=0;
    if(del_w<0)del_w=0;
    ui->treeWidgetDevice->resize(m_sizeTreeViewDevice.width(),m_sizeTreeViewDevice.height()+del_h);
    ui->frameDevice->resize(m_sizeframeDevice.width()+del_w,m_sizeframeDevice.height()+del_h);
    ui->textEditDescription->resize(m_sizeEditDescription.width()+del_w,m_sizeEditDescription.height()+del_h);

    ui->frameCancel->setGeometry(QRect(m_pointFrameCancel.x()+del_w,m_pointFrameCancel.y()+del_h,m_pointFrameCancel.width(),m_pointFrameCancel.height()));
    ui->pushButton_remove->setGeometry(QRect(m_pointRemove.x()+del_w,m_pointRemove.y()+del_h,m_pointRemove.width(),m_pointRemove.height()));
    ui->pushButton_save->setGeometry(QRect(m_pointSave.x()+del_w,m_pointSave.y()+del_h,m_pointSave.width(),m_pointSave.height()));
    ui->pushButton_saveList->setGeometry(QRect(m_pointSaveList.x(),m_pointSaveList.y()+del_h,m_pointSaveList.width(),m_pointSaveList.height()));
    ui->pushButton_openList->setGeometry(QRect(m_pointOpenList.x(),m_pointOpenList.y()+del_h,m_pointOpenList.width(),m_pointOpenList.height()));
}

void FrmDeviceSetup::refresh()
{
    if(m_edeviceInfoList.load(false)){
        this->setTreeView();
    }
}


void FrmDeviceSetup::setTreeView()
{
ui->treeWidgetDevice->clear();
ui->treeWidgetDevice->setColumnCount(2);
QStringList labels;
labels<<"Tên thiết bị"<<"Mã thiết bị";
ui->treeWidgetDevice->setHeaderLabels(labels);
QList<ETypeDef::TypeDevice> _group = m_edeviceInfoList.groups();
QList<QTreeWidgetItem*> root;

ui->treeWidgetDevice->setColumnWidth(0,180);
for(int i=0;i<_group.count();i++){
    QTreeWidgetItem *_item = new QTreeWidgetItem(ui->treeWidgetDevice);
    QList<EDeviceInfo> _list = m_edeviceInfoList.groupList(i);
    _item->setText(0,_group.at(i).name);
    _item->setText(1,"");
    _item->setFont(0,QFont("Segoe UI", 9, QFont::Bold,true));
    for(int j=0;j<_list.size();j++){
        QTreeWidgetItem *_child = new QTreeWidgetItem();
        _child->setText(0,_list.at(j).name());
        _child->setText(1,QString("%1").arg(_list.at(j).serial(), 8, 16, QLatin1Char( '0' )));
        _item->addChild(_child);
    }
    if(i<m_treeExpandedStatus.count()){
        if(m_treeExpandedStatus.at(i))_item->setExpanded(true);
        }
    root.append(_item);
}
ui->treeWidgetDevice->addTopLevelItems(root);
emit stateChange(ETypeDef::StateChange::LIST_DEVICE);
}

void FrmDeviceSetup::loadDeviceInfo()
{
ui->label_serialNumber->setText(QString("%1").arg(m_deviceInfo.serial(), 8, 16, QLatin1Char( '0' )));
ui->label_nameDevice->setText(m_deviceInfo.name());
ui->label_groupDevice->setText(m_edeviceInfoList.group(m_deviceInfo).name);
ui->label_typeDevice->setText(m_edeviceInfoList.type(m_deviceInfo).name);
ui->label_versionDevice->setText(QString::number(m_deviceInfo.serial(EDeviceInfo::SERIAL_VERSION)));
ui->textEditDescription->setText(m_deviceInfo.description());
}

void FrmDeviceSetup::showSensor()
{
    if(m_frmAddSensor){
        QObject::disconnect(m_frmAddSensor,&FrmAddSensor::setup,this,&FrmDeviceSetup::on_setup);
        m_frmAddSensor->deleteLater();
        m_frmAddSensor = nullptr;
    }
    m_frmAddSensor = new FrmAddSensor(this,m_deviceInfo);
    QObject::connect(m_frmAddSensor,&FrmAddSensor::setup,this,&FrmDeviceSetup::on_setup);
    m_frmAddSensor->setWindowTitle("Thêm thiết bị");
    m_frmAddSensor->show();
}




void FrmDeviceSetup::on_pushButton_addDevice_clicked()
{
this->showSensor();
}


void FrmDeviceSetup::on_pushButton_Cancel_clicked()
{
    this->close();
}


void FrmDeviceSetup::on_pushButton_remove_clicked()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có chắc chắn muốn xóa \'" + m_deviceInfo.name() + "\' ra khỏi danh sách thiết bị không?\n");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
    if (msg.result() == QMessageBox::Yes) {
        if(!m_edeviceInfoList.removeDevice(m_deviceInfo)){
            QMessageBox  msg1;
            msg1.setStandardButtons(QMessageBox::Ok);
            msg1.setText("Đã xảy ra lỗi! Không thể xóa "+ m_deviceInfo.name() +" khỏi danh sách thiết bị.");
            msg1.setWindowTitle(this->windowTitle());
            msg1.setParent(nullptr);
            msg1.setIcon(QMessageBox::Warning);
            msg1.setWindowIcon(this->windowIcon());
            msg1.exec();
        }
        else this->setTreeView();
    } else {

    }

}




void FrmDeviceSetup::on_pushButton_save_clicked()
{
    if(m_deviceInfo.saveFile())return;
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setWindowIcon(this->windowIcon());
    //save file
    msg.setText("Không thể lưu thiết bị!");
    msg.setIcon(QMessageBox::Warning);
    msg.exec();
}


void FrmDeviceSetup::on_pushButton_saveList_clicked()
{
    if(m_edeviceInfoList.saveFile())return;
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setWindowIcon(this->windowIcon());
    //save file
    msg.setText("Không thể lưu danh sách thiết bị!");
    msg.setIcon(QMessageBox::Warning);
    msg.exec();
}

void FrmDeviceSetup::on_pushButton_openList_clicked()
{
    if(m_edeviceInfoList.openFile()){
        this->setTreeView();
        m_edeviceInfoList.save();
        m_edeviceInfoList.load(true);
        return;
    }
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setWindowIcon(this->windowIcon());
    //save file
    msg.setText("Không thể mở tệp tin, danh sách thiết bị được lưu với đuôi mở rộng \'.ldev\'!");
    msg.setIcon(QMessageBox::Warning);
    msg.exec();
}

void FrmDeviceSetup::closeEvent(QCloseEvent *event)
{
    if(m_frmAddSensor){
        QObject::disconnect(m_frmAddSensor,&FrmAddSensor::setup,this,&FrmDeviceSetup::on_setup);
        m_frmAddSensor->deleteLater();
        m_frmAddSensor = nullptr;
    }
    if(m_itemModel)delete m_itemModel;
    event->accept();
}

void FrmDeviceSetup::on_treeWidgetDevice_collapsed(const QModelIndex &index)
{
    if(index.row()<m_treeExpandedStatus.count())m_treeExpandedStatus.replace(index.row(),false);
}

void FrmDeviceSetup::on_treeWidgetDevice_expanded(const QModelIndex &index)
{
    if(index.row()<m_treeExpandedStatus.count())m_treeExpandedStatus.replace(index.row(),true);
}

void FrmDeviceSetup::on_treeWidgetDevice_itemSelectionChanged()
{
    QTreeWidgetItem *item = ui->treeWidgetDevice->currentItem();
    bool ok;
    EDeviceInfo dev;
    if(item->text(1)=="")return;
    uint val = QString(item->text(1)).toUInt(&ok,16);
    if(ok){
       dev = m_edeviceInfoList.getDevice(val,&ok);
    }
    if(ok)m_deviceInfo = dev;
    else{
        m_deviceInfo.setSerial(0);
        m_deviceInfo.setName("lỗi");
    }
this->loadDeviceInfo();
}


void FrmDeviceSetup::on_treeWidgetDevice_itemDoubleClicked(QTreeWidgetItem*, int)
{
this->showSensor();
}

