/**
 * @file    SDataStruct.h
 * @author  jinhee.lee
 * @date    2024.10.21
 * @brief   Gather all Data Struture
 * 
 * @copyright jinhee.lee
 */

#ifndef __SOURCE_DATA_DATATYPE_H__
#define __SOURCE_DATA_DATATYPE_H__

#pragma pack(1)

namespace msg
{
    struct stMsg_IPCHeader
    {
        unsigned short _Source        :   16;
        unsigned short _dest          :   16;
        unsigned short _command       :   16;
        unsigned short _reserved      :   16;
    };

    enum class MsgNo : const unsigned int
    {
        IPC_HEADER,
    };
}


#pragma unpack();
#endif /* __SOURCE_DATA_DATATYPE_H__ */