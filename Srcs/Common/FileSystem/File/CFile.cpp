#include "CFile.h"

namespace file
{
    CFile::CFile(const char * const filename) noexcept
    : m_fileType(FileType::FILE_NONE)
    {

    }

    CFile::CFile(const char * const filename, io_stream_file_t) noexcept
    : m_fileType(FileType::FILE_BOTH)
    , m_ofs{filename}
    , m_ifs{filename}
    {

    }

    CFile::CFile(const char * const filename, out_stream_file_t) noexcept
    : m_fileType(FileType::FILE_WRITE)
    , m_ofs{filename}
    {

    }

    CFile::CFile(const char * const filename, in_stream_file_t) noexcept
    : m_fileType(FileType::FILE_READ)
    , m_ifs{filename}
    {

    }

    CFile::~CFile()
    {

    }
} /* namespace file */

