#include "frmdeviceconfig.h"
#include "ui_frmdeviceconfig.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QtMath>

FrmDeviceConfig::FrmDeviceConfig(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDeviceConfig)
{
    ui->setupUi(this);
    QLineEdit *_lde = ui->comboBox_unit->lineEdit();
    _lde->setObjectName("LineEdit");
    QString _style = ("QLineEdit{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(255, 255 ,255);\
                        border: none;\
                        border-style: outset;\
                        border-top-left-radius: 15px;\
                        border-bottom-left-radius: 15px;\
                        }\
                        QLineEdit:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }");
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setFont(QFont("Segoe UI",10,QFont::Bold));
    _lde->setStyleSheet(_style);
    _lde->setReadOnly(true);
    ui->comboBox_unit->setLineEdit(_lde);
    _lde = ui->comboBox_resolution->lineEdit();
    _lde->setFont(QFont("Segoe UI",10,QFont::Bold));
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setStyleSheet(_style);
    _lde->setReadOnly(true);
    ui->comboBox_resolution->setLineEdit(_lde);
}

FrmDeviceConfig::~FrmDeviceConfig()
{
 /*   if(m_esensor){
    QObject::disconnect(m_esensor,&ESensor::newData,this,&FrmDeviceConfig::on_newData);
  //  m_esensor->deleteLater();
  //  m_esensor = nullptr;
    }*/
    delete ui;
}

void FrmDeviceConfig::setDevice(EDevice *dev)
{
    m_edevice = dev;
    this->setWindowTitle(dev->deviceInfo().name() + "(@" + dev->deviceInfo().serialHex() + ")");
    m_esensor = new ESensor(this,m_edevice);
    m_esensor->start();
    //init Display
    this->init();
    QObject::connect(m_esensor,&ESensor::newData,this,&FrmDeviceConfig::on_newData);
}

void FrmDeviceConfig::setSensor(ESensor *sen)
{
    if(m_esensor){
        QObject::disconnect(m_esensor,&ESensor::newData,this,&FrmDeviceConfig::on_newData);
        m_esensor->deleteLater();
        m_esensor = nullptr;
    }
    m_esensor = sen;
    m_edevice = sen->device();
    this->setWindowTitle(m_edevice->deviceInfo().name() + "(@" + m_edevice->deviceInfo().serialHex() + ")");
    //init Display
    this->init();
    QObject::connect(m_esensor,&ESensor::newData,this,&FrmDeviceConfig::on_newData);
}

void FrmDeviceConfig::on_newData(int)
{
    this->setValue();
}

void FrmDeviceConfig::on_pushButton_cancel_clicked()
{
    this->close();
}

void FrmDeviceConfig::init()
{
    if(!m_esensor)return;
    m_para = m_esensor->parameter();
    //name
    ui->label_Name->setText(m_esensor->device()->deviceInfo().name());
    //zero
    if(!m_para.isZero()){
        ui->toolButton_setZero->setHidden(true);
        ui->toolButton_clearZero->setHidden(true);
        ui->lineEdit_Zero->setHidden(true);
        ui->label_zeroText->setText("Không điều chỉnh điểm tham chiếu");
    }
    else{
        ui->lineEdit_Zero->setText(QString::number(EDeviceParameter::getConvertValue(m_para.zeroSetup(),m_para.currentUnit(),m_para.currentResolution())));
        ui->label_Unit->setText(m_para.currentUnit().symbol);
    }
    //sampleTime
    ui->spinBox_sampleTime->setValue(m_esensor->device()->deviceInfo().sampleTime());

    //unit
    ui->comboBox_unit->clear();
    auto _unit = m_para.currentUnit();
    for(int i=0;i<m_para.unit().count();i++){
        ui->comboBox_unit->addItem(m_para.unit().at(i).name);
    }
    m_para.setCurrentUnit(_unit);
    ui->comboBox_unit->setCurrentText(m_para.currentUnit().name);
    //resolution
    ui->comboBox_resolution->clear();
    auto res = m_para.currentResolution();
    for(int i=0;i<m_para.resolution().count();i++){
        ui->comboBox_resolution->addItem(m_para.resolution().at(i).name);
    }
    m_para.setCurrentResolution(res);
    ui->comboBox_resolution->setCurrentText(m_para.currentResolution().name);

    //temp compensation
    if(m_para.isTempComp())ui->checkBox_tempCompensation->setCheckState(Qt::Checked);
        else ui->checkBox_tempCompensation->setCheckState(Qt::Unchecked);

    m_initStatus = true;
}

