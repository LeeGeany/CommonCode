#include "App/API/api.h"

#include "Common/Concurrent/Affinity/CSetThreadCoreMask.h"

namespace API
{
    namespace APP
    {
        void AppInit()
        {
            CApp::getInstance()->Initiate();
        }

        void CreateDataMngr()
        {
            CApp::getInstance()->CreateDataMngr();
        }

        void CreateThreadMngr()
        {
            CApp::getInstance()->CreateThreadMngr();
        }

    } /* namespace app */



    namespace DATA
    {
        bool InsertData(const unsigned int _dataNo, data::IData * _data)
        {
            bool ret = true;
            data::IData * tptr = CApp::getInstance()->getDataMngr().FindData(_dataNo);
            
            if(tptr == nullptr)
            {
                ret = false;
            }
            else
            {
                CApp::getInstance()->getDataMngr().InsertData(_dataNo, _data);
            }
            return ret;
        }

        data::IData * FindData(const unsigned int _dataNo)
        {
            data::IData * tptr = CApp::getInstance()->getDataMngr().FindData(_dataNo); 
            return tptr;
        }
    } /* namespace DATA */



    namespace THREAD
    {
        bool InsertThread(std::string _threadName, thread::CThread * _pthread)
        {
            bool ret = true;
            thread::CThread * tptr = CApp::getInstance()->getThreadMngr().FindThread(_threadName);

            if(tptr == nullptr)
            {
                ret = false;
            }
            else
            {
                CApp::getInstance()->getThreadMngr().InsertThread(_threadName, _pthread);
            }
            return ret;
        }

        thread::CThread * FindThread(std::string _threadName)
        {
            thread::CThread * tptr = CApp::getInstance()->getThreadMngr().FindThread(_threadName);
            return tptr;
        }

        bool StartThread(std::string _threadName)
        {
            bool ret = CApp::getInstance()->getThreadMngr().StartThread(_threadName);
            return ret;
        }

        bool StopThread(std::string _threadName)
        {
            bool ret = CApp::getInstance()->getThreadMngr().StopThread(_threadName);
            return ret;
        }

        bool JoinThread(std::string _threadName)
        {
            bool ret = CApp::getInstance()->getThreadMngr().JoinThread(_threadName);
            return ret;
        }

        bool DetachThread(std::string _threadName)
        {
            bool ret = CApp::getInstance()->getThreadMngr().DetachThread(_threadName);
            return ret;
        }

        thread::pcb_t & getThreadInfo(std::string _threadName)
        {
            return CApp::getInstance()->getThreadMngr().getThreadInfo(_threadName);
        }

        bool setThreadCoreMask(std::string _threadName, unsigned int _coreMask)
        {
            bool ret = true;
            thread::CThread * tptr = CApp::getInstance()->getThreadMngr().FindThread(_threadName);

            if(tptr == nullptr)
            {
                ret = false;
            }
            else
            {
                affinity::CSetThreadCoreMask(tptr, _coreMask);
            }
            return ret;
        }
    } /* namespace THREAD */
} /* namespace API */