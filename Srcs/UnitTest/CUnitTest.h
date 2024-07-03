/**
 * @file    CUnitTest.h
 * @author  jinhee.lee
 * @date    2024.07.03
 * @brief   Class of Message Queue Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __UNITTEST_CUNITTEST_H__
#define __UNITTEST_CUNITTEST_H__

#include <CommonHeader.h>

class CUnitTest
{
public:
    /**
     * @brief Construct a new CUnitTest object
     */
    CUnitTest();

    /**
     * @brief Destroy the CUnitTest object
     * 
     */
    virtual ~CUnitTest();

    /**
     * @brief Run Program
     */
    void Run();


protected:
    /**
     * @brief Print Running Time
     * 
     */
    void PrintRunningTime();

    /**
     * @brief Override This Function to do UnitTest
     */
    virtual void UnitTest()=0;

private:
    /**
     * @brief Run Success or Fail Flag
     */
    bool RunningFlag;

    /**
     * @brief Program Running Start Time
     */
    std::chrono::system_clock::time_point m_Start;
    
    /**
     * @brief Program Running End Time
     */
    std::chrono::system_clock::time_point m_End;
};
#endif /* __UNITTEST_CUNITTEST_H__ */