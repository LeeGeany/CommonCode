/**
 * @file    Test_MsgQueue.cpp
 * @author  jinhee.lee
 * @date    2024.07.02
 * @brief   Class of Message Queue Header
 * 
 * @copyright jinhee.lee
 */

#include "Test_MsgQueue.h"

CUnitTest_MsgQueue::CUnitTest_MsgQueue()
{

}

CUnitTest_MsgQueue::~CUnitTest_MsgQueue()
{

}

void CUnitTest_MsgQueue::UnitTest()
{
    // Make Send, Receive Message Queue Instance
    m_uptrMsg1 = std::make_unique<comm::ipc::msgQ::CMsgQueue>(static_cast<int>(IPC_USR_DEF_ID::MSG_NUM_1));
    m_uptrMsg2 = std::make_unique<comm::ipc::msgQ::CMsgQueue>(static_cast<int>(IPC_USR_DEF_ID::MSG_NUM_2));

    // Get Message Queue ID
    int Msg1ID = m_uptrMsg1->GetMyMsgQID();
    int Msg2ID = m_uptrMsg2->GetMyMsgQID();
    
    // Cross Insert Message Queue ID
    m_uptrMsg1->InsertKey(IPC_USR_DEF_ID::MSG_NUM_2, Msg2ID);
    m_uptrMsg2->InsertKey(IPC_USR_DEF_ID::MSG_NUM_1, Msg1ID);

    // Buffer Data
    SData SendData;
    SData RecvData;

    SendData.Data1 = 1;
    SendData.Data2 = 3.14;
    SendData.Data3 = 0x13456789;

    // Send Message Queue Data
    m_uptrMsg1->SendMsg<SData>(IPC_USR_DEF_ID::MSG_NUM_2, 1, &SendData);
    
    // Receive Message Queue Data
    m_uptrMsg2->RecvMsg<SData>(&RecvData, 1);

    // Print Result
    std::cout << RecvData.Data1 << std::endl;
    std::cout << RecvData.Data2 << std::endl;
    std::cout << RecvData.Data3 << std::endl;
}
