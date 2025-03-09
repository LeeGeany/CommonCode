#include "CommonHeader.h"

namespace dir
{
    struct dir_trunc_t
    {
        explicit dir_trunc_t() = default;
    };

    class CDir
    {
    public:
        CDir(std::string _FilePath);

    public:
        bool CreateDir();
        bool isDir();
        

    private:
        std::string m_FilePath;
    }; /* class CDir */
} /* namespace dir */