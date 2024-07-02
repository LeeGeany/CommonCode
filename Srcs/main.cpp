#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>
#include <UnitTest/Test_MsgQueue/Test_MsgQueue.h>

int main(void)
{
    CUnitTest_MsgQueue MsgQExample;

    MsgQExample.UnitTest();
}
