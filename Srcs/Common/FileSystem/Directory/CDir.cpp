#include "CDir.h"

#define LINUX

#ifdef LINUX
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif /* LINUX */

namespace dir
{
    /**
     * @brief   Constructor
     * @param   _FilePath   Directory Path
     */
    CDir::CDir(std::string _FilePath)
    : m_FilePath{_FilePath}
    {

    }

    bool CDir::CreateDir()
    {
        bool ret = true;
        return ret;
    }

    bool CDir::isDir()
    {
        bool ret = true;
        return ret;    
    }
} /* namespace dir */