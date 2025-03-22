#include "Source/myThread/CConsoleThread.h"

#include "App/API/api.h"
#include "Source/myThread/CStressThread.h"

namespace usr 
{
    CConsoleThread::CConsoleThread(std::string _threadName)
    : thread::CThread(_threadName, thread::thread_loop)
    {

    }

    CConsoleThread::~CConsoleThread()
    {

    }

    void CConsoleThread::PreOperate()
    {
        std::cout << "Console On\n";
    }

    void CConsoleThread::Operate()
    {
        std::cout << " > ";
        std::cin >> m_Cmd;
        
        if(m_Cmd == "exit")
        {
            thread_Stop();
        }
        else if(m_Cmd == "thread1")
        {
            API::THREAD::CreateThread<CStressThread>("thread1");
            API::THREAD::StartThread("thread1");
            API::THREAD::DetachThread("thread1");
        }
        else if(m_Cmd == "thread2")
        {
            API::THREAD::CreateThread<CStressThread>("thread2");
            API::THREAD::StartThread("thread2");
            API::THREAD::DetachThread("thread2");
        }
        else if(m_Cmd == "thread3")
        {
            API::THREAD::CreateThread<CStressThread>("thread3");
            API::THREAD::StartThread("thread3");         
            API::THREAD::DetachThread("thread3");  
        }
        else if(m_Cmd == "thread4")
        {
            API::THREAD::CreateThread<CStressThread>("thread4");
            API::THREAD::StartThread("thread4"); 
            API::THREAD::DetachThread("thread4");           
        }
        else if(m_Cmd == "stop1")
        {
            API::THREAD::StopThread("thread1");
        }
        else if(m_Cmd == "stop2")
        {
            API::THREAD::StopThread("thread2");
        }
        else if(m_Cmd == "stop3")
        {
            API::THREAD::StopThread("thread3");
        }
        else if(m_Cmd == "stop4")
        {
            API::THREAD::StopThread("thread4");
        }
        else
        {
            std::cout << "   " << m_Cmd << '\n';
        }
    }

    void CConsoleThread::PostOperate()
    {

        std::cout << "Console Off\n";
    }
} /* namespace usr */