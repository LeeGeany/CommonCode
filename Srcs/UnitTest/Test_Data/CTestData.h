/**
 * @file        CTestData.h
 * @author      jinhee.lee
 * @date        2025.03.05
 * @brief       Class of Data Test
 * 
 * @copyright   jinhee.lee
 */

#include "../../Common/DataSystem/CData.h"

namespace usr
{

#pragma pack(1)
    typedef struct stTestData
    {
        unsigned int uiTest1;
        unsigned int uiTest2;
    }stTestData_t;
#pragma unpack

    class CTestData : public CData<stTestData_t>
    {
    public:
        CTestData();;
        CTestData(CTestData&& _other);
        CTestData(stTestData_t&& _other);

    public:
        virtual stTestData_t& getData() final;
    }; /* class CTestData */
} /* namespace usr */