/*
    Copyright © 2002-2004, The AROS Development Team. 
    All rights reserved.
    
    $Id: wait.h 22498 2004-11-17 19:12:41Z NicJA $
*/

#ifndef SYS_WAIT_H_
#define SYS_WAIT_H_

#ifndef SYS_TYPES_H
#include <sys/types.h>
#endif

pid_t wait(int *status);
//pid_t   waitpid(pid_t, int *, int);

//struct rusage;
//pid_t   wait3(int *, int, struct rusage *);
//pid_t   wait4(pid_t, int *, int, struct rusage *);

#endif /* SYS_WAIT_H_ */