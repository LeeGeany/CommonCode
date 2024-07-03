/**
 * @file    CUnitTest.cpp
 * @author  jinhee.lee
 * @date    2024.07.03
 * @brief   Class of Message Queue Header
 * 
 * @copyright jinhee.lee
 */

#include "CUnitTest.h"

CUnitTest::CUnitTest()
: RunningFlag(false)
{

}

CUnitTest::~CUnitTest()
{

}

void CUnitTest::PrintRunningTime()
{
    std::chrono::duration<double> sec = m_End - m_Start;
    std::cout << "\n================ Result ================\n";
    std::cout << "Program Running Result : " << (RunningFlag == true ? "Success" : "Fail") << "\n"; 
    std::cout << "Program Running Time(Sec) : " << sec.count() << "\n"; 
}

void CUnitTest::Run()
{
    try
    {
        m_Start = std::chrono::system_clock::now();
        UnitTest();
        m_End = std::chrono::system_clock::now();

        RunningFlag = true;
    }
    catch(const std::exception& e)
    {
        
        std::cerr << e.what() << '\n';
    }

    PrintRunningTime();
}