/**
 * @file    Test_Signal.h
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of TCP Client Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __UNITTEST_TEST_SIGNAL_H__
#define __UNITTEST_TEST_SIGNAL_H__

#include <UnitTest/CUnitTest.h>

#include <Common/Communication/Signal/CSignal.h>

void SigHandler(int signal);

class CTest_Signal : public CUnitTest
{
public:
    /**
     * @brief Construct a new CTest_Signal object
     */
    CTest_Signal();

    /**
     * @brief Destroy the CTest_Signal object
     */
    virtual ~CTest_Signal();


public:
    /**
     * @brief Unit Test Function
     */
        virtual void UnitTest() final;

};
#endif /* __UNITTEST_TEST_SIGNAL_H__ */
