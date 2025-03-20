#include "Source/myThread/CConsoleThread.h"

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