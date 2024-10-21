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

#include <memory>
#include <unordered_map>

#include <App/Manager/Data/IData.h>

class CDataManager
{
private:
    CDataManager(){};
    virtual ~CDataManager(){};

public:
    static CDataManager* getInstance()
    {
        static CDataManager * pDataManager = new CDataManager();
        return pDataManager;
    }

public:
    void InsertData(const unsigned int DataNo, IData * data);
    IData* FindData(const unsigned int DataNo);
    
private:
    std::unordered_map<unsigned int, IData*> m_Map;
};

#endif /* __APP_MANAGER_DATA_CDATAMANAGER_H__ */