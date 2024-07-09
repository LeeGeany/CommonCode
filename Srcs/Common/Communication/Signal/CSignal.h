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
public:
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
    void UsrSignal(int SigType, std::function<void(int)> Handler);

    /**
     * @brief 
     */

    /**
     * @brief
     * @param Signal
     * @return 
     */
    int SignalBlock(int Signal);

private:
    sigset_t m_Set;
};

} /* namespace sig */
} /* namespace comm */

#endif /* __COMMON_COMMUNICATION_SIGNAL_CSIGNAL_H__ */