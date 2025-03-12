#include "emanagesystem.h"

EManageSystem::EManageSystem(QObject *parent)
    : QObject{parent}
{

}

void EManageSystem::setSelectDevice(EDeviceInfo )
{

}

void EManageSystem::setSelectDevice(EDevice *dev)
{
    if(!m_device)m_device = dev;
    this->setSelectDevice(dev->deviceInfo());
}

void EManageSystem::setDevice(EDevice *dev)
{
m_device = dev;
}

void EManageSystem::on_selectDevice(EDeviceInfo dev)
{
emit this->replyDevices(dev,m_device);
}
