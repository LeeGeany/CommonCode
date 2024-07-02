#include "Test_MsgQueue.h"

void CUnitTest_MsgQueue::UnitTest()
{
    m_uptrMsg1 = std::make_unique<comm::ipc::msgQ::CMsgQueue>(static_cast<int>(IPC_USR_DEF_ID::MSG_NUM_1));
    m_uptrMsg2 = std::make_unique<comm::ipc::msgQ::CMsgQueue>(static_cast<int>(IPC_USR_DEF_ID::MSG_NUM_2));

    int Msg1ID = m_uptrMsg1->GetMyMsgQID();
    int Msg2ID = m_uptrMsg2->GetMyMsgQID();
    
    m_uptrMsg1->InsertKey(IPC_USR_DEF_ID::MSG_NUM_2, Msg2ID);
    m_uptrMsg2->InsertKey(IPC_USR_DEF_ID::MSG_NUM_1, Msg1ID);

    SData SendData;
    SData RecvData;

    SendData.Data1 = 1;
    SendData.Data2 = 3.14;
    SendData.Data3 = 0x13241234;

    m_uptrMsg1->SendMsg<SData>(IPC_USR_DEF_ID::MSG_NUM_2, 1, &SendData);
    

    m_uptrMsg2->RecvMsg<SData>(&RecvData, 1);

    std::cout << RecvData.Data1 << std::endl;
    std::cout << RecvData.Data2 << std::endl;
    std::cout << RecvData.Data3 << std::endl;
}
