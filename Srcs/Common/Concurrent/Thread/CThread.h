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
#include <Common/Concurrent/Mutex/CMutex.h>

namespace thread 
{
    struct thread_loop_t    {   explicit thread_loop_t()    = default;      };
    struct thread_once_t    {   explicit thread_once_t()    = default;      };
    struct thread_count_t   {   explicit thread_count_t()   = default;      };
    struct thread_time_t    {   explicit thread_time_t()    = default;      };

    constexpr thread_loop_t   thread_loop;
    constexpr thread_once_t   thread_once;
    constexpr thread_count_t  thread_count;
    constexpr thread_time_t   thread_time;

    enum class thread_type
    {
        THREAD_LOOP_T,
        THREAD_ONCE_T,
        THREAD_COUNT_T,
        THREAD_TIME_T,
        THREAD_STOP_T,
    };

    enum class thread_status
    {
        THREAD_STATUS_NEW,
        THREAD_STATUS_READY,
        THREAD_STATUS_WAIT,
        THREAD_STATUS_RUNNING,
        THREAD_STATUS_TERMINATE
    };

    typedef struct process_control_block_t
    {
        thread::thread_type         _TYPE;
        thread::thread_status       _STATUS;
        unsigned int                _LOOP_CNT;
    }pcb_t;

    class CThread : public concurrent::IOperate
    {
    public:
        /**
         * @brief Construct a new CThread object
         */
        explicit CThread() noexcept;
        explicit CThread(thread_once_t _type);
        explicit CThread(thread_loop_t _type);

        /**
         * @brief Destroy the CThread object
         */
        virtual ~CThread() noexcept;
    
    public:
        /**
         * @brief 
         */
        void thread_Start();

        /**
         * @brief 
         */
        void thread_Stop();


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
         * @brief   Thread Type
         */
        thread_type m_threadType;

        /**
         * @brief   lock for changing m_threadType
         */
        mutex::CMutex m_Mutex;

    }; /* class CThread*/
} /* thread */
#endif /* __COMMON_CONCURRENT_THREAD_CTHREAD_H__ */