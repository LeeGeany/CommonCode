/**
 * @file    IOperation.cpp
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of Operation Interface
 * 
 * @copyright jinhee.lee
 */

#ifndef __COMMON_CONCURRENT_IOPERATE_H__
#define __COMMON_CONCURRENT_IOPERATE_H__

namespace concurrent {

class IOperate
{
public:
    /**
     * @brief Destroy the IOperate object
     */
    virtual ~IOperate(){};

protected:
    /**
     * @brief Operation
     */
    virtual void Operate()=0;
};

} /* concurrent */
#endif /* __COMMON_CONCURRENT_IOPERATE_H__ */