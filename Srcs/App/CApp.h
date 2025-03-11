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
#include "App/Manager/Thread/CThreadManager.h"

namespace app
{
    class CApp
    {
    public:
        CApp();
        CApp(mngr::CDataManager * _DataMngr);
        virtual ~CApp();

    public:
        virtual void Initiate()=0;

    public:
        void CreateDataMngr();
        void setDataMngr(mngr::CDataManager* _pDataMngr);
        mngr::CDataManager& getDataMngr();


    private:
        /**
         * @brief
         */
        std::unique_ptr<mngr::CDataManager> m_upDataMngr;

        /**
         * @brief
         */
         //mngr::
    }; /* class CApp */
} /* namespace app */
#endif  /* __APP_CAPP_H__ */