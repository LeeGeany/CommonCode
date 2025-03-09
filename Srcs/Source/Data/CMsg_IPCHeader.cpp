#include "Source/Data/CMsg_IPCHeader.h"

#include "Common/Common.h"

namespace msg
{
    CMsg_IPCHeader::CMsg_IPCHeader()
    {

    }

    CMsg_IPCHeader::CMsg_IPCHeader(const struct stMsg_IPCHeader&& other)
    {
        m_Data = std::move(other);
    }

    CMsg_IPCHeader::CMsg_IPCHeader(const CMsg_IPCHeader&& other)
    {
        m_Data = std::move(other.m_Data);
    }

    CMsg_IPCHeader::~CMsg_IPCHeader()
    {

    }

    stMsg_IPCHeader& CMsg_IPCHeader::getData()
    {
        return m_Data;
    }

    void CMsg_IPCHeader::setSource(unsigned short _source)
    {
        m_Data._Source = _source;
    }

    void CMsg_IPCHeader::setDestination(unsigned short _dest)
    {
        m_Data._dest = _dest;
    }

    void CMsg_IPCHeader::setCommand(unsigned short _command)
    {
        m_Data._command = _command;
    }

    unsigned short CMsg_IPCHeader::getSource()
    {
        return m_Data._Source;
    }

    unsigned short CMsg_IPCHeader::getDestination()
    {
        return m_Data._dest;
    }

    unsigned short CMsg_IPCHeader::getCommand()
    {
        return m_Data._command;
    }
} /* namespace msg */