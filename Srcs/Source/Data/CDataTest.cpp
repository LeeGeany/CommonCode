#include "Source/Data/CDataTest.h"

namespace usr
{
    CDataTest::CDataTest()
    : m_Data{0}
    {

    }

    CDataTest::CDataTest(const stTest&& other)
    {
        m_Data = std::move(other);
    }

    CDataTest::CDataTest(const CDataTest&& other)
    {
        m_Data = std::move(other.m_Data);
    }

    CDataTest::~CDataTest()
    {

    }

    stTest& CDataTest::getData()
    {
        return m_Data;
    }

    void CDataTest::setTest1(unsigned int value)
    {
        m_Data.test1 = value;
    }

    void CDataTest::setTest2(unsigned int value)
    {
        m_Data.test2 = value;
    }

    unsigned int CDataTest::getTest1()
    {
        return m_Data.test1;
    }

    unsigned int CDataTest::getTest2()
    {
        return m_Data.test2;
    }
}