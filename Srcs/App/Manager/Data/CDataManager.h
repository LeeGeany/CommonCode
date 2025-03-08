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

#include "../../../Common/Common.h"

namespace mngr
{
    class CDataManager
    {
    private:
        CDataManager();
        virtual ~CDataManager();


    public:
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

    protected:
        /**
         * @brief   Create Data
         * @param   _dataName   Key of Data
         */
        template <typename T>
        void CreateData(const unsigned int _dataName)
        {
            std::unique_ptr<T> tData = std::make_unique<T>();
            m_Map.InsertData(_dataName, tData.release());
        }

        /**
         * @brief   Insert Data
         * @param   _dataName   Key of Data
         * @param   _data       value of Data
         */
        void InsertData(const unsigned int _dataName, data::CData * _data)

        /**
         * @brief   Find Data
         * @param   _dataName   Key of Data
         */
        data::CData* FindData(const unsigned int _dataName)

    private:
        /** 
         * @brief   Singleton Instance   
         */
        static CDataManager * m_pDataIns;

        /**
         * @brief   Data Container
         */
        std::unordered_map<unsigned int, data::CData*> m_Map;
    }; /* class CDataManager*/
} /* namespace mngr */
#endif /* __APP_MANAGER_DATA_CDATAMANAGER_H__ */