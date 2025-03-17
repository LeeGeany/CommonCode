#include "App/API/api.h"

namespace API
{
    namespace APP
    {
        void AppInit()
        {
            app::CApp::getInstance()->Initiate();
        }

        void CreateDataMngr()
        {
            app::CApp::getInstance()->CreateDataMngr();
        }
    } /* namespace app */

    namespace DATA
    {
        bool InsertData(const unsigned int _dataNo, data::IData * _data)
        {
            bool ret = true;
            data::IData * tptr = app::CApp::getInstance()->getDataMngr().FindData(_dataNo);
            
            if(tptr == nullptr)
            {
                ret = false;
            }
            else
            {
                app::CApp::getInstance()->getDataMngr().InsertData(_dataNo, _data);
            }
            return ret;
        }

        data::IData * FindData(const unsigned int _dataNo)
        {
            data::IData * tptr = app::CApp::getInstance()->getDataMngr().FindData(_dataNo); 
            return tptr;
        }
    } /* namespace data */

    namespace thread
    {

    } /* namespace thread */
} /* namespace api */