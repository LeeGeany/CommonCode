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
    : m_PCB { 
             _threadName,
              thread::thread_type::THREAD_ONCE_T,
              thread::thread_status::THREAD_STATUS_WAIT,
              0
            }
    {

    }

    CThread::CThread(std::string _threadName, thread_once_t _type)
    : m_PCB { 
              _threadName,
              thread::thread_type::THREAD_ONCE_T,
              thread::thread_status::THREAD_STATUS_WAIT,
              0
            }
    {

    }

    CThread::CThread(std::string _threadName, thread_loop_t _type)
    : m_PCB { 
              _threadName,
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
        std::lock_guard<std::mutex> lock(m_Mutex.getMutex());
        m_thread = std::thread(&CThread::Run, this);
        m_PCB._STATUS   = thread::thread_status::THREAD_STATUS_RUNNING;
        
    }

    void CThread::thread_Stop()
    {
        std::lock_guard<std::mutex> lock(m_Mutex.getMutex());
        m_PCB._STATUS   = thread::thread_status::THREAD_STATUS_TERMINATE;
        m_PCB._TYPE     = thread::thread_type::THREAD_STOP_T;
    }

    void CThread::Join()
    {
        m_thread.join();
    }

    void CThread::Detach()
    {
        m_thread.detach();
    }

    pcb_t & CThread::getThreadInfo()
    {
        std::lock_guard<std::mutex> lock(m_Mutex.getMutex());
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