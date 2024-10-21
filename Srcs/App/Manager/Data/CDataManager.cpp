/**
 * @file    CDataManager.cpp
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Data Manager 
 * 
 * @copyright jinhee.lee
 */

#include "CDataManager.h"

void CDataManager::InsertData(const unsigned int DataNo, IData * data)
{
    m_Map.insert({DataNo, data});
}

IData* CDataManager::FindData(const unsigned int DataNo)
{
    return m_Map[DataNo];

}