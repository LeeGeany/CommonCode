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

void CSignal::Initiate()
{
    sigemptyset(&m_Set);
}

void CSignal::Insert(int SigType, void(*Handler)(int))
{
    int Ret = 0;
    Ret = sigaddset(&m_Set, SigType);
    
    if(Ret == 0)
    {
        signal(SigType, Handler);
    }
    else
    {

    }
    
    sigprocmask(SIG_SETMASK, &m_Set, NULL);
}

void CSignal::Delete(int SigType)
{
    int Ret = 0;
    Ret = sigdelset(&m_Set, SigType);

    sigprocmask(SIG_SETMASK, &m_Set, NULL);
}

int CSignal::Block(int SigType)
{
    int Ret = 0;
    sigset_t tSet;

    Ret = sigaddset(&tSet, SigType);
    sigprocmask(SIG_BLOCK, &tSet, NULL);

    return Ret;
}

int CSignal::BlockAll()
{
    sigprocmask(SIG_BLOCK, &m_Set, NULL);
}

int CSignal::Release(int SigType)
{
    int Ret = 0;
    sigset_t tSet;
    
    Ret = sigaddset(&tSet, SigType);
    sigprocmask(SIG_BLOCK, &tSet, NULL);

    return Ret;
}

int CSignal::ReleaseAll()
{

}

} /* namespace sig */
} /* namespace comm */