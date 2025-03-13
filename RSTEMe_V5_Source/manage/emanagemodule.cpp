#include "emanagemodule.h"

EManageModule::EManageModule(QObject *parent)
    : QObject{parent}
{

}

void EManageModule::setSelectDevice(EDeviceInfo )
{

}

void EManageModule::setSelectDevice(EDevice *dev)
{
    if(!m_device)m_device = dev;
    this->setSelectDevice(dev->deviceInfo());
}

void EManageModule::setDevice(EDevice *dev)
{
m_device = dev;
}

void EManageModule::on_selectDevice(EDeviceInfo dev)
{
emit this->replyDevices(dev,m_device);
}
