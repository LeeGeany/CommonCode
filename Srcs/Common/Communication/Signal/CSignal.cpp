/**
 * @file    CSignal.cpp
 * @author  jinhee.lee
 * @date    2024.07.09
 * @brief   Class of Signal Source
 * 
 * @copyright jinhee.lee
 */

#include "CSignal.h"

namespace comm {
namespace sig {

CSignal::CSignal()
{
    
}

CSignal::~CSignal()
{

}

void CSignal::UsrSignal(int SigType, std::function<void(int)> Handler)
{
    void(*const * pFunc)(int)  = Handler.target<void(*)(int)>();
    signal(SigType, *pFunc);
}

int CSignal::SignalBlock(int Signal)
{

}


} /* namespace sig */
} /* namespace comm */