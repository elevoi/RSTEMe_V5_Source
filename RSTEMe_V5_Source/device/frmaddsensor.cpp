#include "frmaddsensor.h"
#include "ui_frmaddsensor.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include "root/eaccountlist.h"
#include "device/def/esensor.h"

FrmAddSensor::FrmAddSensor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmAddSensor)
{
    this->init();
}

FrmAddSensor::FrmAddSensor(QWidget *parent, EDeviceInfo dev):QMainWindow(parent),
ui(new Ui::FrmAddSensor)
{
m_deviceInfo = dev;
this->init();
}

void FrmAddSensor::init()
{
    ui->setupUi(this);
    m_sizeGroupDescription = ui->groupBox_description->size();
    m_sizeEditDescription = ui->textEdit_descriptionDevice->size();
    m_sizeGroupInfo = ui->groupBox_Info->size();

    m_pointAddDevice = ui->pushButton_addDevice->geometry();
    m_pointCancel = ui->pushButton_Cancel->geometry();
    m_pointSave = ui->pushButton_writeFile->geometry();
    m_deviceSetup = this->size();

    this->loadDeviceInfo();
    //default
    if(EAccountList::currentAccount().type()!=EAccountInfo::ACC_ROOT){
        ui->tabWidget_Parameter->setEnabled(false);
        ui->tabWidget_Genaral->setEnabled(false);
        ui->pushButton_addDevice->setHidden(true);
    }
}



void FrmAddSensor::setIcon(EDeviceInfo *dev)
{
    QString iconNumber = QString("%1").arg(dev->serial(EDeviceInfo::SERIAL_WINDOW), 3, 16, QLatin1Char( '0' )).toUpper();
    dev->setIcon(":/icon/device/iconDeviceOff_"+iconNumber);
    dev->setIconOn(":/icon/device/iconDeviceOn_"+iconNumber);
    //AddToolDisplayControl
    switch(dev->serial(EDeviceInfo::SERIAL_GROUP)){
    case EDeviceInfo::GROUP_SOFTWARE:
        break;
    case EDeviceInfo::GROUP_SENSOR:this->setTool(dev);
        break;
    case EDeviceInfo::GROUP_MODULE:this->setTool(dev);
        break;
    case EDeviceInfo::GROUP_SYSTEM:this->setTool(dev);
        break;
    }
}

void FrmAddSensor::setTool(EDeviceInfo *dev)
{
    auto sensor = new ESensor();
    dev->setToolDisplay(sensor->devicePara(*dev).toolDisplay());
    dev->setToolPractice(sensor->devicePara(*dev).toolPractice());
    dev->setToolControl(sensor->devicePara(*dev).toolControl());
}

void FrmAddSensor::showMessageBox(QString text, QMessageBox::Icon icon)
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setText(text);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(icon);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
}

void FrmAddSensor::updateSerialNumber()
{
    bool ok;
    QString str="";
    str += QString("%1").arg(ui->spinBox_versioneDevice->value(), 1, 16, QLatin1Char( '0' ));
    int _groupId = m_edeviceInfoList.groups().at(ui->comboBox_groupDevice->currentIndex()).id;
    str += QString("%1").arg(_groupId, 1, 16, QLatin1Char( '0' ));
    str += QString("%1").arg(m_edeviceInfoList.type(_groupId).at(ui->comboBox_typeDevice->currentIndex()).id, 2, 16, QLatin1Char( '0' ));
    uint val = QString(ui->lineEdit_serialNumber->text()).toUInt(&ok,16);
    str += QString("%1").arg(val, 4, 16, QLatin1Char( '0' ));
    ui->label_serialNumber->setText(str.toUpper());
    m_deviceInfo.setSerial(QString(ui->label_serialNumber->text()).toUInt(&ok,16));
    this->setIcon(&m_deviceInfo);
    ui->pushButton_iconDevice->setIcon(QIcon(m_deviceInfo.icon()));
}


