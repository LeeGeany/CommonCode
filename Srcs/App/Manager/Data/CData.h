/**
 * @file    CData.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Data Interface
 * 
 * @copyright jinhee.lee
 */

#ifndef __APP_MANAGER_DATA_CDATA_H__
#define __APP_MANAGER_DATA_CDATA_H__

#include <App/Manager/Data/IData.h>

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
};


#endif /* __APP_MANAGER_DATA_CDATA_H__ */