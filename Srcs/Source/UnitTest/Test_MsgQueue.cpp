#include "Test_MsgQueue.h"

void CUnitTest_MsgQueue::UnitTest()
{

}

void CUnitTest_MsgQueue::Initiate()
{
    m_uptrMsg1 = std::make_unique<comm::ipc::msgQ::CMsgQueue>(static_cast<int>(IPC_USR_DEF_ID::MSG_NUM_1));
    m_uptrMsg2 = std::make_unique<comm::ipc::msgQ::CMsgQueue>(static_cast<int>(IPC_USR_DEF_ID::MSG_NUM_2));

    int Msg1ID = m_uptrMsg1->GetMyMsgQID();
    int Msg2ID = m_uptrMsg2->GetMyMsgQID();
    
    
}