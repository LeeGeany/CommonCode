/**
 *@file     IServer.h
 *@author   Jinhee.LEE
 *@brief    Send Interface Class 
 */

#ifndef __COMMUNICATION_ISEND__
#define __COMMUNICATION_ISEND__

namespace comm {

class ISend 
{
public:
    virtual ~ISend(){};

public:
    virtual int Send(const char* Buffer, int BufferSize)=0;
};

} /* namespace comm */

#endif /* __COMMUNICATION_ISEND__ */