#include "frmsensordisplaymultiple.h"
#include "ui_frmsensordisplaymultiple.h"

FrmSensorDisplayMultiple::FrmSensorDisplayMultiple(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmSensorDisplayMultiple)
{
    ui->setupUi(this);
    m_sizeWindow = this->size();
    m_widSensorDisplayDigital = new WidSensorDisplayDigital();
    m_graphicView = ui->graphicsView->size();
    m_frameStatus = ui->frame_status->geometry();
    m_buttonCancel = ui->toolButton_cancel->geometry();
}

FrmSensorDisplayMultiple::~FrmSensorDisplayMultiple()
{
    delete ui;
}

void FrmSensorDisplayMultiple::addDevice(EDevice *dev)
{
    bool isdev=false;
    m_edevice = dev;
    //if(m_listDevice.isEmpty())
    foreach(EDevice *var,m_listDevice){
        if(var == dev)isdev = true;
    }
    if(!isdev){
        m_listDevice.append(dev);
        this->refreshDisplay();
        QObject::connect(dev,&EDevice::finished,this,[dev,this](){
            m_listDevice.removeOne(dev);
            this->removeDisplay(dev);
            if(m_listDevice.isEmpty())this->close();
        });
    }
}

void FrmSensorDisplayMultiple::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    // Your code here.
     int del_h = this->size().height() - m_sizeWindow.height();
     int del_w = this->size().width() - m_sizeWindow.width();
     if(del_h<0)del_h=0;
     if(del_w<0)del_w=0;
     ui->graphicsView->resize(m_graphicView.width()+del_w,m_graphicView.height()+del_h);
     ui->frame_status->setGeometry(m_frameStatus.x(),this->size().height()-m_frameStatus.height(),m_frameStatus.width(),m_frameStatus.height());
     ui->toolButton_cancel->setGeometry(m_buttonCancel.x()+del_w,m_buttonCancel.y()+del_h,m_buttonCancel.width(),m_buttonCancel.height());
}

void FrmSensorDisplayMultiple::on_removeDevice(EDevice *dev)
{
    foreach(EDevice *var,m_listDevice){
        if(var == dev){
            m_listDevice.removeOne(dev);
            this->removeDisplay(dev);
            if(m_listDevice.isEmpty())this->close();
        }
    }
}


void FrmSensorDisplayMultiple::removeDevice()
{
    m_listDevice.clear();
}

void FrmSensorDisplayMultiple::removeDisplay(EDevice *dev)
{
    this->refreshDisplay();
    this->removeSensorDisplayDigital(dev);
}

void FrmSensorDisplayMultiple::refreshDisplay()
{
    int row_max=0;
    if(m_listDevice.count()<1)return;
    if(m_gridLayout)delete m_gridLayout;
        m_gridLayout = new QGridLayout(ui->graphicsView);
    for(int i=0;i<m_listDevice.count();i++){
        int row = i%m_gridRowMax;
        int colum = i/m_gridRowMax;
        m_gridLayout->setColumnStretch(colum,1);
        if(row_max<row)row_max=row;
        auto frm = this->getSensorDisplayDigital(m_listDevice.at(i));
        this->resize(QSize(frm->size().width()*(colum+1)*1.04,30 + frm->size().height()*(row_max+1)*1.1));
        m_gridLayout->addWidget(frm,row,colum);
    }
}

void FrmSensorDisplayMultiple::removeSensorDisplayDigital(EDevice *dev)
{
    foreach (auto *var, m_listSensorDisplayDigital) {
            if(var->device()==dev){
                m_listSensorDisplayDigital.removeOne(var);
                var->deleteLater();
                var = nullptr;
            }
        }
}

WidSensorDisplayDigital *FrmSensorDisplayMultiple::getSensorDisplayDigital(EDevice *dev)
{
    foreach (auto *var, m_listSensorDisplayDigital) {
            if(var->device()==dev){
                var->show();
                var->activateWindow();
                return var;
            }
        }
        m_widSensorDisplayDigital = new WidSensorDisplayDigital();
        m_widSensorDisplayDigital->setDevice(dev);
        QObject::connect(m_widSensorDisplayDigital,&WidSensorDisplayDigital::removeDevice,this,&FrmSensorDisplayMultiple::on_removeDevice);
        m_listSensorDisplayDigital.append(m_widSensorDisplayDigital);
        m_widSensorDisplayDigital->show();
        return m_widSensorDisplayDigital;
}

void FrmSensorDisplayMultiple::on_toolButton_cancel_clicked()
{
    this->close();
}


void FrmSensorDisplayMultiple::on_spinBox_rowMax_valueChanged(int arg1)
{
    m_gridRowMax = arg1;
    this->refreshDisplay();
}

