int CommonProjectVersion[4] 	__attribute__((section("Build Version"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUild Date"))) = {2024,5,15,1};

#include <iostream>

int main(void)
{
	std::cout << "main\n";
	return 0;
}
