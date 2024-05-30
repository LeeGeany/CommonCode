#include <Common/Logger/CLogger.h>

CLogger::CLogger(const CLogger& other)
{

}

CLogger& CLogger::GetInstance()
{
    CLogger* pLog = m_instance.load(std::memory_order_consume);
    return *m_instance;
}