#ifndef DEFINES_LOWLEVEL_PROTOS_H
#define DEFINES_LOWLEVEL_PROTOS_H

/*
    *** Automatically generated from 'lowlevel.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for lowlevel
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>


#define __ReadJoyPort_WB(__LowLevelBase, __arg1) \
        AROS_LC1(ULONG, ReadJoyPort, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__LowLevelBase), 10, LowLevel)

#define ReadJoyPort(arg1) \
    __ReadJoyPort_WB(LowLevelBase, (arg1))

#define __GetLanguageSelection_WB(__LowLevelBase) \
        AROS_LC0(ULONG, GetLanguageSelection, \
        struct Library *, (__LowLevelBase), 11, LowLevel)

#define GetLanguageSelection() \
    __GetLanguageSelection_WB(LowLevelBase)

#define __GetKey_WB(__LowLevelBase) \
        AROS_LC0(ULONG, GetKey, \
        struct Library *, (__LowLevelBase), 13, LowLevel)

#define GetKey() \
    __GetKey_WB(LowLevelBase)

#define __QueryKeys_WB(__LowLevelBase, __arg1, __arg2) \
        AROS_LC2(void, QueryKeys, \
                  AROS_LCA(struct KeyQuery *,(__arg1),A0), \
                  AROS_LCA(UBYTE,(__arg2),D1), \
        struct Library *, (__LowLevelBase), 14, LowLevel)

#define QueryKeys(arg1, arg2) \
    __QueryKeys_WB(LowLevelBase, (arg1), (arg2))

#define __AddKBInt_WB(__LowLevelBase, __arg1, __arg2) \
        AROS_LC2(APTR, AddKBInt, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct Library *, (__LowLevelBase), 15, LowLevel)

#define AddKBInt(arg1, arg2) \
    __AddKBInt_WB(LowLevelBase, (arg1), (arg2))

#define __RemKBInt_WB(__LowLevelBase, __arg1) \
        AROS_LC1(void, RemKBInt, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__LowLevelBase), 16, LowLevel)

#define RemKBInt(arg1) \
    __RemKBInt_WB(LowLevelBase, (arg1))

#define __AddTimerInt_WB(__LowLevelBase, __arg1, __arg2) \
        AROS_LC2(APTR, AddTimerInt, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct Library *, (__LowLevelBase), 18, LowLevel)

#define AddTimerInt(arg1, arg2) \
    __AddTimerInt_WB(LowLevelBase, (arg1), (arg2))

#define __RemTimerInt_WB(__LowLevelBase, __arg1) \
        AROS_LC1(void, RemTimerInt, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__LowLevelBase), 19, LowLevel)

#define RemTimerInt(arg1) \
    __RemTimerInt_WB(LowLevelBase, (arg1))

#define __StopTimerInt_WB(__LowLevelBase, __arg1) \
        AROS_LC1(void, StopTimerInt, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__LowLevelBase), 20, LowLevel)

#define StopTimerInt(arg1) \
    __StopTimerInt_WB(LowLevelBase, (arg1))

#define __StartTimerInt_WB(__LowLevelBase, __arg1, __arg2, __arg3) \
        AROS_LC3(void, StartTimerInt, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(BOOL,(__arg3),D1), \
        struct Library *, (__LowLevelBase), 21, LowLevel)

#define StartTimerInt(arg1, arg2, arg3) \
    __StartTimerInt_WB(LowLevelBase, (arg1), (arg2), (arg3))

#define __ElapsedTime_WB(__LowLevelBase, __arg1) \
        AROS_LC1(ULONG, ElapsedTime, \
                  AROS_LCA(struct EClockVal *,(__arg1),A0), \
        struct Library *, (__LowLevelBase), 22, LowLevel)

#define ElapsedTime(arg1) \
    __ElapsedTime_WB(LowLevelBase, (arg1))

#define __AddVBlankInt_WB(__LowLevelBase, __arg1, __arg2) \
        AROS_LC2(APTR, AddVBlankInt, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct Library *, (__LowLevelBase), 23, LowLevel)

#define AddVBlankInt(arg1, arg2) \
    __AddVBlankInt_WB(LowLevelBase, (arg1), (arg2))

#define __RemVBlankInt_WB(__LowLevelBase, __arg1) \
        AROS_LC1(void, RemVBlankInt, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__LowLevelBase), 24, LowLevel)

#define RemVBlankInt(arg1) \
    __RemVBlankInt_WB(LowLevelBase, (arg1))

#endif /* DEFINES_LOWLEVEL_PROTOS_H*/
