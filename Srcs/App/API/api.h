#ifndef __APP_API_API_H__
#define __APP_API_API_H__

#include "App/CApp.h"

namespace API
{
    namespace APP
    {
        /**
        * @brief   Function that Initiate All Manager
        */
        void AppInit();

        /**
        * @brief   Function that Initiate Data Manager;
        */
        void CreateDataMngr();
    } /* namespace APP */


    namespace DATA
    {
        /**
         * @brief   Function that Create Data
         * @type    DataType        Data Class type 
         * @param   _dataNo         Key of Data
         * @return  bool            success - true / fail - false
         */
        template <typename DataType>
        bool CreateData(const unsigned int _dataNo)
        {
            bool ret = app::CApp::getInstance()->getDataMngr().CreateData<DataType>(_dataNo);
            return ret;
        }

        /**
         * @brief   Function that Insert Data
         * @param   _dataNo         Key of Data
         * @param   _data           Data class that based by IData
         * @return  bool            success - true / fail - false
         */
        bool InsertData(const unsigned int _dataNo, data::IData * _data);

        /**
         * @brief   Function that Find Data
         * @param   _dataNo         Key of Data
         * @return  data::IData*    success - data pointer / fail - nullptr
         */
        data::IData * FindData(const unsigned int _dataNo);
    } /* namespace DATA */

    namespace THREAD
    {

    } /* namespace THREAD */
} /* namespace api */
#endif /* __APP_API_API_H__ */