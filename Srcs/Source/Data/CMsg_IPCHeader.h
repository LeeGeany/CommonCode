/**
 * @file    SDataStruct.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Gather all Data Struture
 * 
 * @copyright jinhee.lee
 */


#ifndef __SOURCE_DATA_CMSG_IPCHEADER_H__
#define __SOURCE_DATA_CMSG_IPCHEADER_H__

#include "Common/DataSystem/CData.h"
#include "Source/Data/SDataStruct.h"

namespace msg {
    class CMsg_IPCHeader : public data::CData<struct stMsg_IPCHeader>
    {
    public:
        CMsg_IPCHeader();
        CMsg_IPCHeader(const stMsg_IPCHeader&& other);
        CMsg_IPCHeader(const CMsg_IPCHeader&& other);
        virtual ~CMsg_IPCHeader();

        
    public:
        virtual stMsg_IPCHeader& getData() final;


    public:
        void setSource(unsigned short _source);
        void setDestination(unsigned short _dest);
        void setCommand(unsigned short _command);

        unsigned short getSource();
        unsigned short getDestination();
        unsigned short getCommand();
    };
} /* namespace msg */
#endif /* __SOURCE_DATA_CMSG_IPCHEADER_H__ */