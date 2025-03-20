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

    CThread::CThread(std::string _threadName)
    : m_PCB { _threadName,
              thread::thread_type::THREAD_ONCE_T,
              thread::thread_status::THREAD_STATUS_WAIT,
              0
            }
    {

    }

    CThread::CThread(std::string _threadName, thread_once_t _type)
    : m_PCB { _threadName,
              thread::thread_type::THREAD_ONCE_T,
              thread::thread_status::THREAD_STATUS_WAIT,
              0
            }
    {

    }

    CThread::CThread(std::string _threadName, thread_loop_t _type)
    : m_PCB { _threadName,
              thread::thread_type::THREAD_LOOP_T,
              thread::thread_status::THREAD_STATUS_WAIT,
              0
            }
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
        m_PCB._TYPE = thread::thread_type::THREAD_STOP_T;
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

    pcb_t & CThread::getThreadInfo()
    {
        return m_PCB;
    }

    void CThread::Run()
    {
        try
        {
            PreOperate();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        
        do
        {
            try
            {
                Operate();
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
            }
            
        }
        while(m_PCB._TYPE == thread::thread_type::THREAD_LOOP_T);

        try
        {
            PostOperate();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
} /* thread */