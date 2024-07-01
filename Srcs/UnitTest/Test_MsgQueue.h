#include <CommonHeader.h>

#include <Common/Communication/IPC/MsgQueue/CMsgQueue.h>
#include <Common/Communication/IPC/MsgQueue/MsgQData.h>

enum IPC_USR_DEF_ID
{
    MSG_NUM_1 = 0x1000,
    MSG_NUM_2, 
};

typedef struct sData
{
    int Data1;
    float Data2;
    unsigned long long Data3;
}SData;


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