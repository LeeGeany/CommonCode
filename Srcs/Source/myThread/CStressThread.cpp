#include "Source/myThread/CStressThread.h"

namespace usr
{
    CStressThread::CStressThread(std::string _threadName)
    : thread::CThread(_threadName, thread::thread_loop)
    {

    }

    CStressThread::~CStressThread()
    {

    }

    void CStressThread::PreOperate()
    {
        counter = 0;
    }

    void CStressThread::Operate()
    {
        counter++;
    }

    void CStressThread::PostOperate()
    {

    }    

} /* namespace usr */