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
    api::AppInit();
    //api::CreateDataMngr();
    bool check1 = api::data::CreateData<msg::CMsg_IPCHeader>(0x1000);
    return 0;
}