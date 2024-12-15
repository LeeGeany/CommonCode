#include "CommonHeader.h"

namespace Time 
{
    class CTime
    {
    public:
        CTime();
        virtual ~CTime();

    public:
        static void getTimeStamp(char * buffer)
        {
            gettimeofday(&m_time, NULL);
            m_ptm = localtime(&m_time.tv_sec);

            sprintf(&buffer[0], "%4d%2d%2d%2d%2d%2d"        \
                              , 1900 + m_ptm->tm_year
                              , m_ptm->tm_mon + 1
                              , m_ptm->tm_mday
                              , m_ptm->tm_hour
                              , m_ptm->tm_min
                              , m_ptm->tm_sec);
        }

        static void setTimeStamp( unsigned int year
                                , unsigned int day
                                , unsigned int hour
                                , unsigned int min
                                , unsigned int sec)
        {
            struct timeval time;
            time.tv_sec = ((year - 1970) * 365 * 24 * 60 * 60)
                        + (day * 24 * 60 * 60)
                        + (hour * 60 * 60)
                        + (min * 60) 
                        + (sec);
            time.tv_usec = 0;
            int sreturn = settimeofday(&time, NULL);
        }

    private:
        static struct timeval m_time;
        static struct tm* m_ptm;
    };
} /* namespace Time */