/**
 * @file    CTCPClient.cpp
 * @author  jinhee.lee
 * @date    2024.07.04
 * @brief   Class of TCP Client Header
 * 
 * @copyright jinhee.lee
 */

#include "CTCPClient.h"

namespace comm {
namespace eth {
namespace tcp {

CTCPClient::CTCPClient(const char * DestIP, const short DestPort) noexcept
: m_sockfd(0)
{
    std::memset(&(m_sClientAddr), 0, sizeof(sockaddr_in));
    m_sClientAddr.sin_family        = static_cast<sa_family_t>(AF_INET);
    m_sClientAddr.sin_addr.s_addr   = inet_addr(DestIP);
    m_sClientAddr.sin_port          = static_cast<in_port_t>(DestPort);
}

CTCPClient::~CTCPClient() noexcept
{
    (void)Close();
}

int CTCPClient::Socket()
{
    int Ret = 0;
    m_sockfd = socket(PF_INET, SOCK_STREAM, 0);

    if(m_sockfd < 0)
    {
        std::perror("Open Socket Fail...");
        Ret = -1;
    }
    
    return Ret;
}

int CTCPClient::Connect()
{
    int Ret = 0; 
    Ret = connect(m_sockfd, reinterpret_cast<sockaddr*>(&(m_sClientAddr)), sizeof(sockaddr_in));

    if(0 > Ret)
    {
        std::perror("Connect Fail...");
    }

    return Ret;
}   

int CTCPClient::Close()
{
    return close(m_sockfd);
}

int CTCPClient::Send(const char* Buffer, const unsigned int BufferSize)
{
    return send(m_sockfd, Buffer, BufferSize, 0);
}

int CTCPClient::Receive(char * Buffer, const unsigned int BufferSize)
{
    return recv(m_sockfd, Buffer, BufferSize, 0);
}


void CTCPClient::Initiate()
{
    Socket();
    Connect();
}

void CTCPClient::Terminate()
{
    Close();
}

void CTCPClient::ClientInfoShow()
{
    std::cout << "[Clinet IP]   : " << m_sClientAddr.sin_addr.s_addr << '\n';
    std::cout << "[Client Port] : " << m_sClientAddr.sin_port << '\n';
}

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */