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

namespace unittest
{
    class CTest_Thread : public concurrent::thread::CThread
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
        virtual void PreOperate()   final;
        virtual void Operate()      final;
        virtual void PostOperate()  final;

    };
} /* unittest */

#endif /* __UNITTEST_TEST_THREAD_H__ */