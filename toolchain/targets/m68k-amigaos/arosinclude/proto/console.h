#ifndef PROTO_CONSOLE_H
#define PROTO_CONSOLE_H

/*
    *** Automatically generated from 'console.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/system.h>

#include <clib/console_protos.h>

#if !defined(ConsoleDevice) && !defined(__NOLIBBASE__) && !defined(__CONSOLE_NOLIBBASE__)
extern struct Device *ConsoleDevice;
#endif

#if !defined(NOLIBDEFINES) && !defined(CONSOLE_NOLIBDEFINES)
#   include <defines/console.h>
#endif

#endif /* PROTO_CONSOLE_H */
