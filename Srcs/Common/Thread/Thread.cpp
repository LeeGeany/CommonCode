#include "Common/Thread/Thread.h"

Thread::Thread(const char * ThreadName) noexcept
{
    std::cout << ThreadName << " Thread Constructor\n";
}
 
Thread::~Thread()
{
    std::cout << "Thread Destructor\n";
}