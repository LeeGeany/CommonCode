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
    // Thread1 = std::make_unique<concurrent::thread::CThread>(Thread1Main);
    // Thread2 = std::make_unique<concurrent::thread::CThread>(Thread2Main);

    // Thread1->Start();
    // Thread2->Start();

    // Thread1->Join();
    // Thread2->Join();

    ThreadLoop1 = std::make_unique<concurrent::thread::CThreadLoop>(ThreadLoop1Main);
    ThreadLoop2 = std::make_unique<concurrent::thread::CThreadLoop>(ThreadLoop2Main);

    ThreadLoop1->Start();
    ThreadLoop2->Start();


    sleep(5);

    ThreadLoop1->Stop();
    ThreadLoop2->Stop();
}

void Thread1Main()
{
    for(int i = 0; i < 3; ++i)
        std::cout << "This is Thread1\n";
}

void Thread2Main()
{
    for(int i = 0; i < 3; ++i)
        std::cout << "This is Thread2\n";
}

void ThreadLoop1Main()
{
    std::cout << "This is Loop Thread1\n";
    sleep(1);
}

void ThreadLoop2Main()
{
    std::cout << "This is Loop Thread2\n";
    sleep(1);
}