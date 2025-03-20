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
         * @brief Function that Create Thread
         * @param   _threadName     Thread Name
         * @param   _type           Thread Type     
         * @return  bool            success - true / fail - false
         */
        template <typename T>
        bool CreateThread(std::string _threadName)
        {
            bool ret = true;
            auto item = m_ThreadMap.find(_threadName);
        
            if(item != m_ThreadMap.end())
            {
                ret = false;
            }
            else
            {
                if(std::is_base_of_v<thread::CThread, T> == true)
                {
                    std::unique_ptr<T> tThread = std::make_unique<T>(_threadName);

                    m_ThreadMap[_threadName] = tThread.release();
                }
                else
                {
                    ret = false;
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

        /**
         * @brief Function that Start thread
         * @param   _threadName             Key of Thread Map
         * @return  bool                    success - true / fail - false
         */
        bool StartThread(std::string _threadName);

        /**
         * @brief Function that Stop thread
         * @param   _threadName             Key of Thread Map
         * @return  bool                    success - true / fail - false
         */
        bool StopThread(std::string _threadName);

        /**
         * @brief Function that Join Thread
         * 
         * @param _threadName 
         * @return true 
         * @return false 
         */
        bool JoinThread(std::string _threadName);

        /**
         * @brief Function that Detach Thread
         * 
         * @param _threadName 
         * @return true 
         * @return false 
         */
        bool DetachThread(std::string _threadName);

        /**
         * @brief Get the Thread Info object
         * 
         * @param _threadName 
         * @return thread::pcb_t& 
         */
        thread::pcb_t & getThreadInfo(std::string _threadName);

    private:
        std::unordered_map<std::string, thread::CThread*> m_ThreadMap;
    
    }; /* class CThreadManager */
} /* namespace mngr */
} /* namespace app */
#endif  /* __APP_MANAGER_THREAD_CTHREADMANAGER_H__ */