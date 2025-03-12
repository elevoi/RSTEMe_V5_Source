#include "widsensordisplaydigital.h"
#include "ui_widsensordisplaydigital.h"
#include <QLineEdit>

WidSensorDisplayDigital::WidSensorDisplayDigital(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidSensorDisplayDigital)
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
    m_currentSize = this->size();
}

WidSensorDisplayDigital::~WidSensorDisplayDigital()
{
    if(m_esensor){
    QObject::disconnect(m_esensor,&ESensor::newData,this,&WidSensorDisplayDigital::on_newData);
    m_esensor->deleteLater();
    m_esensor = nullptr;
    }
    delete ui;
}

void WidSensorDisplayDigital::setDevice(EDevice *dev)
{
m_edevice = dev;
m_esensor = new ESensor(this,m_edevice);
m_esensor->start();
//init Display
this->initDisplay();
QObject::connect(m_esensor,&ESensor::newData,this,&WidSensorDisplayDigital::on_newData);
}

void WidSensorDisplayDigital::initDisplay()
{
m_para = m_esensor->parameter();
ui->lcdNumber_Value->setDigitCount(m_para.digital().digitCount);
//name
ui->label_Name->setText(m_esensor->device()->deviceInfo().name() + " - @" + m_esensor->device()->deviceInfo().objectName());
//unit
ui->comboBox_unit->clear();
for(int i=0;i<m_para.unit().count();i++){
    ui->comboBox_unit->addItem(m_para.unit().at(i).name);
}
//resolution
ui->comboBox_resolution->clear();
for(int i=0;i<m_para.resolution().count();i++){
    ui->comboBox_resolution->addItem(m_para.resolution().at(i).name);
}
//resize display with temp
if(!m_para.isTemp()){
    QRect _framePara = ui->frame_parameter->geometry();
    QRect _frame = ui->frame->geometry();
    ui->frame_parameter->setGeometry(QRect(_framePara.x(),_framePara.y()-m_tempFrameSize,_framePara.width(),_framePara.height()));
    ui->frame->setGeometry(QRect(_frame.x(),_frame.y(),_frame.width(),_frame.height()-m_tempFrameSize));
    this->resize(QSize(this->width(),this->height()-m_tempFrameSize));
    }
m_currentSize = this->size();
}

void WidSensorDisplayDigital::setValue()
{
    //value
    m_para = m_esensor->parameter();
    double value = m_para.value();
    ui->lcdNumber_Value->display(value);
    ui->label_UnitSymbol->setText(m_para.currentUnit().symbol);
    //temp
    if(m_para.isTemp()){
        ui->lcdNumber_temperature->display(m_para.temp());
    }
}

void WidSensorDisplayDigital::on_newData(int)
{
this->setValue();
}

void WidSensorDisplayDigital::on_toolButton_cancel_clicked()
{
    emit this->removeDevice(m_edevice);
    this->close();
}


void WidSensorDisplayDigital::on_comboBox_unit_currentIndexChanged(int index)
{
    if(index<0)return;
    m_para = m_esensor->parameter();
    m_para.setCurrentUnit(m_para.unit().at(index));
    m_esensor->setParameter(m_para);
    ui->label_UnitSymbol->setText(m_para.unit().at(index).symbol);
}


void WidSensorDisplayDigital::on_comboBox_resolution_currentIndexChanged(int index)
{
    if(index<0)return;
    m_para = m_esensor->parameter();
    m_para.setCurrentResolution(m_para.resolution().at(index));
    m_esensor->setParameter(m_para);
}

