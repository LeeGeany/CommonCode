#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>

#include "Source/Data/CDataTest.h"
#include "App/API_JHData.h"

int main(void)
{
    CDataTest test(stTest{1,2});

    API::JHData::InsertData(0, &test);
    API::JHData::CreateData<CDataTest>(1);

    std::cout << API::JHData::FindData<CDataTest>(0).getTest1() << std::endl;
    std::cout << API::JHData::FindData<CDataTest>(0).getTest2() << std::endl;

    API::JHData::FindData<CDataTest>(0).setTest1(100);
    API::JHData::FindData<CDataTest>(0).setTest2(200);

    API::JHData::FindData<CDataTest>(1).setTest1(300);
    API::JHData::FindData<CDataTest>(1).setTest2(400);    

    std::cout << API::JHData::FindData<CDataTest>(0).getTest1() << std::endl;
    std::cout << API::JHData::FindData<CDataTest>(0).getTest2() << std::endl;
    std::cout << API::JHData::FindData<CDataTest>(1).getTest1() << std::endl;
    std::cout << API::JHData::FindData<CDataTest>(1).getTest2() << std::endl;
    return 0;
}
