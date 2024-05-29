/**
 *@file     IServer.h
 *@author   Jinhee.LEE
 *@brief    Send Interface Class 
 */

#ifndef __COMMUNICATION_ISEND_H__
#define __COMMUNICATION_ISEND_H__

namespace comm {

class ISend 
{
public:
    virtual ~ISend(){};

public:
    virtual int Send(const char* Buffer, const unsigned int BufferSize)=0;
};

} /* namespace comm */

#endif /* __COMMUNICATION_ISEND_H__ */