#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include <CommonHeader.h>

#include "Common/FileSystem/File/CFile.h"


int main(void)
{
    std::string buffer{};

    file::CFile file_both("test.txt", file::io_stream_file);
    file_both << "hello" << " " << "world" << "\n";

    file::CFile file_read("test.txt", file::in_stream_file);
    file_read >> buffer;

    std::cout << buffer;
    return 0;
}