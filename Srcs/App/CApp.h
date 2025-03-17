/**
 * @file    CApp.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Application
 * 
 * @copyright jinhee.lee
 */

#ifndef __APP_CAPP_H__
#define __APP_CAPP_H__

#include "Common/Common.h"
#include "App/Manager/Data/CDataManager.h"

namespace app
{
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

        // Set
        void setDataMngr(mngr::CDataManager* _pDataMngr);
        
        // Get
        mngr::CDataManager& getDataMngr();


    private:
        /**
         * @brief   This class Instance (Singleton)
         */
        static CApp* m_pApp;


    private:
        /**
         * @brief   Data Manager Instance
         */
        std::unique_ptr<mngr::CDataManager> m_upDataMngr;
    }; /* class CApp */
} /* namespace app */
#endif  /* __APP_CAPP_H__ */