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

CSignal * CSignal::m_pInstance = nullptr;
std::mutex CSignal::m_Mutex;

CSignal::CSignal()
{
    sigemptyset(&m_Set);
}

CSignal::~CSignal()
{

}

void CSignal::Insert(int SigType, void(*Handler)(int))
{
    int Ret = 0;
    Ret = sigaddset(&m_Set, SigType);
    
    if(Ret == 0)
    {
        sigprocmask(SIG_SETMASK, &m_Set, NULL);
        signal(SigType, Handler);
    }
    
    
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
    int ret = sigprocmask(SIG_BLOCK, &m_Set, NULL);
    return ret;
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
    int ret = sigprocmask(SIG_UNBLOCK, &m_Set, NULL);
    return ret;
}

} /* namespace sig */
} /* namespace comm */