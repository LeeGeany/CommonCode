/**
 * @file    CApp.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Application Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __APP_CAPP_H__
#define __APP_CAPP_H__

#include "Common/Common.h"

#include "App/Manager/Data/CDataManager.h"
#include "App/Manager/Thread/CThreadManager.h"
#include "App/Manager/Ethernet/CEthernetManager.h"

class CApp
{
public:
    CApp();
    virtual ~CApp();

public:
    static CApp * getInstance()
    {
        if(m_pApp == nullptr)
        {
            m_pApp = new CApp();
        }
        return m_pApp;
    }

public:
    void Initiate();


public:
    // Create
    void CreateDataMngr();
    void CreateThreadMngr();
    void CreateEthernetMngr();

    // Set
    void setDataMngr(CDataManager* _pDataMngr);
    void setThreadMngr(CThreadManager* _pThreadMngr);
    void setEthernetMngr(CEthernetManager* _pEthernetMngr);

    // Get
    CDataManager& getDataMngr();
    CThreadManager& getThreadMngr();
    CEthernetManager& getEthernetMngr();


private:
    /**
     * @brief   This class Instance (Singleton)
     */
    static CApp* m_pApp;


private:
    /**
     * @brief   Data Manager Instance
     */
    std::unique_ptr<CDataManager> m_upDataMngr;

    /**
     * @brief   Thread Manager Instance
     */
    std::unique_ptr<CThreadManager> m_upThreadMngr;

    /**
     * @brief   Ethernet Manager Instance
     */
    std::unique_ptr<CEthernetManager> m_upEthernetMngr;
}; /* class CApp */
#endif  /* __APP_CAPP_H__ */