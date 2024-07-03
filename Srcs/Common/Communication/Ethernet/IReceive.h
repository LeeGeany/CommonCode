/**
 *@file     IServer.h
 *@author   Jinhee.LEE
 *@brief    Receive Interface Class 
 */

#ifndef __COMMUNICATION_IRECEIVE__
#define __COMMUNICATION_IRECEIVE__

class IReceive 
{
public:
    virtual ~IReceive(){};

public:
    virtual int Receive(char * Buffer, const unsigned int BufferSize)=0;
};

#endif /* __COMMUNICATION_IRECEIVE__ */