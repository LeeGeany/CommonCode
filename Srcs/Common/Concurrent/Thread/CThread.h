#ifndef __COMMON_CONCURRENT_THREAD_CTHREAD_H__
#define __COMMON_CONCURRENT_THREAD_CTHREAD_H__

#include "CommonHeader.h"

#include <Common/Concurrent/IRun.h>
#include <Common/Concurrent/IOperate.h>

class CThread : public IRun, public IOperate
{
public:
    explicit CThread() noexcept;
    virtual ~CThread() noexcept;

protected:

    void Start();

    void Join();

    bool Joinable();

    void Detach();

private:
    virtual void Run() final;

private:
    std::thread m_thread;
};

#endif /* __COMMON_CONCURRENT_THREAD_CTHREAD_H__ */