bool FrmAddSensor::getDevice(EDeviceInfo *dev)
{
    bool ok;
    uint _sn = QString(ui->label_serialNumber->text()).toUInt(&ok,16);
    if(!ok){
        this->showMessageBox("Mã thiết bị không đúng! Mã thiết bị bao gồm đúng 8 kí tự [0-9] và [A-F].",QMessageBox::Warning);
        return false;
    }
    dev->setSerial(_sn);
    QString name = ui->lineEdit_nameDevice->text();
    if(name==""){
        this->showMessageBox("Tên thiết bị không được để trống! Tối đa 30 kí tự.",QMessageBox::Warning);
        return false;
    }
    dev->setName(name);
    dev->setAccount(ui->comboBox_accountType->currentIndex());
    this->setIcon(dev);
    ui->pushButton_iconDevice->setIcon(QIcon(dev->icon()));
    dev->setDescription(ui->textEdit_descriptionDevice->toPlainText());
    //setAdvances
    //para
    dev->setSampleTime(ui->spinBox_sampleTime->value());
    dev->setRangeMin(QVariant(ui->spinBox_rangeMin->value()).toDouble());
    dev->setRangeMax(QVariant(ui->spinBox_rangeMax->value()).toDouble());
    //modbus
    dev->setAddressDefault(ui->spinBox_addressDefault->value());
    dev->setPriority(ui->spinBox_requestPriority->value());
    dev->setRetries(ui->spinBox_requestRetries->value());
    dev->setTimeOut(ui->spinBox_requestTimeOut->value());
    dev->setRegStart(ui->spinBox_regStart->value());
    dev->setRegNumber(ui->spinBox_regNumber->value());
    //Calib
    auto _calib = dev->calibParameter();
    _calib.calibTime = ui->spinBox_calibTime->value();
    _calib.sampleTime = ui->spinBox_calibSampleTime->value();
    _calib.sampleNumber = ui->spinBox_sampleNumber->value();
    _calib.accuracyType = ui->comboBox_accuracySelect->currentIndex();
    qreal val;
    val = QString(ui->lineEdit_accuracy->text()).toDouble(&ok);
    if(!ok)val = 0;
    _calib.accuracyValue = val;
    _calib.RangeMin = ui->spinBox_rangeMin->value();
    _calib.RangeMax = ui->spinBox_rangeMax->value();
    if(ui->radioButton_standardSample->isChecked())_calib.methodType = 0;
        else _calib.methodType = 1;
    val = QString(ui->lineEdit_standardValue_01->text()).toDouble(&ok);
    if(!ok)val = 0;
    _calib.standardValue01 = val;
    val = QString(ui->lineEdit_standardValue_02->text()).toDouble(&ok);
    if(!ok)val = 0;
    _calib.standardValue02 = val;
    val = QString(ui->lineEdit_standardValue_03->text()).toDouble(&ok);
    if(!ok)val = 0;
    _calib.standardValue03 = val;
    _calib.evaluateType = ui->comboBox_evaluateSelect->currentIndex();
    dev->setCalibParameter(_calib);
    return true;
}

