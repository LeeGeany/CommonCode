#ifndef __APP_API_API_H__
#define __APP_API_API_H__

#include "App/CApp.h"

namespace API
{
    namespace APP
    {
        /**
        * @brief   Function that Initiate All Manager
        */
        void AppInit();

        /**
        * @brief   Function that Initiate Data Manager;
        */
        void CreateDataMngr();

        /**
         * @brief Create a Thread Mngr object
         */
        void CreateThreadMngr();
    } /* namespace APP */


    namespace DATA
    {
        /**
         * @brief   Function that Create Data
         * @type    DataType        Data Class type 
         * @param   _dataNo         Key of Data
         * @return  bool            success - true / fail - false
         */
        template <typename DataType>
        bool CreateData(const unsigned int _dataNo)
        {
            bool ret = app::CApp::getInstance()->getDataMngr().CreateData<DataType>(_dataNo);
            return ret;
        }

        /**
         * @brief   Function that Insert Data
         * @param   _dataNo         Key of Data
         * @param   _data           Data class that based by IData
         * @return  bool            success - true / fail - false
         */
        bool InsertData(const unsigned int _dataNo, data::IData * _data);

        /**
         * @brief   Function that Find Data
         * @param   _dataNo         Key of Data
         * @return  data::IData*    success - data pointer / fail - nullptr
         */
        data::IData * FindData(const unsigned int _dataNo);
    } /* namespace DATA */

    namespace THREAD
    {
        /**
         * @brief   Function that Create Thread
         * @type    DataType        Data Class type 
         * @param   _dataNo         Key of Data
         * @return  bool            success - true / fail - false
         */
        template <typename ThreadType>
        bool CreateThread(std::string _threadName)
        {
            bool ret = app::CApp::getInstance()->getThreadMngr().CreateThread<ThreadType>(_threadName);
            return ret;
        }

        /**
         * @brief Function that Insert Thread
         * 
         * @param _threadName 
         * @param _thread 
         * @return true 
         * @return false 
         */
        bool InsertThread(std::string _threadName, thread::CThread * _thread);

        /**
         * @brief Function that Find Thread Instance
         * 
         * @param _threadName 
         * @return thread::CThread*
         * @return nullptr 
         */
        thread::CThread * FindThread(std::string _threadName);

        /**
         * @brief 
         * @param   _threadName     Key of Map
         * @return  true     Success 
         * @return  false    Fail
         */
        bool StartThread(std::string _threadName);

        /**
         * @brief Function that Stop Thread
         * 
         * @param _threadName 
         * @return true     Success 
         * @return false    Fail
         */
        bool StopThread(std::string _threadName);

        /**
         * @brief 
         * 
         * @param _threadName 
         * @return true     Success 
         * @return false    Fail
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
         * @brief Get the Thread Inof object
         * 
         * @param _threadName 
         * @return thread::pcb_t& 
         */
        thread::pcb_t & getThreadInfo(std::string _threadName);
    } /* namespace THREAD */
} /* namespace api */
#endif /* __APP_API_API_H__ */