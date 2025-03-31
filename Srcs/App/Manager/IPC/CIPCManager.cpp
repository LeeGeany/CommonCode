/**
 * @file    CIPCManager.cpp
 * @author  jinhee.lee
 * @date    2025.03.28
 * @brief   Class of IPC Manager Source
 * 
 * @copyright jinhee.lee
 */

#include "App/Manager/IPC/CIPCManager.h"

CIPCManager::CIPCManager(CApp * pApp)
: m_pApp{pApp}
{

}

CIPCManager::~CIPCManager()
{

}

void CIPCManager::Initiate()
{
    m_MsgQueueMap.clear();
}

bool CIPCManager::InsertMsgQueue(std::string _MsgQueueName, comm::ipc::msgQ::CMsgQueue * _pMsgQueue)
{
    bool ret = true;
    auto item = m_MsgQueueMap.find(_MsgQueueName);
    if(item != m_MsgQueueMap.end())
    {    
        ret = false;
    }
    else
    {
        m_MsgQueueMap[_MsgQueueName] = _pMsgQueue;
    }
    return ret;
}

comm::ipc::msgQ::CMsgQueue * CIPCManager::FindMsgQueue(std::string _MsgQueueName)
{
    comm::ipc::msgQ::CMsgQueue * tptr = nullptr;
    auto item = m_MsgQueueMap.find(_MsgQueueName);
    if(item != m_MsgQueueMap.end())
    {    
        tptr = item->second;
    }
    return tptr;
}