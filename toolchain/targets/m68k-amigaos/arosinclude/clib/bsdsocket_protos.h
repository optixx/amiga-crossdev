#ifndef CLIB_BSDSOCKET_PROTOS_H
#define CLIB_BSDSOCKET_PROTOS_H

/*
    *** Automatically generated from 'bsdsocket.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>
/* Stub macros for 'emulation' of some functions */
#define select(nfds,rfds,wfds,efds,timeout) WaitSelect(nfds,rfds,wfds,efds,timeout,NULL)
#define inet_ntoa(addr) Inet_NtoA(((struct in_addr)addr).s_addr)

AROS_LP3(int, socket,
        AROS_LPA(int, domain, D0),
        AROS_LPA(int, type, D1),
        AROS_LPA(int, protocol, D2),
        struct Library *, SocketBase, 5, BSDSocket)

AROS_LP3(int, bind,
        AROS_LPA(int, s, D0),
        AROS_LPA(struct sockaddr *, name, A0),
        AROS_LPA(int, namelen, D1),
        struct Library *, SocketBase, 6, BSDSocket)

AROS_LP2(int, listen,
        AROS_LPA(int, s, D0),
        AROS_LPA(int, backlog, D1),
        struct Library *, SocketBase, 7, BSDSocket)

AROS_LP3(int, accept,
        AROS_LPA(int, s, D0),
        AROS_LPA(struct sockaddr *, addr, A0),
        AROS_LPA(int *, addrlen, A1),
        struct Library *, SocketBase, 8, BSDSocket)

AROS_LP3(int, connect,
        AROS_LPA(int, s, D0),
        AROS_LPA(struct sockaddr *, name, A0),
        AROS_LPA(int, namelen, D1),
        struct Library *, SocketBase, 9, BSDSocket)

AROS_LP6(int, sendto,
        AROS_LPA(int, s, D0),
        AROS_LPA(const void *, msg, A0),
        AROS_LPA(int, len, D1),
        AROS_LPA(int, flags, D2),
        AROS_LPA(const struct sockaddr *, to, A1),
        AROS_LPA(int, tolen, D3),
        struct Library *, SocketBase, 10, BSDSocket)

AROS_LP4(int, send,
        AROS_LPA(int, s, D0),
        AROS_LPA(const void *, msg, A0),
        AROS_LPA(int, len, D1),
        AROS_LPA(int, flags, D2),
        struct Library *, SocketBase, 11, BSDSocket)

AROS_LP6(int, recvfrom,
        AROS_LPA(int, s, D0),
        AROS_LPA(void *, buf, A0),
        AROS_LPA(int, len, D1),
        AROS_LPA(int, flags, D2),
        AROS_LPA(struct sockaddr *, from, A1),
        AROS_LPA(int *, fromlen, A2),
        struct Library *, SocketBase, 12, BSDSocket)

AROS_LP4(int, recv,
        AROS_LPA(int, s, D0),
        AROS_LPA(void *, buf, A0),
        AROS_LPA(int, len, D1),
        AROS_LPA(int, flags, D2),
        struct Library *, SocketBase, 13, BSDSocket)

AROS_LP2(int, shutdown,
        AROS_LPA(int, s, D0),
        AROS_LPA(int, how, D1),
        struct Library *, SocketBase, 14, BSDSocket)

AROS_LP5(int, setsockopt,
        AROS_LPA(int, s, D0),
        AROS_LPA(int, level, D1),
        AROS_LPA(int, optname, D2),
        AROS_LPA(void *, optval, A0),
        AROS_LPA(int, optlen, D3),
        struct Library *, SocketBase, 15, BSDSocket)

AROS_LP5(int, getsockopt,
        AROS_LPA(int, s, D0),
        AROS_LPA(int, level, D1),
        AROS_LPA(int, optname, D2),
        AROS_LPA(void *, optval, A0),
        AROS_LPA(void *, optlen, A1),
        struct Library *, SocketBase, 16, BSDSocket)

AROS_LP3(int, getsockname,
        AROS_LPA(int, s, D0),
        AROS_LPA(struct sockaddr *, name, A0),
        AROS_LPA(int *, namelen, A1),
        struct Library *, SocketBase, 17, BSDSocket)

AROS_LP3(int, getpeername,
        AROS_LPA(int, s, D0),
        AROS_LPA(struct sockaddr *, name, A0),
        AROS_LPA(int *, namelen, A1),
        struct Library *, SocketBase, 18, BSDSocket)

AROS_LP3(int, IoctlSocket,
        AROS_LPA(int, s, D0),
        AROS_LPA(unsigned long, request, D1),
        AROS_LPA(char *, argp, A0),
        struct Library *, SocketBase, 19, BSDSocket)

AROS_LP1(int, CloseSocket,
        AROS_LPA(int, s, D0),
        struct Library *, SocketBase, 20, BSDSocket)

AROS_LP6(int, WaitSelect,
        AROS_LPA(int, nfds, D0),
        AROS_LPA(fd_set *, readfds, A0),
        AROS_LPA(fd_set *, writefds, A1),
        AROS_LPA(fd_set *, exceptfds, A2),
        AROS_LPA(struct timeval *, timeout, A3),
        AROS_LPA(ULONG *, sigmask, D1),
        struct Library *, SocketBase, 21, BSDSocket)

AROS_LP3(void, SetSocketSignals,
        AROS_LPA(ULONG, intrmask, D0),
        AROS_LPA(ULONG, iomask, D1),
        AROS_LPA(ULONG, urgmask, D2),
        struct Library *, SocketBase, 22, BSDSocket)

