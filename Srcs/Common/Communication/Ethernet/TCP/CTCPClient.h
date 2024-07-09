/**
 * @file    CTCPClient.h
 * @author  jinhee.lee
 * @date    2024.07.05
 * @brief   Class of TCP Client Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H__
#define __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H__

#include <CommonHeader.h>

#include <Common/Communication/Ethernet/IReceive.h>
#include <Common/Communication/Ethernet/ISend.h>

namespace comm {
namespace eth {
namespace tcp {

class CTCPClient : public IReceive, public ISend
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


private:
    /**
     * @brief Create Socket (PF_INET - IPv4, SOCK_STREAM, 0)
     */
    virtual int Socket() final;

    /**
     * @brief Make Connection
     */
    virtual int Connect() final;
        
    /**
     * @brief Close Socket
     */
    virtual int Close() final;


public:
    /**
     * @brief Send Data
     * @param Buffer
     * @param BufferSize
     * @return int Send Buffer Size
     */
    virtual int Send(const char* Buffer, const unsigned int BufferSize) override;

    /**
     * @brief Recv Data
     * @param Buffer Recv Buffer
     * @param BufferSize Recv Buffer Size
     * @return int Receive Buffer Size
     */
    virtual int Receive(char * Buffer, const unsigned int BufferSize) override;

    /**
     * @brief Initiate Client Instance
     */
    void Initiate();

    /**
     * @brief Terminate Client Instance
     */
    void Terminate();

    /**
     * @brief Show Info
     */
    void ClientInfoShow();
    

private:
    /**
     * @brief Socket Descripter
     */
    int m_sockfd;

    /**
     * @brief Structure of Address
     */
    sockaddr_in m_sClientAddr;
};

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */
#endif /* __COMMON_COMMUNICATION_ETHERNET_TCP_CTCPCLIENT_H__ */