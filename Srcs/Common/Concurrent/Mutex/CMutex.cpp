/**
 * @file    CMutex.cpp
 * @author  jinhee.lee
 * @date    2025.03.09
 * @brief   Class of Mutex
 * 
 * @copyright jinhee.lee
 */

 #include "Common/Concurrent/Mutex/CMutex.h"

 namespace mutex
 {
    CMutex::CMutex()
    {

    }

    CMutex::~CMutex()
    {

    }

    std::mutex& CMutex::getMutex()
    {
        return m_mtx;
    }

    void CMutex::Lock()
    {
        m_mtx.lock();
    }

    void CMutex::UnLock()
    {
        m_mtx.unlock();
    }

 } /* namespace mutex */