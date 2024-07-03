/**
 * @file    CMsgQueue.h
 * @author  jinhee.lee
 * @date    2024.07.02
 * @brief   Class of Message Queue Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __COMMON_COMMUNICATION_IPC_MSGQUEUE_CMSGQUEUE_H__
#define __COMMON_COMMUNICATION_IPC_MSGQUEUE_CMSGQUEUE_H__

#include <CommonHeader.h>

namespace comm {
namespace ipc {
namespace msgQ {

/**
 * @class CMsgQueue
 * @brief Class of Linux IPC Message Queue
 */
class CMsgQueue
{
public:
    /**
     * @brief CMsgQueue Constructor 
     * @param UsrDefID User Define Message Queue ID (Example : Enum, Define etc...)
     */
    explicit CMsgQueue(int UsrDefID) noexcept;

    /**
     * @brief CMsgQueue Destructor
     */
    virtual ~CMsgQueue() noexcept;


public:
    /**
     * @brief Send Message
     * @param DestUsrDefID Destination Message Queue Instance User Define ID
     * @param MsgType Message Type
     * @param Buffer Send Data Buffer
     * @return int Sucess or Fail
     */
    template <typename DATA>
    int SendMsg(int DestUsrDefID, int MsgType, const DATA * Buffer)
    {
        // Step.1 Make Message
        SMsgQData<DATA> tMsg;
        tMsg.msgType = MsgType;
        tMsg.data = *Buffer;

        // Step.2 Find Destination
        int SendMsgQID = GetOtherMsgQID(DestUsrDefID); 

        // Step.3 Send Message
        int ret = msgsnd(SendMsgQID, &tMsg, sizeof(DATA), IPC_NOWAIT);

        // Step.4 Return Result
        return ret;
    }

    /**
     * @brief Receive Message
     * @param Buffer Receive Data Buffer
     * @param msgType Message Type
     * @return Sucess or Fail
     */
    template <typename DATA>
    int RecvMsg(DATA * Buffer, unsigned int msgType=0)
    {
        // Make Message
        SMsgQData<DATA> tMsg;

        // Receive Message
        int ret =  msgrcv(m_MsgID, &tMsg, sizeof(DATA), msgType, IPC_NOWAIT);
    
        // Copy Data
        *Buffer = tMsg.data;

        // Flush Queue
        ret = msgctl(m_MsgID, IPC_RMID, NULL);

        // Return Result
        return ret;
    }

    /**
     * @brief Insert Other Process Msg Queue ID
     * @param UserDefID Other Message Queue Instance User Define ID
     * @param MsgQID Other Message Queue Instance ID (Create By msgget(...) Function)
     */
    void InsertKey(int UserDefID, int MsgID);

    /**
     * @brief Get This Instance Message Queue ID (Create By msgget(...) Function)
     * @return This Instance Message Queue ID
     */
    int GetMyMsgQID();

    /**
     * @brief Get Other Instance Message Queue ID (Insert By InsertKey(...) Function)
     * @return Other Instance Message Queue ID or Error -1
     */
    int GetOtherMsgQID(unsigned int DestUsrDefID);


private:
    /**
     * @brief Message Queue ID (Create By msgget(...) Function)
     */
    int m_MsgID;

    /**
     * @brief key=UsrDefineID , value=MsgID 
     */
    std::unordered_map<int, int> m_umID;

    /**
     * @struct SMsgQData
     * @brief Structure of Linux IPC Message Queue
     */
    template <typename DATA>
    struct SMsgQData
    {
        long msgType;
        DATA data;
    };
};

} /* namespace msgQ */
} /* namespace ipc */
} /* namespace comm */
#endif /* __COMMON_COMMUNICATION_IPC_MSGQUEUE_CMSGQUEUE_H__ */