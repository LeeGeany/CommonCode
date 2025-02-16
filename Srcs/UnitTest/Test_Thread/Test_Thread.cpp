/**
 * @file    Test_Thread.cpp
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   CClass of Thread Unit Test Source
 * 
 * @copyright jinhee.lee
 */

#include "Test_Thread.h"

namespace unittest 
{
    CTest_Thread::CTest_Thread()
    {

    }

    CTest_Thread::~CTest_Thread()
    {

    }

    void CTest_Thread::PreOperate()
    {
        std::cout << "PreOperate\n";
    }

    void CTest_Thread::Operate()
    {
        std::cout << "Operate\n";
    }

    void CTest_Thread::PostOperate()
    {
        std::cout << "PostOperate\n";
    }
} /* namespace unittest */