void FrmAddSensor::loadDeviceInfo()
{
//load combobox
ui->comboBox_groupDevice->clear();
for(int i=0;i<m_edeviceInfoList.groups().count();i++){
    ui->comboBox_groupDevice->addItem(m_edeviceInfoList.groups().at(i).name);
}
//load device info
ui->label_serialNumber->setText(QString("%1").arg(m_deviceInfo.serial(), 8, 16, QLatin1Char( '0' )));
if(m_deviceInfo.account()<ui->comboBox_accountType->count()){
    ui->comboBox_accountType->setCurrentIndex(m_deviceInfo.account());
    }
ui->lineEdit_serialNumber->setText(QString("%1").arg(m_deviceInfo.serial(EDeviceInfo::SERIAL_ID), 4, 16, QLatin1Char( '0' )));
ui->comboBox_groupDevice->setCurrentIndex(m_edeviceInfoList.group(m_deviceInfo.serial(EDeviceInfo::SERIAL_GROUP)));
ui->comboBox_typeDevice->setCurrentIndex(m_edeviceInfoList.type(m_deviceInfo.serial(EDeviceInfo::SERIAL_DEVICE),m_edeviceInfoList.type(m_deviceInfo.serial(EDeviceInfo::SERIAL_GROUP))));
ui->spinBox_versioneDevice->setValue(m_deviceInfo.serial(EDeviceInfo::SERIAL_VERSION));
ui->lineEdit_nameDevice->setText(ui->comboBox_typeDevice->currentText());
ui->textEdit_descriptionDevice->setText(m_deviceInfo.description());

//advanced.............................................................
//para
ui->spinBox_sampleTime->setValue(m_deviceInfo.sampleTime());
ui->spinBox_rangeMin->setValue(QVariant(m_deviceInfo.rangeMin()).toInt());
ui->spinBox_rangeMax->setValue(QVariant(m_deviceInfo.rangeMax()).toInt());

//Modbus
ui->spinBox_addressDefault->setValue(m_deviceInfo.addressDefault());
ui->spinBox_requestPriority->setValue(m_deviceInfo.priority());
ui->spinBox_requestRetries->setValue(m_deviceInfo.retries());
ui->spinBox_requestTimeOut->setValue(m_deviceInfo.timeOut());
ui->spinBox_regStart->setValue(m_deviceInfo.regStart());
ui->spinBox_regNumber->setValue(m_deviceInfo.regNumber());

ui->pushButton_iconDevice->setIcon(QIcon(m_deviceInfo.icon()));

//Calib
auto _calib = m_deviceInfo.calibParameter();
ui->spinBox_calibTime->setValue(_calib.calibTime);
ui->spinBox_calibSampleTime->setValue(_calib.sampleTime);
ui->spinBox_sampleNumber->setValue(_calib.sampleNumber);
ui->comboBox_accuracySelect->setCurrentIndex(_calib.accuracyType);
ui->lineEdit_accuracy->setText(QString::number(_calib.accuracyValue));
ui->spinBox_rangeMin->setValue(_calib.RangeMin);
ui->spinBox_rangeMax->setValue(_calib.RangeMax);
if(_calib.methodType == 0)ui->radioButton_standardSample->setChecked(true);
    else ui->radioButton_referenceSample->setChecked(true);
ui->lineEdit_standardValue_01->setText(QString::number(_calib.standardValue01));
ui->lineEdit_standardValue_02->setText(QString::number(_calib.standardValue02));
ui->lineEdit_standardValue_03->setText(QString::number(_calib.standardValue03));
ui->comboBox_evaluateSelect->setCurrentIndex(_calib.evaluateType);

this->updateSerialNumber();
}



bool FrmAddSensor::addNewDevice()
{
    EDeviceInfo dev;
    if(this->getDevice(&dev)){
        if(!m_edeviceInfoList.insertDevice(dev)){
            return false;
        }
        else{
            //m_edeviceInfoList.load(false);
            m_deviceInfo = dev;
            return true;
        }
    }
    return false;
}

EDeviceInfo FrmAddSensor::device(int serial)
{
EDeviceInfo dev;
dev.setSerial(serial);
//load device info
if(m_edeviceInfoList.checkDevice(dev)){
    auto _listType = m_edeviceInfoList.type(dev);
    dev.setName(_listType.name);
    this->setIcon(&dev);
    }
    else{
        dev.setName("Không hỗ trợ");
    }
return dev;
}


FrmAddSensor::~FrmAddSensor()
{
    delete ui;
}


void FrmAddSensor::on_pushButton_Cancel_clicked()
{
    this->close();
}

