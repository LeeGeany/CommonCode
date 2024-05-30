#include <Common/Concurrent/Thread/CThread.h>

CThread::CThread() noexcept
{
    
}
 
CThread::~CThread() noexcept
{
    std::cout << "Thread Destructor\n";
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
    PreStart();
    OnStart();
    PostStart();
}