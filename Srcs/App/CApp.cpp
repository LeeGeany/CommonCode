#include "App/CApp.h"

namespace app
{
    CApp::CApp()
    {

    }

    CApp::CApp(mngr::CDataManager * _DataMngr)
    : m_upDataMngr{_DataMngr}
    {

    }

    CApp::~CApp()
    {

    }

    void CApp::App_Initiate()
    {
        m_upDataMngr->Initiate();
    }

} /* namespace app */