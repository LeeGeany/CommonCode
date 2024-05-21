
#ifndef __COMMON_HEADER__
#define __COMMON_HEADER__

#define __ethernet

#ifdef __cplusplus

/* Standard IO */
#include <iostream>

/* C++ Header */
#include <memory>

/* C Header */
#include <cstring>

/* Standard Template Library */
#include <vector>
#include <string>

#endif /* __cplusplus */


#ifndef __linux__
#define __linux__

/* POSIX */
#include <unistd.h>

#endif /* linux */


#ifdef __ethernet

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#endif /* __ethernet */


#endif /* __COMMON_HEADER__ */
