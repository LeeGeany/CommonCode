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

    // type empty class
    struct thread_loop_t
    {
        explicit thread_loop_t() = default;
    };

    struct thread_once_t
    {
        explicit thread_once_t() = default;
    };

    struct thread_count_t
    {
        explicit thread_count_t() = default;
    }

    /**
     * @brief alive for time
     */
    struct thread_time_t
    {
        explicit thread_time_t = default;
    }

    class CThread : public concurrent::IOperate
    {
    public:
        /**
         * @brief Construct a new CThread object
         */
        explicit CThread() noexcept;

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
         * @brief   Checking this thread can Join
         * @return  If thread can Join return true, However cannot to join return false
         */
        bool Joinable();

        /**
         * @brief 
         */
        void Detach();


    private:
        void Run();


    private:
        /**
         * @brief Thread Instance
         */
        std::thread m_thread;

        /**
         * @brief   Loop State
         */
        bool m_isLoop;
    };

} /* thread */
} /* concurrent */
#endif /* __COMMON_CONCURRENT_THREAD_CTHREAD_H__ */