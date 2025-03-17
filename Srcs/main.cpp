#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>

#include "App/API/api.h"

#include "Source/Data/CMsg_IPCHeader.h"

int main(void)
{
    // Initiate Top Application 
    API::APP::AppInit();
    bool check1 = API::DATA::CreateData<msg::CMsg_IPCHeader>(0x1000);
    if(!check1){std::cout << "fail1\n";}
    bool check2 = API::DATA::CreateData<msg::CMsg_IPCHeader>(0x1000);
    if(!check2){std::cout << "fail2\n";}
    
    return 0;
}