/**
 * @file    Test_TCP.h
 * @author  jinhee.lee
 * @date    2024.07.05
 * @brief   Class of TCP Client Header
 * 
 * @copyright jinhee.lee
 */

#include "Test_Signal.h"

CTest_Signal::CTest_Signal()
{

}

CTest_Signal::~CTest_Signal()
{

}

void CTest_Signal::UnitTest()
{
    comm::sig::CSignal::GetSignalMgr()->Insert(SIGINT, SigHandler);

    while(1)
    {

    }

}


void SigHandler(int signal)
{
    std::cout << signal << " Signal Occur\n" << std::endl;
}
