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