/**
 * @file    Test_TCP.h
 * @author  jinhee.lee
 * @date    2024.07.05
 * @brief   Class of TCP Client Header
 * 
 * @copyright jinhee.lee
 */

#include "Test_TCP.h"

#include <Common/Concurrent/Thread/CThread.h>

CUnitTest_TCP::CUnitTest_TCP()
{

}

CUnitTest_TCP::~CUnitTest_TCP()
{

}

void CUnitTest_TCP::UnitTest()
{
    concurrent::thread::CThread Server(MainServer);
    concurrent::thread::CThread Client(MainClient);

    Server.Start();
    Client.Start();  

    Client.Join();
    Server.Join();

    
}

void MainServer()
{
    std::unique_ptr<comm::eth::tcp::CTCPServer> m_uptrServer = std::make_unique<comm::eth::tcp::CTCPServer>(11111);
    char RecvBuffer[128] = {0, };
    
    m_uptrServer->Initiate();
    
    while(1)
    {
        std::memset(RecvBuffer, 0, sizeof(RecvBuffer));
        m_uptrServer->Receive(RecvBuffer, sizeof(RecvBuffer));
        std::cout << "Server Receive Data : " << RecvBuffer << std::endl;
    }

    m_uptrServer->Terminate();
}

void MainClient()
{
    std::unique_ptr<comm::eth::tcp::CTCPClient>  m_uptrClient = std::make_unique<comm::eth::tcp::CTCPClient>("192.168.0.34", 11111);
    m_uptrClient->Initiate();

    char SendBuffer[128] = {0, };

    std::memcpy(SendBuffer, "Client Send TCP Message", sizeof(SendBuffer));

    while(1)
    {    
        m_uptrClient->Send(SendBuffer, sizeof(SendBuffer));
        sleep(1);
    }

    m_uptrClient->Terminate();
}