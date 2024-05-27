/**
 *@file     CTCPClient.cpp
 *@author   Jinhee.LEE
 *@brief    TCP Client Class Source 
 */

#include <Common/Communication/Ethernet/TCP/CTCPClient.h>

namespace comm {
namespace eth {
namespace tcp {

CTCPClient::CTCPClient(const char * DestIP, const short DestPort) noexcept
: m_sockfd(0)
{
    std::memset(&(m_sClientAddr), 0, sizeof(sockaddr_in));
    m_sClientAddr.sin_family        = AF_INET;
    m_sClientAddr.sin_addr.s_addr   = inet_addr(DestIP);
    m_sClientAddr.sin_port          = htons(DestPort);
}

CTCPClient::~CTCPClient() noexcept
{
    (void)Close();
}

/**
 * @brief Create Socket (PF_INET - IPv4, SOCK_STREAM, 0)
 */
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

/**
 * @brief Make Connection
 */
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
    
/**
 * @brief Close Socket
 */
int CTCPClient::Close()
{
    return close(m_sockfd);
}

/**
 * @brief Send Data
 * @param Buffer
 * @param BufferSize
 * @return int Send Buffer Size
 */
int CTCPClient::Send(const char* Buffer, int BufferSize)
{
    return send(m_sockfd, Buffer, BufferSize, 0);
}

/**
 * @brief Recv Data
 * @param Buffer
 * @param BufferSize
 * @return int Receive Buffer Size
 */
int CTCPClient::Receive(char * Buffer, int BufferSize)
{
    return recv(m_sockfd, Buffer, BufferSize, 0);
}

/**
 * @brief Initiate Client Instance
 */
void CTCPClient::Initiate()
{
    Socket();
    Connect();
}

/**
 * @brief Terminate Client Instance
 */
void CTCPClient::Terminate()
{
    Close();
}

/**
 * @brief Show Info
 */
void CTCPClient::ClientInfoShow()
{
    std::cout << "[Clinet IP]   : " << m_sClientAddr.sin_addr.s_addr << '\n';
    std::cout << "[Client Port] : " << m_sClientAddr.sin_port << '\n';
}

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */