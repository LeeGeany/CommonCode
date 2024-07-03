/**
 * @file    ILoop.cpp
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of Opeartion Interface
 * 
 * @copyright jinhee.lee
 */

#ifndef __COMMON_CONCURRENT_ILOOP_H__
#define __COMMON_CONCURRENT_ILOOP_H__

namespace concurrent {

class ILoop
{
public:
    virtual ~ILoop(){};

protected:
    /**
     * @brief Before Loop Operation 
     */
    virtual void PreLoop()=0;

    /**
     * @brief Loop Operation
     */
    virtual void Operate()=0;

    /**
     * @brief After Loop Operation
     */
    virtual void PostLoop()=0;
};

} /* concurrent */
#endif /* __COMMON_CONCURRENT_ILOOP_H__ */