#ifndef __SOURCE_DATA_CDATATEST_H__
#define __SOURCE_DATA_CDATATEST_H__

#include "Source/Data/DataType.h"
#include "App/Manager/Data/CData.h"

class CDataTest : public CData<stTest>
{
public:
    CDataTest();
    CDataTest(const stTest&& other);
    CDataTest(const CDataTest&& other);
    virtual ~CDataTest();

public:
    virtual stTest& getData() final;

public:
    void setTest1(unsigned int value);
    void setTest2(unsigned int value);

    unsigned int getTest1();
    unsigned int getTest2();
};

#endif /* __SOURCE_DATA_CDATATEST_H__ */