/**
 * @file    CMutex.h
 * @author  jinhee.lee
 * @date    2025.03.09
 * @brief   Class of mutex
 * 
 * @copyright jinhee.lee
 */

#ifndef __COMMON_CONCURRENT_MUTEX_CMUTEX_H__
#define __COMMON_CONCURRENT_MUTEX_CMUTEX_H__

#include "Common/Common.h"

 namespace mutex
 {
    class CMutex
    {
    public:
        CMutex();
        virtual ~CMutex();

    
    public:
        /**
         * @brief   Return Mutex
         */
        std::mutex& getMutex();


    public:
        /**
         * @brief   Lock
         */
        void Lock();

        /**
         * @brief   UnLock
         */
        void UnLock();


    private:
        /**
         * @brief   Mutex Instance
         */
        std::mutex m_mtx;

    }; /* class CMutex */
 } /* namespace mutex */
#endif  /* __COMMON_CONCURRENT_MUTEX_CMUTEX_H__ */