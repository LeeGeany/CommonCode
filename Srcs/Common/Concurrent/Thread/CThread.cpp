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

CThread::CThread(std::function<void()> Func) noexcept
: m_Run(Func)
{

}
 
CThread::~CThread() noexcept
{

}

void CThread::Start()
{
    m_thread = std::thread(&CThread::Operate, this);
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

void CThread::Operate()
{
    m_Run();
}

} /* thread */
} /* concurrent */