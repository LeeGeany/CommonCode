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
    m_umID.insert({UserDefID, MsgID});
}

int CMsgQueue::GetMyMsgQID()
{
    return m_MsgID;
}

int CMsgQueue::GetOtherMsgQID(unsigned int DestUsrDefID)
{
    return m_umID.find(DestUsrDefID)->second;
}

} /* namespace msgQ */
} /* namespace ipc */
} /* namespace comm */