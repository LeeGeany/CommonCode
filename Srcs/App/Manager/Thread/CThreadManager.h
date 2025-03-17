/**
 * @file    CThreadManager.h
 * @author  jinhee.lee
 * @date    2025.03.17
 * @brief   Class of Thread Manager
 * 
 * @copyright jinhee.lee
 */
 
#ifndef __APP_MANAGER_THREAD_CTHREADMANAGER_H__
#define __APP_MANAGER_THREAD_CTHREADMANAGER_H__

#include "Common/Common.h"
#include "Common/Concurrent/Thread/CThread.h"

namespace app {
namespace mngr {
    class CThreadManager
    {
    public:
        CThreadManager();
        virtual ~CThreadManager();

    public:
        /**
         * @brief   Function that Initiate
         */
        void Initiate();

        /**
         * @brief
         */
        template <typename T>
        bool CreateThread(std::string _threadName, thread::thread_type _type)
        {
            bool ret = true;
            auto item = m_ThreadMap.find(_threadName);
        
            if(item != m_ThreadMap.end())
            {
                
            }
            else
            {
                std::unique_ptr<T> tThread = std::make_unique<T>();
                if(std::is_base_of_v<thread::CThread, T> == true)
                {
                    if(_type == thread::thread_type::THREAD_ONCE_T)
                    {
                        tThread = std::make_unique<thread::CThread>(thread::thread_once);
                    }
                    else if(_type == thread::thread_type::THREAD_LOOP_T)
                    {
                        tThread = std::make_unique<thread::CThread>(thread::thread_loop);
                    }
                    else if(_type == thread::thread_type::THREAD_COUNT_T)
                    {
                        // Count
                    }
                    else if(_type == thread::thread_type::THREAD_TIME_T)
                    {
                        // Timer
                    }
                    else
                    {
                        ret = false;
                    }
                }


                if(true == ret)
                {
                    m_ThreadMap[_threadName] = tThread.release();
                }
            }

            return ret;
        }

        /**
         * @brief   Function that Insert Thread
         * @param   _threadName         Key of map
         * @param   _thread             Value of map
         * @return  bool                success - true / fail - false
         */         
        bool InsertThread(std::string _threadName, thread::CThread* _thread);

        /**
         * @brief   Function that Find Thread
         * @param   _threadName             Key of Thread Map
         * @return  thread::CThread*        success - CThread* / fail - nullptr
         */
        thread::CThread * FindThread(std::string _threadName);

        /**
         * @brief   Funtion that Delete Thread
         * @param   _threadName             Key of Thread Map
         * @return  bool                    success - true / fail - false
         */
        bool DeleteThread(std::string _threadName);

    private:
        std::unordered_map<std::string, thread::CThread*> m_ThreadMap;
    
    }; /* class CThreadManager */
} /* namespace mngr */
} /* namespace app */
#endif  /* __APP_MANAGER_THREAD_CTHREADMANAGER_H__ */