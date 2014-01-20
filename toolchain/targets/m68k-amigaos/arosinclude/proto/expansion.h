#ifndef PROTO_EXPANSION_H
#define PROTO_EXPANSION_H

/*
    *** Automatically generated from 'expansion.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/system.h>

#include <clib/expansion_protos.h>

#if !defined(ExpansionBase) && !defined(__NOLIBBASE__) && !defined(__EXPANSION_NOLIBBASE__)
extern struct Library *ExpansionBase;
#endif

#if !defined(NOLIBDEFINES) && !defined(EXPANSION_NOLIBDEFINES)
#   include <defines/expansion.h>
#endif

#endif /* PROTO_EXPANSION_H */