AROS_LP0(int, getdtablesize,
        struct Library *, SocketBase, 23, BSDSocket)

AROS_LP4(LONG, ObtainSocket,
        AROS_LPA(LONG, id, D0),
        AROS_LPA(LONG, domain, D1),
        AROS_LPA(LONG, type, D2),
        AROS_LPA(LONG, protocol, D3),
        struct Library *, SocketBase, 24, BSDSocket)

AROS_LP2(LONG, ReleaseSocket,
        AROS_LPA(LONG, sd, D0),
        AROS_LPA(LONG, id, D1),
        struct Library *, SocketBase, 25, BSDSocket)

AROS_LP2(LONG, ReleaseCopyOfSocket,
        AROS_LPA(LONG, sd, D0),
        AROS_LPA(LONG, id, D1),
        struct Library *, SocketBase, 26, BSDSocket)

AROS_LP0(LONG, Errno,
        struct Library *, SocketBase, 27, BSDSocket)

AROS_LP2(void, SetErrnoPtr,
        AROS_LPA(void *, ptr, A0),
        AROS_LPA(int, size, D0),
        struct Library *, SocketBase, 28, BSDSocket)

AROS_LP1(char *, Inet_NtoA,
        AROS_LPA(unsigned long, in, D0),
        struct Library *, SocketBase, 29, BSDSocket)

AROS_LP1(unsigned long, inet_addr,
        AROS_LPA(const char *, cp, A0),
        struct Library *, SocketBase, 30, BSDSocket)

AROS_LP1(unsigned long, Inet_LnaOf,
        AROS_LPA(unsigned long, in, D0),
        struct Library *, SocketBase, 31, BSDSocket)

AROS_LP1(unsigned long, Inet_NetOf,
        AROS_LPA(unsigned long, in, D0),
        struct Library *, SocketBase, 32, BSDSocket)

AROS_LP2(unsigned long, Inet_MakeAddr,
        AROS_LPA(int, net, D0),
        AROS_LPA(int, lna, D1),
        struct Library *, SocketBase, 33, BSDSocket)

AROS_LP1(unsigned long, inet_network,
        AROS_LPA(const char *, cp, A0),
        struct Library *, SocketBase, 34, BSDSocket)

AROS_LP1(struct hostent *, gethostbyname,
        AROS_LPA(char *, name, A0),
        struct Library *, SocketBase, 35, BSDSocket)

AROS_LP3(struct hostent *, gethostbyaddr,
        AROS_LPA(char *, addr, A0),
        AROS_LPA(int, len, D0),
        AROS_LPA(int, type, D1),
        struct Library *, SocketBase, 36, BSDSocket)

AROS_LP1(struct netent *, getnetbyname,
        AROS_LPA(char *, name, A0),
        struct Library *, SocketBase, 37, BSDSocket)

AROS_LP2(struct netent *, getnetbyaddr,
        AROS_LPA(long, net, D0),
        AROS_LPA(int, type, D1),
        struct Library *, SocketBase, 38, BSDSocket)

AROS_LP2(struct servent *, getservbyname,
        AROS_LPA(char *, name, A0),
        AROS_LPA(char *, proto, A1),
        struct Library *, SocketBase, 39, BSDSocket)

AROS_LP2(struct servent *, getservbyport,
        AROS_LPA(int, port, D0),
        AROS_LPA(char *, proto, A0),
        struct Library *, SocketBase, 40, BSDSocket)

AROS_LP1(struct protoent *, getprotobyname,
        AROS_LPA(char *, name, A0),
        struct Library *, SocketBase, 41, BSDSocket)

AROS_LP1(struct protoent *, getprotobynumber,
        AROS_LPA(int, proto, D0),
        struct Library *, SocketBase, 42, BSDSocket)

AROS_LP3(void, vsyslog,
        AROS_LPA(int, level, D0),
        AROS_LPA(const char *, format, A0),
        AROS_LPA(LONG *, args, A1),
        struct Library *, SocketBase, 43, BSDSocket)

AROS_LP2(int, Dup2Socket,
        AROS_LPA(int, fd1, D0),
        AROS_LPA(int, fd2, D1),
        struct Library *, SocketBase, 44, BSDSocket)

AROS_LP3(int, sendmsg,
        AROS_LPA(int, s, D0),
        AROS_LPA(const struct msghdr *, msg, A0),
        AROS_LPA(int, flags, D1),
        struct Library *, SocketBase, 45, BSDSocket)

AROS_LP3(int, recvmsg,
        AROS_LPA(int, s, D0),
        AROS_LPA(struct msghdr *, msg, A0),
        AROS_LPA(int, flags, D1),
        struct Library *, SocketBase, 46, BSDSocket)

AROS_LP2(int, gethostname,
        AROS_LPA(char *, name, A0),
        AROS_LPA(int, namelen, D0),
        struct Library *, SocketBase, 47, BSDSocket)

AROS_LP0(long, gethostid,
        struct Library *, SocketBase, 48, BSDSocket)

AROS_LP1(ULONG, SocketBaseTagList,
        AROS_LPA(struct TagItem *, tagList, A0),
        struct Library *, SocketBase, 49, BSDSocket)

AROS_LP1(LONG, GetSocketEvents,
        AROS_LPA(ULONG *, eventsp, A0),
        struct Library *, SocketBase, 50, BSDSocket)

#endif /* CLIB_BSDSOCKET_PROTOS_H */
