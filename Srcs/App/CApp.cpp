#include "App/CApp.h"

namespace app
{
    CApp::CApp()
    {

    }

    CApp::CApp(mngr::CDataManager * _DataMngr)
    : m_pDataMngr{_DataMngr}
    {

    }

    CApp::~CApp()
    {

    }

    mngr::CDataManager& CApp::getDataMngr()
    {
        return *m_pDataMngr;
    }
} /* namespace app */