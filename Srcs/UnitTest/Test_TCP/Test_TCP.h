/**
 * @file    Test_TCP.h
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of TCP Client Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __UNITTEST_TEST_TCP_H__
#define __UNITTEST_TEST_TCP_H__

#include <UnitTest/CUnitTest.h>

#include "CommonHeader.h"

#include <Common/Communication/Ethernet/TCP/CTCPServer.h>
#include <Common/Communication/Ethernet/TCP/CTCPClient.h>

void MainServer();
void MainClient();

class CUnitTest_TCP : public CUnitTest
{
public:
    /**
     * @brief Construct a new CUnitTest_TCP object
     */
    CUnitTest_TCP();

    /**
     * @brief Destroy the CUnitTest_TCP object
     */
    virtual ~CUnitTest_TCP();


public:
    /**
     * @brief Unit Test Function
     */
        virtual void UnitTest() final;

};
#endif /* __UNITTEST_TEST_TCP_H__ */
