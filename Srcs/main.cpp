#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>

#include "Common/Time/CTime.h"


int main(void)
{

    char buffer[20] = {0,};
    Time::CTime::getTimeStamp(buffer);
    printf("%s\n", buffer);

    Time::CTime::setTimeStamp(2025,140,0,0,0);
    Time::CTime::getTimeStamp(buffer);
    printf("%s\n", buffer);


    return 0;
}