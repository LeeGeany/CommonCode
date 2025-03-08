/**
 * @file        CData.h
 * @author      jinhee.lee
 * @date        2024.10.21
 * @brief       Class of Data Interface
 * 
 * @copyright   jinhee.lee
 */

#ifndef __COMMON_DATASYSTEM_CDATA_H__
#define __COMMON_DATASYSTEM_CDATA_H__

#include "./IData.h"

namespace data
{
    template <typename T> 
    class CData : public IData
    {
    protected:
        CData() = default;
        virtual ~CData() = default;

    public:
        virtual T& getData()=0;

    protected:
        T m_Data;
    }; /* namespace */
} /* namespace data */
#endif  /* __COMMON_DATASYSTEM_CDATA_H__ */