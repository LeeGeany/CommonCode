#ifndef __SOURCE_MYTHREAD_CCONSOLETHREAD_H__
#define __SOURCE_MYTHREAD_CCONSOLETHREAD_H__

#include "Common/Common.h"
#include "Common/Concurrent/Thread/CThread.h"

namespace usr
{
    class CConsoleThread : public thread::CThread
    {
    public:
        CConsoleThread(std::string _threadName);
        virtual ~CConsoleThread();

    public:
        virtual void PreOperate() final;

        virtual void Operate() final;

        virtual void PostOperate() final;

    private:
        std::string m_Cmd;

    }; /* class CConsoleThread */
} /* namespace usr */

#endif /* __SOURCE_MYTHREAD_CCONSOLETHREAD_H__ */