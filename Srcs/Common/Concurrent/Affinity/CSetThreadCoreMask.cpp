#include "Common/Concurrent/Affinity/CSetThreadCoreMask.h"

namespace affinity
{
    CSetThreadCoreMask::CSetThreadCoreMask(thread::CThread * _thread, unsigned int _mask)
    {
        m_pthread   = _thread->getThread().native_handle();
        CPU_ZERO(&m_CPUSet);
       
    }

    CSetThreadCoreMask::~CSetThreadCoreMask()
    {

    }
} /* namespace affinity */