/**
 * @file    CMsgQueue.cpp
 * @author  jinhee.lee
 * @date    2024.07.02
 * @brief   Class of Message Queue Header
 * 
 * @copyright jinhee.lee
 */

#include "CMsgQueue.h"

namespace comm {
namespace ipc {
namespace msgQ {

CMsgQueue::CMsgQueue(int UsrDefID) noexcept
{
    m_MsgID = msgget(static_cast<key_t>(UsrDefID), IPC_CREAT|0666);
}

CMsgQueue::~CMsgQueue() noexcept
{

}

void CMsgQueue::InsertKey(int UserDefID, int MsgID)
{
    try
    {
        m_umID.insert({UserDefID, MsgID});
    }
    catch(const std::exception& e)
    {
        //< Make Log
        std::cout << e.what() << '\n';
    }
}

int CMsgQueue::GetMyMsgQID()
{
    return m_MsgID;
}

int CMsgQueue::GetOtherMsgQID(unsigned int DestUsrDefID)
{
    int ret = 0;
    auto item = m_umID.find(DestUsrDefID);

    if(item != m_umID.end())
    {
        ret = item->second;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

} /* namespace msgQ */
} /* namespace ipc */
} /* namespace comm */