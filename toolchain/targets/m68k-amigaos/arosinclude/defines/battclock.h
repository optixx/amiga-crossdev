#ifndef DEFINES_BATTCLOCK_PROTOS_H
#define DEFINES_BATTCLOCK_PROTOS_H

/*
    *** Automatically generated from 'battclock.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for battclock
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>


#define __ResetBattClock_WB(__BattClockBase) \
        AROS_LC0(void, ResetBattClock, \
        APTR , (__BattClockBase), 1, Battclock)

#define ResetBattClock() \
    __ResetBattClock_WB(BattClockBase)

#define __ReadBattClock_WB(__BattClockBase) \
        AROS_LC0(ULONG, ReadBattClock, \
        APTR , (__BattClockBase), 2, Battclock)

#define ReadBattClock() \
    __ReadBattClock_WB(BattClockBase)

#define __WriteBattClock_WB(__BattClockBase, __arg1) \
        AROS_LC1(void, WriteBattClock, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        APTR , (__BattClockBase), 3, Battclock)

#define WriteBattClock(arg1) \
    __WriteBattClock_WB(BattClockBase, (arg1))

#endif /* DEFINES_BATTCLOCK_PROTOS_H*/
