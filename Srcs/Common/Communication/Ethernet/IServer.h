/**
 *@file     IServer.h
 *@author   Jinhee.LEE
 *@brief    Server Interface Class 
 */

#ifndef _COMMUNICATION_ETHERNET_ISERVER_H_
#define _COMMUNICATION_ETHERNET_ISERVER_H_

namespace comm {
namespace eth {

    class IServer 
    {
    public:
        virtual ~IServer() { } 

    public:
        virtual void Socket()=0;
        virtual void Bind()=0;
        virtual void Listen()=0;
        virtual void Accept()=0;
        virtual void Close()=0;
    };

} /* namespace eth */
} /* namespace comm */

#endif /* _COMMUNICATION_ETHERNET_ISERVER_H_ */