#include "Common/Concurrent/Affinity/CSetThreadCoreMask.h"

namespace affinity
{
    CSetThreadCoreMask::CSetThreadCoreMask(thread::CThread * _thread, cpu_set_t _mask)
    {
        m_pthread   = _thread->getThread().native_handle();
        m_CPUSet    = _mask;
       
    }

    CSetThreadCoreMask::~CSetThreadCoreMask()
    {

    }
} /* namespace affinity */