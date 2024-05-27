#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>

#include <Common/Communication/Ethernet/TCP/CTCPClient.h>

int main(void)
{
	std::unique_ptr<comm::eth::tcp::CTCPClient> uptr_Client;
	uptr_Client = std::make_unique<comm::eth::tcp::CTCPClient>("192.168.0.7", 12345);

	uptr_Client->Initiate();

	while(1)
	{
		
	}
}
