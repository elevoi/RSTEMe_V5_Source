#include "erequestunit.h"


int ERequestUnit::m_requestID=0;
ERequestUnit::ERequestUnit()
{

}

int ERequestUnit::requestID()
{
if(m_requestID<1)m_requestID=1;
return m_requestID++;
}

ERequestUnit ERequestUnit::getRequestRead()
{
    ERequestUnit _rq;
    _rq.setType(RequestType::Read);
    return _rq;
}

ERequestUnit ERequestUnit::getRequestWrite()
{
    ERequestUnit _rq;
    _rq.setType(RequestType::Write);
    return _rq;
}
