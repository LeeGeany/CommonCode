#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>

#include "App/CApp.h"
#include "App/Manager/Data/CDataManager.h"

int main(void)
{
    return 0;
}