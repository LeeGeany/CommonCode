/**
 * @file    CIPCManager.h
 * @author  jinhee.lee
 * @date    2025.03.28
 * @brief   Class of IPC Manager Header 
 * 
 * @copyright jinhee.lee
 */
 
 #ifndef    __APP_MANAGER_IPC_CIPCMANAGER_H__
 #define    __APP_MANAGER_IPC_CIPCMANAGER_H__

#include "App/CApp.h"

#include "Common/Common.h"
#include "Common/Communication/IPC/MsgQueue/CMsgQueue.h"

class CIPCManager
{
public:
    CIPCManager(CApp * pApp);
    virtual ~CIPCManager();

public:
    /**
     * @brief   Function that Initiate
     */
    void Initiate();

    /**
     * @brief Function that Insert MsgQueue
     * 
     * @param _MsgQueueName 
     * @param _pMsgQueue 
     * @return true 
     * @return false 
     */
    bool InsertMsgQueue(std::string _MsgQueueName, comm::ipc::msgQ::CMsgQueue * _pMsgQueue);

    /**
     * @brief 
     * 
     * @param _MsgQueueName 
     * @return comm::ipc::msgQ::CMsgQueue* 
     */
    comm::ipc::msgQ::CMsgQueue * FindMsgQueue(std::string _MsgQueueName);

private:
    /**
     * @brief 
     */
    CApp * m_pApp;

    /**
     * @brief 
     */
    std::unordered_map<std::string, comm::ipc::msgQ::CMsgQueue*> m_MsgQueueMap;
}; /* class CIPCManager */
#endif /*__APP_MANAGER_IPC_CIPCMANAGER_H__ */
