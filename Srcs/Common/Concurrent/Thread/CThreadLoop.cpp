/**
 * @file    CThread.cpp
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of Thread Source
 * 
 * @copyright jinhee.lee
 */

#include "CThreadLoop.h"

namespace concurrent {
namespace thread {

CThreadLoop::CThreadLoop(std::function<void()> Func) noexcept
: m_Run(Func)
, m_RunningFlag(false)
{
    
}
 
CThreadLoop::~CThreadLoop() noexcept
{

}

void CThreadLoop::Start()
{
    m_RunningFlag = true;
    m_thread = std::thread(&CThreadLoop::Operate, this);
}

void CThreadLoop::Stop()
{
    m_RunningFlag = false;
    m_thread.join();
}

void CThreadLoop::Join()
{
    m_thread.join();
}

bool CThreadLoop::Joinable()
{
    return m_thread.joinable();
}

void CThreadLoop::Detach()
{
    m_thread.detach();
}

void CThreadLoop::Operate()
{
    PreLoop();

    while(m_RunningFlag == true)
    {
        m_Run();
    }
    
    PostLoop();
}

void CThreadLoop::PreLoop()
{

}

void CThreadLoop::PostLoop()
{

}

} /* thread */
} /* concurrent */