#include "frmsensordisplaydigital.h"
#include "ui_frmsensordisplaydigital.h"
#include <QLineEdit>

FrmSensorDisplayDigital::FrmSensorDisplayDigital(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmSensorDisplayDigital)
{
    ui->setupUi(this);
    QLineEdit *_lde = ui->comboBox_unit->lineEdit();
    _lde->setObjectName("LineEdit");
    QString _style = ("QLineEdit{\
                        color: rgb(2, 87, 122);\
                        background-color: rgb(255, 255 ,255);\
                        border: none;\
                        border-style: outset;\
                        border-top-left-radius: 20px;\
                        border-bottom-left-radius: 20px;\
                        }\
                        QLineEdit:hover{\
                        background-color: rgb(25, 149, 173);\
                        color: rgb(255, 255, 255);\
                        }");
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setFont(QFont("Segoe UI",14,QFont::Bold));
    _lde->setStyleSheet(_style);
    _lde->setReadOnly(true);
    ui->comboBox_unit->setLineEdit(_lde);
    _lde = ui->comboBox_resolution->lineEdit();
    _lde->setFont(QFont("Segoe UI",14,QFont::Bold));
    _lde->setAlignment(Qt::AlignHCenter);
    _lde->setStyleSheet(_style);
    _lde->setReadOnly(true);
    ui->comboBox_resolution->setLineEdit(_lde);

}
FrmSensorDisplayDigital::~FrmSensorDisplayDigital()
{
    if(m_frmDeviceConfig){
        m_frmDeviceConfig->deleteLater();
        m_frmDeviceConfig = nullptr;
    }
    if(m_frmAddSensor){
        m_frmAddSensor->deleteLater();
        m_frmAddSensor = nullptr;
    }
    if(m_esensor){
    QObject::disconnect(m_esensor,&ESensor::newData,this,&FrmSensorDisplayDigital::on_newData);
    m_esensor->deleteLater();
    m_esensor = nullptr;
    }
    delete ui;
}

void FrmSensorDisplayDigital::setDevice(EDevice *dev)
{
m_edevice = dev;
this->setWindowTitle(dev->deviceInfo().name() + "(@" + dev->deviceInfo().serialHex() + ")");
ui->label_Name->setText(dev->deviceInfo().name());
m_esensor = new ESensor(this,m_edevice);
m_esensor->start();
//init Display
this->initDisplay();
QObject::connect(m_esensor,&ESensor::newData,this,&FrmSensorDisplayDigital::on_newData);
}

void FrmSensorDisplayDigital::closeEvent(QCloseEvent *event)
{
event->accept();
}
void FrmSensorDisplayDigital::initDisplay()
{
m_para = m_esensor->parameter();
ui->lcdNumber_Value->setDigitCount(m_para.digital().digitCount);

//name
ui->label_Name->setText(m_esensor->device()->deviceInfo().name());

QIcon my_icon;
my_icon.addPixmap(QPixmap(m_esensor->device()->deviceInfo().icon()), QIcon::Normal);
my_icon.addPixmap(QPixmap(m_esensor->device()->deviceInfo().iconOn()), QIcon::Active);
ui->toolButton_info->setIcon(my_icon);
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
//resize display with temp
if(!m_para.isTemp()){
    QRect _frame = ui->frame_parameter->geometry();
    ui->frame_parameter->setGeometry(QRect(_frame.x(),_frame.y()-70,_frame.width(),_frame.height()));
    this->resize(QSize(this->width(),this->height()-90));
}
m_esensor->setParameter(m_para);
}

void FrmSensorDisplayDigital::setValue()
{
    //value
    m_para = m_esensor->parameter();
    double value = m_para.value();
    ui->lcdNumber_Value->display(value);
    ui->lcdNumber_temperature->display(m_para.temp());
    //isTempComp
    if(m_para.isTempComp())ui->checkBox_tempature->setCheckState(Qt::Checked);
    else ui->checkBox_tempature->setCheckState(Qt::Unchecked);
}




void FrmSensorDisplayDigital::on_newData(int)
{
this->setValue();
}



void FrmSensorDisplayDigital::on_pushButton_cancel_clicked()
{
    this->close();
}


void FrmSensorDisplayDigital::on_comboBox_unit_currentIndexChanged(int index)
{
    if(index<0)return;
    m_para = m_esensor->parameter();
    m_para.setCurrentUnit(m_para.unit().at(index));
    m_esensor->setParameter(m_para);
    ui->label_UnitSymbol->setText(m_para.unit().at(index).symbol);
}


void FrmSensorDisplayDigital::on_comboBox_resolution_currentIndexChanged(int index)
{
    if(index<0)return;
    m_para = m_esensor->parameter();
    m_para.setCurrentResolution(m_para.resolution().at(index));
    m_esensor->setParameter(m_para);
}


void FrmSensorDisplayDigital::on_toolButton_info_clicked()
{
    if(!m_edevice)return;
    if(!m_frmAddSensor)m_frmAddSensor = new FrmAddSensor(this,m_edevice->deviceInfo());
    m_frmAddSensor->setAutoFillBackground(false);
    m_frmAddSensor->setWindowTitle("Thêm thiết bị");
    m_frmAddSensor->show();
}


void FrmSensorDisplayDigital::on_toolButton_config_clicked()
{
    if(!m_esensor)return;
    if(!m_frmDeviceConfig){
        m_frmDeviceConfig = new FrmDeviceConfig(this);
        m_frmDeviceConfig->setSensor(m_esensor);
        m_frmDeviceConfig->setWindowIcon(QIcon(m_esensor->device()->deviceInfo().icon()));
    }
    m_frmDeviceConfig->show();
    m_frmDeviceConfig->activateWindow();
}

