/**
 *@file     IClient.h
 *@author   Jinhee.LEE
 *@brief    Client Interface Class 
 */

#ifndef _COMMUNICATION_ETHERNET_ICLIENT_H_
#define _COMMUNICATION_ETHERNET_ICLIENT_H_

namespace comm {
namespace eth {

    class IClient
    {
    public:
        virtual ~IClient() { }

    public:
        virtual int Socket()=0;
        virtual int Connect()=0;
        virtual int Close()=0;
    };

} /* namespace eth */
} /* namespace comm */

#endif /* _COMMUNICATION_ETHERNET_ICLIENT_H_ */