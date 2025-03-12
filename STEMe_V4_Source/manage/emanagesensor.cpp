#include "emanagesensor.h"
#include <QString>

EManageSensor::EManageSensor(QObject *parent)
    : QObject{parent}
{
m_frmDeviceSelection = new FrmDeviceSelection();
QObject::connect(m_frmDeviceSelection,&FrmDeviceSelection::selectDevice,this,&EManageSensor::on_replySelectDeviceInfo);
}

EManageSensor::~EManageSensor()
{
this->close();
}

void EManageSensor::selectDevice(EDevice *dev)
{
    m_device = dev;
    if(!m_frmDeviceSelection){
        m_frmDeviceSelection = new FrmDeviceSelection();
        QObject::connect(m_frmDeviceSelection,&FrmDeviceSelection::selectDevice,this,&EManageSensor::on_replySelectDeviceInfo);
    }
    m_frmDeviceSelection->setDevice(m_device->deviceInfo());
    m_frmDeviceSelection->setWindowIcon(QIcon(m_device->deviceInfo().icon()));
    QObject::connect(m_device,&EDevice::finished,this,&EManageSensor::on_finished);
    m_frmDeviceSelection->show();
    m_frmDeviceSelection->activateWindow();
}

void EManageSensor::on_replySelectDeviceInfo(EDeviceInfo dev)
{
    if(!m_device)return;
    emit this->replySelectDevice(dev,m_device);
}

void EManageSensor::on_finished()
{
//QObject::disconnect(m_device,&EDevice::finished,this,&EManageSensor::on_finished);
if(m_frmDeviceSelection)m_frmDeviceSelection->close();
}


void EManageSensor::close()
{
     if(m_frmDeviceSelection){
         m_frmDeviceSelection->deleteLater();
         m_frmDeviceSelection = nullptr;
     }
}
