#ifndef  __SOURCE_MYTHREAD_CSTRESSTHREAD_CPP_H__
#define __SOURCE_MYTHREAD_CSTRESSTHREAD_CPP_H__

#include "Common/Concurrent/Thread/CThread.h"

namespace usr
{
    class CStressThread : public thread::CThread
    {
    public:
        explicit CStressThread(std::string _threadName);
        virtual ~CStressThread();

    private:
        virtual void PreOperate() final;

        virtual void Operate() final;

        virtual void PostOperate() final;

    private:
        unsigned int counter;
    }; /* class CStressThread */
} /* namespace usr */
#endif /* __SOURCE_MYTHREAD_CSTRESSTHREAD_CPP_H__ */