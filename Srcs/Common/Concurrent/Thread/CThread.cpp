/**
 * @file    CThread.cpp
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of Thread Source
 * 
 * @copyright jinhee.lee
 */

#include "Common/Concurrent/Thread/CThread.h"

namespace thread {

    CThread::CThread() noexcept
    {

    }

    CThread::CThread(thread_once_t _type)
    : m_threadType(thread_type::THREAD_ONCE_T)
    {

    }

    CThread::CThread(thread_loop_t _type)
    : m_threadType(thread_type::THREAD_LOOP_T)
    {

    }

    CThread::~CThread() noexcept
    {

    }

    void CThread::thread_Start()
    {
        m_thread = std::thread(&CThread::Run, this);
    }

    void CThread::thread_Stop()
    {
        std::lock_guard<std::mutex> lock(m_Mutex.getMutex());
        m_threadType = thread_type::THREAD_STOP_T;
    }

    void CThread::Join()
    {
        m_thread.join();
    }

    bool CThread::Joinable()
    {
        return m_thread.joinable();
    }

    void CThread::Detach()
    {
        m_thread.detach();
    }

    void CThread::Run()
    {
        try
        {
            PreOperate();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        do
        {
            try
            {
                Operate();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        while(m_threadType == thread_type::THREAD_LOOP_T);

        try
        {
            PostOperate();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
} /* thread */