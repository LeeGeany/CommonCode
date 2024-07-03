/**
 * @file    Test_Thread.cpp
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   CClass of Thread Unit Test Source
 * 
 * @copyright jinhee.lee
 */

#include "Test_Thread.h"

CTest_Thread::CTest_Thread()
{

}

CTest_Thread::~CTest_Thread()
{

}

void CTest_Thread::UnitTest()
{
    std::function<void()> f1 = Thread1Main;
    auto f2 = Thread2Main;

    Thread1 = std::make_unique<concurrent::thread::CThread>(f1);
    Thread2 = std::make_unique<concurrent::thread::CThread>(f2);

    Thread1->Start();
    Thread2->Start();

    Thread1->Join();
    Thread2->Join();
}

void Thread1Main()
{
    std::cout << "This is Thread1\n";
}

void Thread2Main()
{
    std::cout << "This is Thread2\n";
}