/**
 *@file     CTCPClient.h
 *@author   Jinhee.LEE
 *@brief    TCP Client Class Header
 */

#ifndef __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H__
#define __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H__

#include <CommonHeader.h>

#include <Common/Communication/Ethernet/IClient.h>
#include <Common/Communication/ISend.h>
#include <Common/Communication/IReceive.h>

namespace comm {
namespace eth {
namespace tcp {

class CTCPClient : public comm::eth::IClient, public comm::IReceive, public comm::ISend
{
public:
    /**
     * @brief CTCPClient Constructor
     * @param DestIP
     * @param DestPort
     */
    explicit CTCPClient(const char * DestIP, const short DestPort) noexcept;
    
    /**
     * @brief CTCPClient Destructor
     */
    virtual ~CTCPClient() noexcept;

public:

    virtual int Socket() final;
    virtual int Connect() final;
    virtual int Close() final;

    virtual int Send(const char* Buffer, const unsigned int BufferSize) override;
    virtual int Receive(char * Buffer, const unsigned int BufferSize) override;

public:
    void Initiate();
    void Terminate();
    void ClientInfoShow();
    
private:
    int m_sockfd;
    sockaddr_in m_sClientAddr;
};

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */
#endif /* __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H__ */