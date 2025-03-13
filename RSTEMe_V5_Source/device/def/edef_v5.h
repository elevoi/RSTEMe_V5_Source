#ifndef EDEF_V5_H
#define EDEF_V5_H

#include "device/edeviceinfo.h"
#include "device/def/edeviceparameter.h"
#include "comm/erequestunit.h"

class EDef
{
public:
    EDef(EDeviceInfo dev);
    ~EDef();

    EDeviceParameter parameter();
    //EDeviceParameter parameter(EDeviceInfo dev);
    void setParameter(EDeviceParameter para);
    void setRequest(ERequestUnit request);
private:
    EDeviceInfo m_edeviceInfo;
    EDeviceParameter m_para;
    ERequestUnit m_requestUnit;

    void init();
};

#endif // EDEF_V5_H
