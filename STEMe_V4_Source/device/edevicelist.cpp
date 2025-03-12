#include "edevicelist.h"



QList<EDevice*> EDeviceList::m_listEDeviceOnline;
EDeviceList::EDeviceList()
{

}


bool EDeviceList::removeDeviceOnlineList(EDevice *dev)
{
    return m_listEDeviceOnline.removeOne(dev);
}

void EDeviceList::appendDeviceOnlineList(EDevice *dev)
{
m_listEDeviceOnline.append(dev);
}


