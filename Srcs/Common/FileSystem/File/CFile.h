#include "CommonHeader.h"

namespace file
{
    // type empty class
    struct io_stream_file_t
    {
        explicit io_stream_file_t() = default;
    };

    struct out_stream_file_t 
    {
        explicit out_stream_file_t() = default; 
    };

    struct in_stream_file_t
    {
        explicit in_stream_file_t() = default;
    };

    // type setting in compile time
    constexpr io_stream_file_t  io_stream_file;
    constexpr out_stream_file_t out_stream_file;
    constexpr in_stream_file_t  in_stream_file;

    // File state type
    enum FileType
    {
        FILE_NONE,
        FILE_BOTH,
        FILE_WRITE,
        FILE_READ
    };

    class CFile
    {
    public:
        CFile(const char * const filename) noexcept;
        CFile(const char * const filename, io_stream_file_t) noexcept;
        CFile(const char * const filename, out_stream_file_t) noexcept;
        CFile(const char * const filename, in_stream_file_t) noexcept;
        virtual ~CFile();

    public:
        CFile& operator<<(const char * const str)
        {
            if(m_fileType == FileType::FILE_BOTH || m_fileType == FileType::FILE_WRITE)
            {
                m_ofs << str;
            }
            return *this;
        }

        CFile& operator>>(char * buffer)
        {
            if(m_fileType == FileType::FILE_BOTH || m_fileType == FileType::FILE_READ)
            {
                m_ifs >> buffer;
            }
            return *this;
        }

        CFile& operator>>(std::string& buffer)
        {
            if(m_fileType == FileType::FILE_BOTH || m_fileType == FileType::FILE_READ)
            {
                m_ifs >> buffer;
            }
            return *this;
        }

    private:
        std::ofstream m_ofs;
        std::ifstream m_ifs;

    private:
        FileType m_fileType;
    };
} /* namespace file */