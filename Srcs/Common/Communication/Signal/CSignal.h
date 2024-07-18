/**
 * @file    CSignal.h
 * @author  jinhee.lee
 * @date    2024.07.09
 * @brief   Class of Signal Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __COMMON_COMMUNICATION_SIGNAL_CSIGNAL_H__
#define __COMMON_COMMUNICATION_SIGNAL_CSIGNAL_H__

#include <CommonHeader.h>

namespace comm {
namespace sig { 

class CSignal
{
private:
    /**
     * @brief Construct a new CSignal object
     */
    CSignal();

    /**
     * @brief Destroy the CSignal object
     */
    virtual ~CSignal();


public:
    /**
     * @brief 
     * @param Signal
     * @param
     * @return
     */
    void Insert(int SigType, void(*Handler)(int));

    /**
     * @brief 
     */
    void Delete(int SigType);

    /**
     * @brief
     * @param SigType
     * @return 
     */
    int Block(int SigType);

    /**
     * @brief
     * @return 
     */
    int BlockAll();

    /**
     * @brief 
     * @param SigType
     * @return
     */
    int Release(int SigType);

    /**
     * @brief 
     * @return
     */
    int ReleaseAll();


private:
    /**
     * @brief 
     */
    static CSignal * m_pInstance;

    /**
     * @brief
     */
    static std::mutex m_Mutex;

    /**
     * @brief 
     */
    sigset_t m_Set;

public:
    /**
     * @brief Get the Signal Mgr object
     * @return CSignal& 
     */
    static CSignal * GetSignalMgr()
    {
        if(m_pInstance == nullptr)
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            if(m_pInstance == nullptr)
            {
                m_pInstance = new CSignal();
            }
        }

        return m_pInstance;
    }
};

} /* namespace sig */
} /* namespace comm */
#endif /* __COMMON_COMMUNICATION_SIGNAL_CSIGNAL_H__ */