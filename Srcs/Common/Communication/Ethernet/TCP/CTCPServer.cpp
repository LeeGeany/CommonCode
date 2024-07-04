/**
 *@file     CTCPServer.cpp
 *@author   Jinhee.LEE
 *@brief    TCP Server Class Source
 */

#include <Common/Communication/Ethernet/TCP/CTCPServer.h> 

namespace comm {
namespace eth {
namespace tcp {

CTCPServer::CTCPServer(const short LocalPort)
: m_sockfd(0)
, m_Connectfd(0)
{
    std::memset(&(m_sServerAddr), 0, sizeof(sockaddr_in));
    m_sServerAddr.sin_family        = AF_INET;
    m_sServerAddr.sin_addr.s_addr   = INADDR_ANY;
    m_sServerAddr.sin_port          = htons(LocalPort);

    m_addrlen = sizeof(m_sServerAddr);
}

CTCPServer::~CTCPServer()
{

}


int CTCPServer::Socket()
{
    int Ret = 0;
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(m_sockfd < 0)
    {
        std::perror("Open Server Socket Fail...");
        Ret = -1;
    }

    return Ret;
}

int CTCPServer::Bind()
{
    int Ret = 0;
    Ret = bind(m_sockfd, reinterpret_cast<sockaddr*>(&m_sServerAddr), m_addrlen);

    if(Ret < 0)
    {
        std::perror("Bind Fail...");
        Ret = -1;
    }

    return Ret;
}

int CTCPServer::Listen()
{
    int Ret = 0;
    Ret = listen(m_sockfd, 3);

    if(Ret < 0)
    {
        std::perror("Listen Fail...");
        Ret = -1;
    }
    else
    {
        std::printf("Listen Success");
    }

    return Ret;
}

int CTCPServer::Accept()
{
    int Ret = 0;
    m_Connectfd = accept(m_sockfd, reinterpret_cast<sockaddr*>(&m_sServerAddr), &m_addrlen);
    
    if(m_Connectfd < 0)
    {
        std::perror("Accept Fail...");
        Ret = -1;
    }
    else
    {
        std::printf("Accept Success...");
    }

    return Ret;
}

void CTCPServer::Close() 
{
    close(m_sockfd);
    close(m_Connectfd);
}

int CTCPServer::Send(const char* Buffer, const unsigned int BufferSize)
{
    return send(m_sockfd, Buffer, BufferSize, 0);
}

int CTCPServer::Receive(char * Buffer, const unsigned int BufferSize)
{
    return recv(m_sockfd, Buffer, BufferSize, 0);
}

void CTCPServer::Initiate()
{
    Socket();
    Bind();
    Listen();
    Accept();
}

void CTCPServer::Terminate()
{
    Close();
}

bool CTCPServer::IsConnect() 
{
    return true;
}

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */