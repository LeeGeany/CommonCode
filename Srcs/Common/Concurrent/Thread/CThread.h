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

//#include "CommonHeader.h"
#include "Common/Common.h"

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
        THREAD_STATUS_WAIT,
        THREAD_STATUS_RUNNING,
        THREAD_STATUS_TERMINATE
    };

    typedef struct process_control_block_t
    {
        std::string                 _NAME;
        thread::thread_type         _TYPE;
        thread::thread_status       _STATUS;
        unsigned int                _RUN_TIME;
    }pcb_t;

    class CThread : public concurrent::IOperate
    {
    public:
        /**
         * @brief Construct a new CThread object
         */
        CThread(std::string _threadName);
        CThread(std::string _threadName, thread_once_t _type);
        CThread(std::string _threadName, thread_loop_t _type);

        /**
         * @brief Destroy the CThread object
         */
        virtual ~CThread() noexcept;

    
    public:
        /**
         * @brief   Function that run Thread
         */
        void thread_Start();

        /**
         * @brief   Function that stop Thread (use in loop thread) 
         */
        void thread_Stop();

        /**
         * @brief 
         */
        void Join();

        /**
         * @brief 
         */
        void Detach();

        /**
         * @brief 
         * @return  pcb_t       return thread infomation
         */
        pcb_t & getThreadInfo();


    private:
        void Run();


    private:
        /**
         * @brief Thread Instance
         */
        std::thread m_thread;

        /**
         * @brief   lock for changing m_threadType
         */
        mutex::CMutex m_Mutex;

        /**
         * @brief   pcb_t
         */
        pcb_t           m_PCB;

    }; /* class CThread*/
} /* thread */
#endif /* __COMMON_CONCURRENT_THREAD_CTHREAD_H__ */