/**
 *@file     CTCPServer.h
 *@author   Jinhee.LEE
 *@brief    TCP Server Class Header
 */

#ifndef __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPSERVER_H__
#define __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPSERVER_H__

#include <CommonHeader.h>

#include <Common/Communication/Ethernet/ISend.h>
#include <Common/Communication/Ethernet/IReceive.h>

namespace comm {
namespace eth {
namespace tcp {

    class CTCPServer : public IReceive, public ISend
    {
    public:
        CTCPServer(const short LocalPort);
        virtual ~CTCPServer();

    public:
        int Socket();
        int Bind();
        int Listen();
        int Accept();
        void Close();
    
        virtual int Send(const char* Buffer, const unsigned int BufferSize) override;
        virtual int Receive(char * Buffer, const unsigned int BufferSize) override;

    public:
        void Initiate();
        bool IsConnect();

    private:
        int             m_sockfd;
        int             m_Connectfd;
        sockaddr_in     m_sServerAddr;
        socklen_t       m_addrlen;
    };

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */
#endif /* __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPSERVER_H__ */