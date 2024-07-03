/**
 * @file    CThread.h
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of Thread Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __COMMON_CONCURRENT_THREAD_CTHREAD_H__
#define __COMMON_CONCURRENT_THREAD_CTHREAD_H__

#include "CommonHeader.h"

#include <Common/Concurrent/IOperate.h>

namespace concurrent {
namespace thread {

class CThread : public concurrent::IOperate
{
public:
    /**
     * @brief Construct a new CThread object
     * @param Func
     */
    explicit CThread(std::function<void()> Func) noexcept;

    /**
     * @brief Destroy the CThread object
     */
    virtual ~CThread() noexcept;


public:
    /**
     * @brief 
     */
    void Start();

    /**
     * @brief 
     */
    void Join();

    /**
     * @brief 
     * @return
     */
    bool Joinable();

    /**
     * @brief 
     */
    void Detach();


private:
    /**
     * @brief Running Function
     */
    virtual void Operate() final;


private:
    /**
     * @brief Thread Instance
     */
    std::thread m_thread;

    /**
     * @brief User Define Operate Function
     */
    std::function<void()> m_Run;
};

} /* thread */
} /* concurrent */
#endif /* __COMMON_CONCURRENT_THREAD_CTHREAD_H__ */