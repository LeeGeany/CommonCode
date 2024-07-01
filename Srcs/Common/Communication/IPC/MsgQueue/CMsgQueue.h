#ifndef __COMMON_COMMUNICATION_IPC_MSGQUEUE_CMSGQUEUE_H__
#define __COMMON_COMMUNICATION_IPC_MSGQUEUE_CMSGQUEUE_H__

#include <CommonHeader.h>

#include <Common/Communication/ISend.h>
#include <Common/Communication/IReceive.h>

namespace comm {
namespace ipc {
namespace msgQ {

class CMsgQueue
{
public:
    /**
     * @brief CMsgQueue Constructor 
     * @param UsrDefID User Define ID (Example : Enum, Define etc...)
     */
    explicit CMsgQueue(int UsrDefID) noexcept;

    /**
     * @brief CMsgQueue Destructor
     */
    virtual ~CMsgQueue() noexcept;


public:
    /**
     * @brief Send Message
     * @param DestID
     * @param Buffer
     * @param BufferSize
     * @return int Sucess or Fail
     */
    template <typename DATA>
    int SendMsg(int DestUsrDefID, const DATA * Buffer, const unsigned int BufferSize)
    {
        int SendMsgQID = GetOtherMsgQID(DestUsrDefID);
        return msgsnd(SendMsgQID, Buffer, sizeof(DATA), IPC_NOWAIT);
    }

    /**
     * @brief Receive Message
     * @param
     * @param
     * @param
     * @return int Sucess or Fail
     */
    template <typename DATA>
    int RecvMsg(DATA * Buffer, unsigned int msgType=0)
    {
        return msgrcv(m_MsgID, Buffer, sizeof(DATA), msgType, IPC_NOWAIT);
    }

    /**
     * @brief Insert Other Process Msg Queue ID
     * @param destKey Destination Process
     * @param MsgQID
     */
    void InsertKey(int UserDefID, int MsgID);

    /**
     * @brief
     */
    int GetMyMsgQID();

    /**
     * @brief
     */
    int GetOtherMsgQID(unsigned int DestUsrDefID);


private:
    /**
     * @brief 
     */
    int m_MsgID;

    /**
     * @brief key=UsrDefineID , value=MsgID 
     */
    std::unordered_map<int, int> m_umID;
};

} /* namespace msgQ */
} /* namespace ipc */
} /* namespace comm */
#endif /* __COMMON_COMMUNICATION_IPC_MSGQUEUE_CMSGQUEUE_H__ */