void FrmAddSensor::resizeEvent(QResizeEvent *)
{
    int del_h = this->size().height() - m_deviceSetup.height();
    int del_w = this->size().width() - m_deviceSetup.width();
    if(del_h<0)del_h=0;
    if(del_w<0)del_w=0;
    ui->groupBox_description->resize(m_sizeGroupDescription.width()+del_w,m_sizeGroupDescription.height()+del_h);
    ui->textEdit_descriptionDevice->resize(m_sizeEditDescription.width()+del_w,m_sizeEditDescription.height()+del_h);
    ui->groupBox_Info->resize(m_sizeGroupInfo.width(),m_sizeGroupInfo.height()+del_h);


    ui->pushButton_addDevice->setGeometry(QRect(m_pointAddDevice.x()+del_w,m_pointAddDevice.y()+del_h,m_pointAddDevice.width(),m_pointAddDevice.height()));
    ui->pushButton_Cancel->setGeometry(QRect(m_pointCancel.x()+del_w,m_pointCancel.y()+del_h,m_pointCancel.width(),m_pointCancel.height()));
    ui->pushButton_writeFile->setGeometry(QRect(m_pointSave.x(),m_pointSave.y()+del_h,m_pointSave.width(),m_pointSave.height()));
}




void FrmAddSensor::on_pushButton_addDevice_clicked()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có chắc chắn muốn thêm \'" + ui->lineEdit_nameDevice->text() + "\' vào phần mềm không?\n");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
    if (msg.result() == QMessageBox::Yes) {
        if(this->addNewDevice()){
            emit this->setup(m_deviceInfo);
            this->showMessageBox("Đã thêm " + m_deviceInfo.name() +" có mã thiết bị :" + m_deviceInfo.serialHex() + ".", QMessageBox::Information);
        }
        else{
            QMessageBox  msg1;
            msg1.setStandardButtons(QMessageBox::Ok);
            msg1.setText("Đã xảy ra lỗi! Không thể thêm "+ m_deviceInfo.name() +" vào danh sách thiết bị.");
            msg1.setWindowTitle(this->windowTitle());
            msg1.setParent(nullptr);
            msg1.setIcon(QMessageBox::Warning);
            msg1.setWindowIcon(this->windowIcon());
            msg1.exec();
        }
    }

}


void FrmAddSensor::on_comboBox_groupDevice_activated(int)
{
    this->updateSerialNumber();
}



void FrmAddSensor::on_comboBox_typeDevice_activated(int)
{
    this->updateSerialNumber();
}


void FrmAddSensor::on_spinBox_versioneDevice_valueChanged(int )
{
    this->updateSerialNumber();
}


void FrmAddSensor::on_lineEdit_serialNumber_textEdited(const QString &)
{
    bool ok;
    QString(ui->lineEdit_serialNumber->text()).toUInt(&ok,16);
    if(!ok){
        this->showMessageBox("Mã định danh không đúng!\n - Mã định danh thiết bị là duy nhất\n - Mã bao gồm 4 kí tự [0-9] và [A-F].",QMessageBox::Warning);
        ui->lineEdit_serialNumber->setText("09AF");
    }
    this->updateSerialNumber();
}


void FrmAddSensor::on_comboBox_groupDevice_currentIndexChanged(int index)
{
    if(index<0)return;
    ui->comboBox_typeDevice->clear();
    auto _list = m_edeviceInfoList.type(m_edeviceInfoList.groups().at(index).id);
    for(int i=0;i<_list.count();i++){
        ui->comboBox_typeDevice->addItem(_list.at(i).name);
        }
}


void FrmAddSensor::on_comboBox_typeDevice_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_nameDevice->setText(arg1);
}


void FrmAddSensor::on_pushButton_writeFile_clicked()
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


void FrmAddSensor::on_pushButton_openFile_clicked()
{
    if(m_deviceInfo.openFile()){
        this->loadDeviceInfo();
        return;
    }
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setWindowIcon(this->windowIcon());
    //save file
    msg.setText("Không thể mở tệp tin, danh sách thiết bị được lưu với đuôi mở rộng \'.dev\'!");
    msg.setIcon(QMessageBox::Warning);
    msg.exec();
}

void FrmAddSensor::closeEvent(QCloseEvent *event)
{
if(m_msg)delete m_msg;
event->accept();
}
