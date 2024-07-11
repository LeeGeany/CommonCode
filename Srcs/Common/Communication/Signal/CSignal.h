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
     * @brief Get the Signal Mgr object
     * @return CSignal& 
     */
    static CSignal & GetSignalMgr()
    {
        if(m_Instance.get() == nullptr)
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            if(m_Instance.get() == nullptr)
            {
                m_Instance = std::make_unique<CSignal>();
            }
        }

        return *(m_Instance.get());
    }


public:
    /**
     * @brief Initiate Signal
     */
    void Initiate();

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
    static std::unique_ptr<CSignal> m_Instance;

    /**
     * @brief
     */
    static std::mutex m_Mutex;

    /**
     * @brief 
     */
    sigset_t m_Set;

};

} /* namespace sig */
} /* namespace comm */

#endif /* __COMMON_COMMUNICATION_SIGNAL_CSIGNAL_H__ */