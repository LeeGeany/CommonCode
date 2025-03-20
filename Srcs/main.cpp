#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif


#include "App/API/api.h"

#include "Source/Data/CMsg_IPCHeader.h"

#include "Source/myThread/CConsoleThread.h"

#define CONSOLE_THREAD_NAME "consoleThread"

int main(void)
{
    bool checker= true;

    // Initiate Top Application 
    API::APP::AppInit();

    // Create Data
    checker = API::DATA::CreateData<msg::CMsg_IPCHeader>(0x1000);
    
    // Final Step | Create Thread
    checker = API::THREAD::CreateThread<usr::CConsoleThread>(CONSOLE_THREAD_NAME);

    cpu_set_t tMask;
    CPU_SET(2,&tMask);

    checker = API::THREAD::setThreadCoreMask(CONSOLE_THREAD_NAME, tMask);


    checker = API::THREAD::StartThread(CONSOLE_THREAD_NAME);




    checker = API::THREAD::JoinThread(CONSOLE_THREAD_NAME);

    return 0;
}