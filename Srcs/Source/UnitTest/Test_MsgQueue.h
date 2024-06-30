#include <CommonHeader.h>
#include <Common/Communication/IPC/MsgQueue/CMsgQueue.h>

enum IPC_ID
{
    MSG_NUM_1 = 0x1000,
    MSG_NUM_2, 
};

class CUnitTest_MsgQueue
{
public:
    CUnitTest_MsgQueue() = default;
    virtual ~CUnitTest_MsgQueue() = default;


public:
    void UnitTest();
    

private:
    void Initiate();


private:
    std::unique_ptr<comm::ipc::msgQ::CMsgQueue> m_uptrMsg1;
    std::unique_ptr<comm::ipc::msgQ::CMsgQueue> m_uptrMsg2;
};