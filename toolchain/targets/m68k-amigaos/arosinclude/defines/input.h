#ifndef DEFINES_INPUT_PROTOS_H
#define DEFINES_INPUT_PROTOS_H

/*
    *** Automatically generated from 'input.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for input
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>


#define __PeekQualifier_WB(__InputBase) \
        AROS_LC0(UWORD, PeekQualifier, \
        struct Device *, (__InputBase), 7, Input)

#define PeekQualifier() \
    __PeekQualifier_WB(InputBase)

#define __AddNullEvent_WB(__InputBase) \
        AROS_LC0(void, AddNullEvent, \
        struct Device *, (__InputBase), 20, Input)

#define AddNullEvent() \
    __AddNullEvent_WB(InputBase)

#endif /* DEFINES_INPUT_PROTOS_H*/
