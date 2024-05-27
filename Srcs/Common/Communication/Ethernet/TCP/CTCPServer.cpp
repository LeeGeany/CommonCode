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
    {

    }

    CTCPServer::~CTCPServer()
    {

    }


    void CTCPServer::Socket()
    {

    }

    void CTCPServer::Bind()
    {

    }

    void CTCPServer::Listen()
    {

    }
    void CTCPServer::Accept() {}
    void CTCPServer::Close() {}

    int CTCPServer::Send(const char* Buffer, int BufferSize) {}
    int CTCPServer::Receive(char * Buffer, int BufferSize){}


    void CTCPServer::Initiate() {}
    bool CTCPServer::IsConnect() {}

} /* namespace tcp */
} /* namespace eth */
} /* namespace comm */