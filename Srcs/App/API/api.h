#ifndef __APP_API_API_H__
#define __APP_API_API_H__

#include "App/CApp.h"

namespace api
{
    void AppInit()
    {
        app::CApp::getInstance()->Initiate();
    }

    void CreateDataMngr()
    {
        app::CApp::getInstance()->CreateDataMngr();
    }

    namespace data
    {
        template <typename DataType>
        bool CreateData(const unsigned int _dataNo)
        {
            bool ret = app::CApp::getInstance()->getDataMngr().CreateData<DataType>(_dataNo);
            return ret;
        }
    } /* namespace data */
} /* namespace api */
#endif /* __APP_API_API_H__ */