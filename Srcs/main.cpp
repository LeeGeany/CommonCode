#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>

#include <Common/Communication/Ethernet/TCP/CTCPClient.h>
#include <Common/Communication/Ethernet/TCP/CTCPServer.h>

char SendBuffer[128] = {0,};
char RecvBuffer[128] = {0,};

int main(void)
{

	std::unique_ptr<comm::eth::tcp::CTCPServer> uptr_Server;
	uptr_Server = std::make_unique<comm::eth::tcp::CTCPServer>(12345);

	

	std::unique_ptr<comm::eth::tcp::CTCPClient> uptr_Client;
	uptr_Client = std::make_unique<comm::eth::tcp::CTCPClient>("192.168.0.101", 12345);


	uptr_Client->Initiate();

	while(1)
	{
		(void)std::memset(SendBuffer, 0, sizeof(SendBuffer));
		(void)std::memset(RecvBuffer, 0, sizeof(RecvBuffer));

		std::scanf(">> %s", SendBuffer);
		uptr_Client->Send(SendBuffer, 128);
		uptr_Server->Receive(RecvBuffer, 128);
		printf("%s\n", RecvBuffer);
	}
}
