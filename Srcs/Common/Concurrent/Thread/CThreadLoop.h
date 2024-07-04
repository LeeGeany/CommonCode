/**
 * @file    CThreadLoop.h
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of Thread Loop Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __COMMON_CONCURRENT_THREAD_CTHREADLOOP_H__
#define __COMMON_CONCURRENT_THREAD_CTHREADLOOP_H__

#include "CommonHeader.h"

#include <Common/Concurrent/ILoop.h>

namespace concurrent {
namespace thread {

class CThreadLoop : public concurrent::ILoop
{
public:
    /**
     * @brief Construct a new CThread object
     * @param Func
     */
    explicit CThreadLoop(std::function<void()> Func) noexcept;

    /**
     * @brief Destroy the CThread object
     */
    virtual ~CThreadLoop() noexcept;


public:
    /**
     * @brief 
     */
    void Start();

    /**
     * @brief 
     */
    void Stop();

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

    /**
     * @brief 
     */
    virtual void PreLoop() override;

    /**
     * @brief brief
     */
    virtual void PostLoop() override;


private:
    /**
     * @brief
     */
    bool m_RunningFlag;

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
#endif /* __COMMON_CONCURRENT_THREAD_CTHREADLOOP_H__ */