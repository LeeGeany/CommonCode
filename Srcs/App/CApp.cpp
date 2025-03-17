#include "App/CApp.h"

namespace app
{
    CApp* CApp::m_pApp = nullptr;
    
    CApp::CApp()
    {

    }

    CApp::~CApp()
    {
        
    }

    void CApp::Initiate()
    {
        // Create Manager if nullptr
        if(m_upDataMngr.get() == nullptr)
        {
            m_upDataMngr = std::make_unique<mngr::CDataManager>();
        }

        // Initiate Manager
        m_upDataMngr->Initiate();        
    }

    void CApp::CreateDataMngr()
    {
        m_upDataMngr = std::make_unique<mngr::CDataManager>();
    }

    void CApp::setDataMngr(mngr::CDataManager* _pDataMngr)
    {
        m_upDataMngr.reset(_pDataMngr);
    }

    mngr::CDataManager& CApp::getDataMngr()
    {
        return *m_upDataMngr.get();
    }
} /* namespace app */