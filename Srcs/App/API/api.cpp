#include "App/API/api.h"

namespace API
{
    namespace APP
    {
        void AppInit()
        {
            app::CApp::getInstance()->Initiate();
        }

        void CreateDataMngr()
        {
            app::CApp::getInstance()->CreateDataMngr();
        }
    } /* namespace app */

    namespace DATA
    {
        bool InsertData(const unsigned int _dataNo, data::IData * _data)
        {
            bool ret = true;
            data::IData * tptr = app::CApp::getInstance()->getDataMngr().FindData(_dataNo);
            
            if(tptr == nullptr)
            {
                ret = false;
            }
            else
            {
                app::CApp::getInstance()->getDataMngr().InsertData(_dataNo, _data);
            }
            return ret;
        }

        data::IData * FindData(const unsigned int _dataNo)
        {
            data::IData * tptr = app::CApp::getInstance()->getDataMngr().FindData(_dataNo); 
            return tptr;
        }
    } /* namespace data */

    namespace THREAD
    {
        bool InsertThread(std::string _threadName, thread::CThread * _pthread)
        {
            bool ret = true;
            thread::CThread * tptr = app::CApp::getInstance()->getThreadMngr().FindThread(_threadName);

            if(tptr == nullptr)
            {
                ret = false;
            }
            else
            {
                app::CApp::getInstance()->getThreadMngr().InsertThread(_threadName, _pthread);
            }
            return ret;
        }

        thread::CThread * FindThread(std::string _threadName)
        {
            thread::CThread * tptr = app::CApp::getInstance()->getThreadMngr().FindThread(_threadName);
            return tptr;
        }

        bool StartThread(std::string _threadName)
        {
            bool ret = app::CApp::getInstance()->getThreadMngr().StartThread(_threadName);
            return ret;
        }

        bool StopThread(std::string _threadName)
        {
            bool ret = app::CApp::getInstance()->getThreadMngr().StopThread(_threadName);
            return ret;
        }

        bool JoinThread(std::string _threadName)
        {
            bool ret = app::CApp::getInstance()->getThreadMngr().JoinThread(_threadName);
            return ret;
        }

        bool DetachThread(std::string _threadName)
        {
            bool ret = app::CApp::getInstance()->getThreadMngr().DetachThread(_threadName);
            return ret;
        }
    } /* namespace thread */
} /* namespace api */