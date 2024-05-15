/**
 *@file     CTCPClient.h
 *@author   Jinhee.LEE
 *@brief    TCP Client Class Header
 */

#ifndef _COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H_
#define _COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H_

#include <CommonHeader.h>

#include <Common/Communication/Ethernet/IClient.h>
#include <Common/Communication/ISend.h>
#include <Common/Communication/IReceive.h>

namespace comm {
namespace eth {
namespace tcp {

class CTCPClient : public comm::eth::IClient, public comm::IReceive, public comm::ISend
{
private:
    int m_sockfd;
    sockaddr_in m_sClientAddr;
    bool m_isConnect;

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

    virtual void Socket() override;
    virtual void Connect() override;
    virtual void Close() override;

    virtual int Send(const char* Buffer, int BufferSize) override;
    virtual int Receive(char * Buffer, int BufferSize) override;

public:
    void Initiate();
    bool IsConnect();

};

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */

#endif /* _COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H_ */