/**
 * @file        CMain.h
 * @author      jinhee.lee
 * @date        2025.03.12
 * @brief       Main Class
 * 
 * @copyright   jinhee.lee
 */

#ifndef __SOURCE_MAIN_CMAIN_H__
#define __SOURCE_MAIN_CMAIN_H__

#include "App/CApp.h"

namespace usr
{
    class CMain : public app::CApp
    {
    public:
        CMain();
        virtual ~CMain();
        
    public:
        virtual void Initiate() final;



    };
} /* usr */
#endif  /* __SOURCE_MAIN_CMAIN_H__ */
