/**
 * @file    CDataManager.cpp
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Data Manager 
 * 
 * @copyright jinhee.lee
 */

#include "CDataManager.h"

namespace mngr
{
    static CDataManager::CDataManager * m_pDataIns = nullptr;

    CDataManager::CDataManager()
    {

    }


    CDataManager::~CDataManager()
    {

    }


    void CDataManager::Initiate()
    {
        m_Map.clear();
    }


    void CDataManager::InsertData(const unsigned int _dataName, data::CData * _data)
    {
        m_Map.insert(std::make_pair<unsigned int, data::CData*>(_dataID, _data));
    }


    data::CData* CDataManager::FindData(const unsigned int _dataName)
    {
        data::CData* ret = nullptr;
        auto item = m_Map.find(_dataName);
        
        if(item != m_Map.end())
        {
            ret = &(item->second);
        }

        return ret;
    }
} /* namespace mngr */