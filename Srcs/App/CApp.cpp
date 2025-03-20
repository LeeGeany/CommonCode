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

        // Create Thread Manaager if nullptr
        if(m_upThreadMngr.get() == nullptr)
        {
            m_upThreadMngr = std::make_unique<mngr::CThreadManager>();
        }

        // Initiate Manager
        m_upDataMngr->Initiate();
        m_upThreadMngr->Initiate();        
    }

    void CApp::CreateDataMngr()
    {
        m_upDataMngr = std::make_unique<mngr::CDataManager>();
    }

    void CApp::CreateThreadMngr()
    {
        m_upThreadMngr = std::make_unique<mngr::CThreadManager>();
    }

    void CApp::setDataMngr(mngr::CDataManager* _pDataMngr)
    {
        m_upDataMngr.reset(_pDataMngr);
    }

    void CApp::setDataMngr(mngr::CThreadManager* _pThreadMngr)
    {
        m_upThreadMngr.reset(_pThreadMngr);
    }

    mngr::CDataManager& CApp::getDataMngr()
    {
        return *m_upDataMngr.get();
    }

    mngr::CThreadManager& CApp::getThreadMngr()
    {
        return *m_upThreadMngr.get();
    }
} /* namespace app */