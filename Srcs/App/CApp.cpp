#include "App/CApp.h"

namespace app
{
    CApp::CApp()
    {

    }

    CAapp::CApp(mngr::CDataManager * _DataMngr)
    : m_DataMngr{_DataMngr}
    {

    }

    CApp::~CApp()
    {

    }

    CApp::App_Initiate()
    {
        m_DataMngr.Initiate();
    }

} /* namespace app */