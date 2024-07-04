#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>
#include <UnitTest/Test_Thread/Test_Thread.h>

#include <UnitTest/Test_TCP/Test_TCP.h>

int main(void)
{
    CUnitTest_TCP Tcp;

    Tcp.UnitTest();

    while(1){}

    return 0;
}
