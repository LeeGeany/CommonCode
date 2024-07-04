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
    /**
     * @brief Construct a new CTCPServer object
     * @param LocalPort 
     */
    CTCPServer(const short LocalPort);

    /**
     * @brief Destroy the CTCPServer object
     */
    virtual ~CTCPServer();

private:
    /**
     * @brief 
     * @return int 
     */
    int Socket();

    /**
     * @brief 
     * @return int 
     */
    int Bind();

    /**
     * @brief 
     * @return int 
     */
    int Listen();

    /**
     * @brief 
     * @return int 
     */
    int Accept();

    /**
     * @brief 
     */
    void Close();


public:
    /**
     * @brief 
     * @param Buffer 
     * @param BufferSize 
     * @return int 
     */
    virtual int Send(const char* Buffer, const unsigned int BufferSize) override;

    /**
     * @brief 
     * @param Buffer 
     * @param BufferSize 
     * @return int 
     */
    virtual int Receive(char * Buffer, const unsigned int BufferSize) override;

    /**
     * @brief 
     */
    void Initiate();

    /**
     * @brief
     */
    void Terminate();

    /**
     * @brief 
     * @return true 
     * @return false 
     */
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