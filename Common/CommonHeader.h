
#ifndef __COMMON_HEADER__
#define __COMMON_HEADER__


#define __linux
#define __ethernet


#ifdef __cplusplus

/* Standard IO */
#include <iostream>

/* C Header */
#include <cstring>

/* Standard Template Library */
#include <vector>
#include <string>

#endif /* __cplusplus */


#ifdef __linux

/* POSIX */
#include <unistd.h>

#endif /* linux */


#ifdef __ethernet

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#endif /* __ethernet */


#endif /* __COMMON_HEADER__ */
