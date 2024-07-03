#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>
#include <UnitTest/Test_Thread/Test_Thread.h>

int main(void)
{
    CTest_Thread ThreadExample;

    ThreadExample.Run();

    return 0;
}
