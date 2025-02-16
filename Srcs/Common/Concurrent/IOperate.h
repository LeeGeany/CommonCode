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

namespace concurrent 
{

    class IOperate
    {
    public:
        /**
         * @brief Destroy the IOperate object
         */
        virtual ~IOperate(){};


    protected:
        /**
         * @brief Previous Operate
         */
        virtual void PreOperate()=0;

        /**
         * @brief Operation
         */
        virtual void Operate()=0;

        /**
         * @brief   Post Operate
         */
        virtual void PostOperate()=0;
    }; /* class IOperate */

} /* concurrent */
#endif /* __COMMON_CONCURRENT_IOPERATE_H__ */