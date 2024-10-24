/**
 * @file    Test_MsgQueue.h
 * @author  jinhee.lee
 * @date    2024.07.02
 * @brief   Class of Message Queue Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __UNITTEST_TEST_MSGQUEUE_H__
#define __UNITTEST_TEST_MSGQUEUE_H__

#include <CommonHeader.h>

#include <UnitTest/CUnitTest.h>
#include <Common/Communication/IPC/MsgQueue/CMsgQueue.h>

/**
 * @enum IPC_USR_DEF_ID
 * @brief Enum of IPC User Define ID 
 */
enum IPC_USR_DEF_ID
{
    MSG_NUM_1 = 0x1000,
    MSG_NUM_2, 
};

/**
 * @struct sData
 * @brief Structure of Data
 */
typedef struct sData
{
    int Data1;
    float Data2;
    unsigned long long Data3;
}SData;

/**
 * @class CUnitTest_MsgQueue
 * @brief Class of Message Queue Unit Test
 */
class CUnitTest_MsgQueue : public CUnitTest
{
public:
    /**
     * @brief CUnitTest_MsgQueue Constructor
     */
    CUnitTest_MsgQueue();

    /**
     * @brief CUnitTest_MsgQueue Destructor
     */
    virtual ~CUnitTest_MsgQueue();


private:
    /**
     * @brief Unit Test Function
     */
        virtual void UnitTest() final;


private:
    /**
     * @brief Message Queue Send Instance 
     */
    std::unique_ptr<comm::ipc::msgQ::CMsgQueue> m_uptrMsg1;

    /**
     * @brief Message Queue Receive Instance 
     */
    std::unique_ptr<comm::ipc::msgQ::CMsgQueue> m_uptrMsg2;
};

#endif /* __UNITTEST_TEST_MSGQUEUE_H__ */