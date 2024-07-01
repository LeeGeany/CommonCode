#include "Test_MsgQueue.h"

void CUnitTest_MsgQueue::UnitTest()
{
    Initiate();

    SData sData = {100, 3.14, 0x123412341234};
    auto tData = comm::ipc::msgQ::CMsgQData<SData>(0, sData);
            std::cout << "here\n";

    //<< Error Occur Here       
    m_uptrMsg1->SendMsg<comm::ipc::msgQ::CMsgQData<SData>>(IPC_USR_DEF_ID::MSG_NUM_2, &tData, sizeof(tData));

    
    SData sData2;
    auto tData2 = comm::ipc::msgQ::CMsgQData<SData>(0, sData2);
    m_uptrMsg2->RecvMsg<comm::ipc::msgQ::CMsgQData<SData>>(&tData2);

    std::cout << tData.GetData().data.Data1 << std::endl;
    std::cout << tData.GetData().data.Data2 << std::endl;
    std::cout << tData.GetData().data.Data3 << std::endl;
}

void CUnitTest_MsgQueue::Initiate()
{
    m_uptrMsg1 = std::make_unique<comm::ipc::msgQ::CMsgQueue>(static_cast<int>(IPC_USR_DEF_ID::MSG_NUM_1));
    m_uptrMsg2 = std::make_unique<comm::ipc::msgQ::CMsgQueue>(static_cast<int>(IPC_USR_DEF_ID::MSG_NUM_2));

    int Msg1ID = m_uptrMsg1->GetMyMsgQID();
    int Msg2ID = m_uptrMsg2->GetMyMsgQID();
    
    m_uptrMsg1->InsertKey(IPC_USR_DEF_ID::MSG_NUM_1, Msg1ID);
    m_uptrMsg2->InsertKey(IPC_USR_DEF_ID::MSG_NUM_2, Msg2ID);

}