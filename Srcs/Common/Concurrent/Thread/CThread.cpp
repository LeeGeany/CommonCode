/**
 * @file    CThread.cpp
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of Thread Source
 * 
 * @copyright jinhee.lee
 */

#include "CThread.h"

namespace concurrent {
namespace thread {

    CThread::CThread() noexcept
    : m_isLoop(false)
    {

    }
    
    CThread::~CThread() noexcept
    {

    }

    void CThread::Start()
    {
        m_thread = std::thread(&CThread::Run, this);
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
        while(m_isLoop);

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
} /* concurrent */