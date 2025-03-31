/**
 * @file    CApp.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Application Source
 * 
 * @copyright jinhee.lee
 */

#include "App/CApp.h"

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
        m_upDataMngr = std::make_unique<CDataManager>();
    }

    // Create Thread Manaager if nullptr
    if(m_upThreadMngr.get() == nullptr)
    {
        m_upThreadMngr = std::make_unique<CThreadManager>();
    }

    // Create Thread Manaager if nullptr
    if(m_upEthernetMngr.get() == nullptr)
    {
        m_upEthernetMngr = std::make_unique<CEthernetManager>();
    }

    // Initiate Manager
    m_upDataMngr->Initiate();
    m_upThreadMngr->Initiate();
    m_upEthernetMngr->Initiate();    
}

void CApp::CreateDataMngr()
{
    m_upDataMngr = std::make_unique<CDataManager>();
    m_upDataMngr->Initiate();
}

void CApp::CreateThreadMngr()
{
    m_upThreadMngr = std::make_unique<CThreadManager>();
    m_upThreadMngr->Initiate();
}

void CApp::CreateEthernetMngr()
{
    m_upEthernetMngr = std::make_unique<CEthernetManager>();
    m_upEthernetMngr->Initiate();
}

void CApp::setDataMngr(CDataManager* _pDataMngr)
{
    m_upDataMngr.reset(_pDataMngr);
}

void CApp::setThreadMngr(CThreadManager* _pThreadMngr)
{
    m_upThreadMngr.reset(_pThreadMngr);
}

void CApp::setEthernetMngr(CEthernetManager* _pEthernetMngr)
{
    m_upEthernetMngr.reset(_pEthernetMngr);
}

CDataManager& CApp::getDataMngr()
{
    return *m_upDataMngr.get();
}

CThreadManager& CApp::getThreadMngr()
{
    return *m_upThreadMngr.get();
}

CEthernetManager& CApp::getEthernetMngr()
{
    return *m_upEthernetMngr.get();
}