void FrmDeviceConfig::setValue()
{
    //value
    m_para = m_esensor->parameter();
    if(m_para.isTempComp())ui->checkBox_tempCompensation->setCheckState(Qt::Checked);
        else ui->checkBox_tempCompensation->setCheckState(Qt::Unchecked);
}


void FrmDeviceConfig::on_toolButton_setZero_clicked()
{
    if(!m_esensor)return;
    bool ok=false;
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setWindowIcon(this->windowIcon());
    qreal val = QVariant(ui->lineEdit_Zero->text()).toDouble(&ok);
    if(!ok){
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Giá trị điểm không nhập vào không hợp lệ!\n Giá trị cần phải là một số thực.");
        msg.exec();
        return;
        }
    uint32_t _zero = 0xFFFFFFFF;
    if(val!=0)_zero = EDeviceParameter::encode_toUInt32((m_esensor->parameter().adc()+m_esensor->parameter().zero()-val),log10(m_esensor->parameter().division()));
    m_esensor->setZero(_zero);
    msg.setIcon(QMessageBox::Information);
    msg.setText("Đã thực hiện \"Zero\" thiết bị.");
    msg.exec();
}


void FrmDeviceConfig::on_toolButton_setSampleTime_clicked()
{
    if(!m_esensor)return;
    m_esensor->setSampleTime(ui->spinBox_sampleTime->value());
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Information);
    msg.setWindowIcon(this->windowIcon());
    msg.setText("Đã cài đặt thời gian lấy mẫu.");
    msg.exec();
}


void FrmDeviceConfig::on_toolButton_clearZero_clicked()
{
    if(!m_esensor)return;
    m_esensor->setZero(0);
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Information);
    msg.setWindowIcon(this->windowIcon());
    msg.setText("Đã thực hiện \" xóa Zero\" thiết bị.");
    msg.exec();
}


void FrmDeviceConfig::on_comboBox_unit_currentIndexChanged(int index)
{
    if(index<0)return;
    if(!m_esensor)return;
    m_para = m_esensor->parameter();
    m_para.setCurrentUnit(m_para.unit().at(index));
    m_esensor->setParameter(m_para);
    ui->label_Unit->setText(m_para.currentUnit().symbol);
    ui->lineEdit_Zero->setText(QString::number(EDeviceParameter::getConvertValue(m_para.zeroSetup(),m_para.currentUnit(),m_para.currentResolution())));
}


void FrmDeviceConfig::on_comboBox_resolution_currentIndexChanged(int index)
{
    if(index<0)return;
    if(!m_esensor)return;
    m_para = m_esensor->parameter();
    m_para.setCurrentResolution(m_para.resolution().at(index));
    m_esensor->setParameter(m_para);
    ui->lineEdit_Zero->setText(QString::number(EDeviceParameter::getConvertValue(m_para.zeroSetup(),m_para.currentUnit(),m_para.currentResolution())));
}


void FrmDeviceConfig::on_lineEdit_Zero_editingFinished()
{
    if(!m_esensor)return;
    m_para = m_esensor->parameter();
    bool ok=false;
    qreal val = QVariant(ui->lineEdit_Zero->text()).toDouble(&ok);
    if(!ok){
     //   ui->lineEdit_Zero->setText(QString::number(m_para.zeroSetup()));
        return;
        }
    m_para.setZeroSetup(val);
    m_esensor->setParameter(m_para);
}



void FrmDeviceConfig::on_checkBox_tempCompensation_toggled(bool checked)
{
    if(!m_initStatus)return;
    if(m_esensor)m_esensor->setTempCompensation(checked);
}

