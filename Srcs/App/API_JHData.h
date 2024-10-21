/**
 * @file    CDataManager.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Data Manager
 * 
 * @copyright jinhee.lee
 */

#ifndef __APP_APP_JHDATA_H__
#define __APP_APP_JHDATA_H__

#include "App/Manager/Data/CDataManager.h"

namespace API
{
    class JHData
    {
    public:
        JHData() = default;

    public:
        template<typename T>
        static void CreateData(unsigned int DataNo)
        {
            T * temp = new T(); 
            CDataManager::getInstance()->InsertData(DataNo, temp);
        }

        static void InsertData(unsigned int DataNo, IData* Data)
        {
            CDataManager::getInstance()->InsertData(DataNo, Data);
        }

        template<typename T> 
        static T& FindData(unsigned int DataNo)
        {
            IData * temp = CDataManager::getInstance()->FindData(DataNo);
            return *(dynamic_cast<T*>(temp));
        }
    };
}

#endif /* __APP_APP_JHDATA_H__ */