#include "./CThreadManager.h"

namespace app {
namespace mngr {
    CThreadManager::CThreadManager()
    {

    }

    CThreadManager::~CThreadManager()
    {

    }

    void CThreadManager::Initiate()
    {
        m_ThreadMap.clear();
    }

    bool CThreadManager::InsertThread(std::string _threadName, thread::CThread* _thread)
    {
        bool ret = true;
        auto item = m_ThreadMap.find(_threadName);
        if(item != m_ThreadMap.end())
        {
            ret = false;
        }
        else
        {
            m_ThreadMap[_threadName] = _thread;
        }
        return ret;
    }

    thread::CThread* CThreadManager::FindThread(std::string _threadName)
    {
        thread::CThread * tptr = nullptr;

        auto item = m_ThreadMap.find(_threadName);
        if(item != m_ThreadMap.end())
        {
            tptr = item->second;
        }
        
        return tptr;
    }

    bool CThreadManager::DeleteThread(std::string _threadName)
    {
        bool ret = false;
        for(auto it = m_ThreadMap.begin(); it != m_ThreadMap.end(); )
        {
            if(it->first == _threadName)
            {
                it = m_ThreadMap.erase(it);
                ret = true;
                break;
            }
            else
            {
                it++;
            }
        }
        return ret;
    }
} /* namespace mngr */
} /* namespace app */