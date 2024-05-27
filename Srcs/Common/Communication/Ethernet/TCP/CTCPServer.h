/**
 *@file     CTCPServer.h
 *@author   Jinhee.LEE
 *@brief    TCP Server Class Header
 */

#ifndef __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPSERVER_H__
#define __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPSERVER_H__

#include <CommonHeader.h>

#include <Common/Communication/Ethernet/IServer.h>
#include <Common/Communication/ISend.h>
#include <Common/Communication/IReceive.h>

namespace comm {
namespace eth {
namespace tcp {

    class CTCPServer : public comm::eth::IServer, public comm::IReceive, public comm::ISend
    {
    public:
        CTCPServer(const short LocalPort);
        virtual ~CTCPServer();

    public:
        virtual void Socket() override;
        virtual void Bind() override;
        virtual void Listen() override;
        virtual void Accept() override;
        virtual void Close() override;
    
        virtual int Send(const char* Buffer, int BufferSize) override;
        virtual int Receive(char * Buffer, int BufferSize) override;

    public:
        void Initiate();
        bool IsConnect();

    private:
        int m_sockfd;
        sockaddr_in m_sServerAddr;
        bool m_isConnect;
    };

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */
#endif /* __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPSERVER_H__ */