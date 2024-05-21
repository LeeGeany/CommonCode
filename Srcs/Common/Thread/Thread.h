#include "CommonHeader.h"

class Thread
{
public:
    explicit Thread(const char * ThreadName) noexcept;
    virtual ~Thread();
};
