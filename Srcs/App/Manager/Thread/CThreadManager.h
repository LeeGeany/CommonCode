/**
 * @file    CDataManager.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Class of Thread Manager
 * 
 * @copyright jinhee.lee
 */
#ifndef __APP_MANAGER_THREAD_CTHREADMANAGER_H__
#define __APP_MANAGER_THREAD_CTHREADMANAGER_H__

namespace mngr
{
    class CThreadManager
    {
    public:
        CThreadManager();
        virtual ~CThreadManager();

    public:
        virtual void Initiate();

    protected:
        /**
         * @brief
         */
        void CreateThread();

        /**
         * @brief
         */         
        void InsertThread();

        /**
         * @brief
         */
        

    } /* class CThreadManager */
} /* namespace mngr */


#endif  __APP_MANAGER_THREAD_CTHREADMANAGER_H__