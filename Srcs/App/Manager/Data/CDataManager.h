/**
 * @file    CDataManager.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Data Manager
 * 
 * @copyright jinhee.lee
 */

#ifndef __APP_MANAGER_DATA_CDATAMANAGER_H__
#define __APP_MANAGER_DATA_CDATAMANAGER_H__

#include "Common/Common.h"
#include "Common/DataSystem/CData.h"
#include "Common/DataSystem/IData.h"

namespace app {
namespace mngr {
    
    class CDataManager
    {
    public:
        /**
         * @brief   CDataManager Constructor
         */
        CDataManager();
        
        /**
         * @brief   CDataManager Destructor
         */
        virtual ~CDataManager();

    public:
        /**
         * @brief   Function that return this Instance (Singleton)
         * @return  this
         */
        static CDataManager* getInstance()
        {
             if(nullptr == m_pDataIns)
             {
                 m_pDataIns = new CDataManager();
             }
             return m_pDataIns;
        }

    public:
        /**
         * @brief   Initiate Manager
         */
        virtual void Initiate();

    public:
        /**
         * @brief   Insert Data
         * @param   _dataName   Key of Data
         * @param   _data       value of Data
         */
        void InsertData(const unsigned int _dataName, data::IData * _data);

        /** 
         * @brief   Create Data
         * @param   _dataName   Key of Data
         */
        template <typename T>
        bool CreateData(const unsigned int _dataName)
        {
            bool ret = true;
            auto item = m_Map.find(_dataName);
            
            if(item != m_Map.end())
            {
                ret = false;
            }
            else
            {           
                std::unique_ptr<T> tData = std::make_unique<T>();
                if(std::is_base_of_v<data::IData, T> == true)
                {
                    m_Map[_dataName] = tData.release();
                }
                else
                {
                    ret = false;
                }
            }
            return ret;
        }

        /**
         * @brief   Find Data
         * @param   _dataName   Key of Data
         */
        data::IData* FindData(const unsigned int _dataName);

    private:
        /** 
         * @brief   Singleton Instance   
         */
        static CDataManager * m_pDataIns;

        /**
         * @brief   Data Container
         */
        std::unordered_map<unsigned int, data::IData*> m_Map;
    }; /* class CDataManager*/
} /* namespace mngr */
} /* namespace app */
#endif /* __APP_MANAGER_DATA_CDATAMANAGER_H__ */