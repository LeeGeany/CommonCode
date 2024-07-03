/**
 * @file    Test_Thread.h
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of Thread Unit Test Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __UNITTEST_TEST_THREAD_H__
#define __UNITTEST_TEST_THREAD_H__

#include <UnitTest/CUnitTest.h>

#include "CommonHeader.h"
#include <Common/Concurrent/Thread/CThread.h>

/**
 * @brief 
 */
void Thread1Main();

/**
 * @brief 
 */
void Thread2Main();

class CTest_Thread : public CUnitTest
{
public:
    /**
     * @brief Construct a new CTest_Thread object
     */
    CTest_Thread();

    /**
     * @brief Destroy the CTest_Thread object
     */
    virtual ~CTest_Thread();

private:
    /**
     * @brief Unit Test Function
     */
    virtual void UnitTest() final;



private:
    /**
     * @brief 
     */
    std::unique_ptr<concurrent::thread::CThread> Thread1;
    
    /**
     * @brief 
     */
    std::unique_ptr<concurrent::thread::CThread> Thread2;
};

#endif /* __UNITTEST_TEST_THREAD_H__ */