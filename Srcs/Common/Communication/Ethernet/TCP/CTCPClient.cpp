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
{

    Initiate();
    
    m_sClientAddr.sin_family        = AF_INET;
    m_sClientAddr.sin_addr.s_addr   = inet_addr(DestIP);
    m_sClientAddr.sin_port          = htons(DestPort);

    Socket();
    Connect();

}

CTCPClient::~CTCPClient() noexcept
{

    Close();

}


    /**
     * @brief Create Socket (PF_INET - IPv4, SOCK_STREAM, 0)
     */
    void CTCPClient::Socket()
    {

        m_sockfd = socket(PF_INET, SOCK_STREAM, 0);

        if(0 > m_sockfd)
        {
            std::perror("Socket Create Fail...");
        }

    }


    /**
     * @brief Make Connection
     */
    void CTCPClient::Connect()
    {
        int ret = connect(m_sockfd, reinterpret_cast<sockaddr*>(&(m_sClientAddr)), sizeof(sockaddr_in));

        m_isConnect = true;

        if(0 > ret)
        {
            std::perror("Connect Fail...");
        }
    
    }   
    
    
    /**
     * @brief Close Socket
     */
    void CTCPClient::Close()
    {

        int ret = 0;
        //int ret = close(m_sockfd);

        if(0 > ret)
        {
            std::perror("Close Fail...");
        }

    }


    /**
     * @brief Send Data
     */
    int CTCPClient::Send(const char* Buffer, int BufferSize)
    {

        int ret = send(m_sockfd, Buffer, BufferSize, 0);

        if(0 > ret)
        {
            std::perror("Send Fail...");
        }

    }


    /**
     * @brief Recv Data
     */
    int CTCPClient::Receive(char * Buffer, int BufferSize)
    {

        int ret = recv(m_sockfd, Buffer, BufferSize, 0);

    }


    /**
     * @brief Initiate
     */
    void CTCPClient::Initiate()
    {

        m_sockfd = 0;
        std::memset(&(m_sClientAddr), 0, sizeof(sockaddr_in));

        m_isConnect = false;

    }


    /**
     * @brief Check Connection
     */
    bool CTCPClient::IsConnect()
    {

        return m_isConnect;

    }

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */