#include "widsensortooldigital.h"
#include "ui_widsensortooldigital.h"
#include <QtMath>

WidSensorToolDigital::WidSensorToolDigital(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidSensorToolDigital)
{
    ui->setupUi(this);
}

WidSensorToolDigital::~WidSensorToolDigital()
{
    delete ui;
}

void WidSensorToolDigital::setDevice(EDevice *dev)
{
    m_edevice = dev;
    m_esensor = new ESensor(this,m_edevice);
    m_esensor->start();
    //init Display
    this->initDisplay();
    QObject::connect(m_esensor,&ESensor::newData,this,&WidSensorToolDigital::on_newData);
    QObject::connect(m_esensor,&ESensor::error,this,&WidSensorToolDigital::on_error);
}

void WidSensorToolDigital::setSampleTime(int time)
{
if(!m_esensor)return;
m_sampleTimeLast = m_esensor->sampleTime();
m_esensor->setSampleTime(time);
}




////////////////////////////////////////////////////////////////////Chart
QSplineSeries *WidSensorToolDigital::newSeries()
{
    m_series = new QSplineSeries();
    if(m_edevice)m_series->setName(m_edevice->deviceInfo().name());
    m_listSeries.append(m_series);
    return m_series;
}

QSplineSeries *WidSensorToolDigital::series()
{
if(!m_series){
    m_series = new QSplineSeries(this);
    if(m_edevice)m_series->setName(m_edevice->deviceInfo().name());
    m_listSeries.append(m_series);
}
return m_series;
}


QValueAxis *WidSensorToolDigital::axisY()
{
if(!m_axisY){
    m_axisY = new QValueAxis(this);
    if(m_edevice)m_axisY->setTitleText(m_edevice->deviceInfo().name());
}
if(m_esensor){
    switch ((int)m_esensor->parameter().currentResolution().factor) {
        case 0:m_axisY->setLabelFormat("%.0f");
            break;
        case 1:m_axisY->setLabelFormat("%.1f");
            break;
        case 2:m_axisY->setLabelFormat("%.2f");
            break;
        case 3:m_axisY->setLabelFormat("%.3f");
            break;
        case 4:m_axisY->setLabelFormat("%.4f");
            break;
        case 5:m_axisY->setLabelFormat("%.5f");
            break;
        }
}

return m_axisY;
}

void WidSensorToolDigital::resizeAxisY(qreal val)
{
if(!m_axisY)return;
if(m_axisY_Max<val)m_axisY_Max = val;
if(m_axisY_Min>val)m_axisY_Min = val;
qreal _min = m_axisY_Min*0.25;
qreal _max = m_axisY_Max*0.25;
if(_min<0)_min *= -1;
if(_max<0)_max *= -1;
m_axisY->setRange(m_axisY_Min-_min,m_axisY_Max+_max);
}


void WidSensorToolDigital::resetAxisY()
{
    if(!m_axisY)return;
    m_axisY_Max = -999999;
    m_axisY_Min = 999999;
    m_axisY->setRange(0,1);
}

void WidSensorToolDigital::removeSeries()
{
    foreach (auto var, m_listSeries) {
       // var->detachAxis(m_axisY);
        var->deleteLater();
        var = nullptr;
    }
}

void WidSensorToolDigital::setDisplayColor(QColor c)
{
    auto _palete = ui->lcdNumber_value->palette();
    _palete.setColor(QPalette::WindowText,c);
ui->lcdNumber_value->setPalette(_palete);
auto _pal = ui->label_Unit->palette();
_pal.setColor(ui->label_Unit->foregroundRole(),c);
ui->label_Unit->setPalette(_pal);
}

void WidSensorToolDigital::updateEvaluate(double val)
{
if(m_evaluatePara.max<val)m_evaluatePara.max=val;
if(m_evaluatePara.min>val)m_evaluatePara.min=val;
m_evaluatePara.sum += val;
m_evaluatePara.sample++;
m_evaluatePara.avr = m_evaluatePara.sum/QVariant(m_evaluatePara.sample).toDouble();
m_evaluatePara.buff.append(val);
double _sum = 0;
foreach (auto var, m_evaluatePara.buff) {
    _sum += pow((var-m_evaluatePara.avr),2);
    }
m_evaluatePara.var = _sum/QVariant(m_evaluatePara.buff.count()).toDouble();
m_evaluatePara.std = pow(m_evaluatePara.var,0.5);
}

void WidSensorToolDigital::resetEvaluate()
{
m_evaluatePara.sample = 0;
m_evaluatePara.sum = 0;
m_evaluatePara.max = -99999999;
m_evaluatePara.min = 99999999;
m_evaluatePara.avr = 0;
m_evaluatePara.std = 0;
m_evaluatePara.buff.clear();
}

void WidSensorToolDigital::on_newData(int)
{
    m_isConnect = true;
    this->setValue();
}

void WidSensorToolDigital::on_error(EDevice::Error err)
{
if(err!=EDevice::NoError)m_isConnect = false;
}

void WidSensorToolDigital::initDisplay()
{
    m_para = m_esensor->parameter();
    ui->lcdNumber_value->setDigitCount(m_para.digital().digitCount);
    //name
    ui->label_Name->setText(m_esensor->device()->deviceInfo().name() + "\n(@" + m_esensor->device()->deviceInfo().objectName()+")");
    ui->label_Unit->setText("");
    QIcon my_icon;
    my_icon.addPixmap(QPixmap(m_esensor->device()->deviceInfo().icon()), QIcon::Normal);
    my_icon.addPixmap(QPixmap(m_esensor->device()->deviceInfo().iconOn()), QIcon::Active);
    ui->toolButton_info->setIcon(my_icon);
}

void WidSensorToolDigital::setValue()
{
    //value
    m_para = m_esensor->parameter();
    double value = m_para.value();
    ui->lcdNumber_value->display(value);
    ui->label_Unit->setText(m_para.currentUnit().symbol);
    //update series
    emit this->updatePoint(m_series,m_para.value());
}


void WidSensorToolDigital::on_toolButton_info_clicked()
{
    if(!m_edevice)return;
    if(!m_frmAddSensor)m_frmAddSensor = new FrmAddSensor(this,m_edevice->deviceInfo());
    m_frmAddSensor->setWindowTitle("Thêm thiết bị");
    m_frmAddSensor->show();
}


void WidSensorToolDigital::on_toolButton_close_clicked()
{
    if(!m_edevice)return;
    if(m_esensor){
        m_esensor->deleteLater();
        m_esensor = nullptr;
    }
    emit this->removeDevice(m_edevice);
}


void WidSensorToolDigital::on_toolButton_setup_clicked()
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

