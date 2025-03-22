#ifndef __COMMON_CONCURRENT_AFFINITY_CSETTHREADCOREMASK_H__
#define __COMMON_CONCURRENT_AFFINITY_CSETTHREADCOREMASK_H__

#include "Common/Common.h"
#include "Common/Concurrent/Thread/CThread.h"

namespace affinity
{
    class CSetThreadCoreMask
    {
    public:
        CSetThreadCoreMask(thread::CThread * _thread, unsigned int _mask);
        virtual ~CSetThreadCoreMask();

    public:
        void operator()(thread::CThread * _thread, unsigned int _mask)
        {
            CPU_SET(_mask, &m_CPUSet);
            pthread_setaffinity_np(_thread->getThread().native_handle(), sizeof(cpu_set_t), &m_CPUSet);
        }

    private:
        /**
         * @brief 
         * 
         */
        pthread_t m_pthread;

        /**
         * @brief 
         * 
         */
        cpu_set_t m_CPUSet;

    }; /* class CSetThreadCoreMask */
} /* namespace affinity */
#endif  /* __COMMON_CONCURRENT_AFFINITY_CSETTHREADCOREMASK_H__ */
