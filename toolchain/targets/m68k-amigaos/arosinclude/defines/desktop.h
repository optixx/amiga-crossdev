#ifndef DEFINES_DESKTOP_PROTOS_H
#define DEFINES_DESKTOP_PROTOS_H

/*
    *** Automatically generated from 'desktop.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for desktop
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>


#define __CreateDesktopObjectA_WB(__DesktopBase, __arg1, __arg2) \
        AROS_LC2(Object *, CreateDesktopObjectA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),A0), \
        struct Library *, (__DesktopBase), 7, Desktop)

#define CreateDesktopObjectA(arg1, arg2) \
    __CreateDesktopObjectA_WB(DesktopBase, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(DESKTOP_NO_INLINE_STDARG)
#define CreateDesktopObject(arg1, ...) \
({ \
    IPTR __args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) }; \
    CreateDesktopObjectA((arg1), (struct TagItem *)__args); \
})
#endif /* !NO_INLINE_STDARG */

#define __DoDesktopOperationA_WB(__DesktopBase, __arg1, __arg2) \
        AROS_LC2(ULONG, DoDesktopOperationA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),D2), \
        struct Library *, (__DesktopBase), 8, Desktop)

#define DoDesktopOperationA(arg1, arg2) \
    __DoDesktopOperationA_WB(DesktopBase, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(DESKTOP_NO_INLINE_STDARG)
#define DoDesktopOperation(arg1, ...) \
({ \
    IPTR __args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) }; \
    DoDesktopOperationA((arg1), (struct TagItem *)__args); \
})
#endif /* !NO_INLINE_STDARG */

#define __GetMenuItemList_WB(__DesktopBase, __arg1) \
        AROS_LC1(struct DesktopOperationItem *, GetMenuItemList, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__DesktopBase), 9, Desktop)

#define GetMenuItemList(arg1) \
    __GetMenuItemList_WB(DesktopBase, (arg1))

#define __BuildDesktopMenus_WB(__DesktopBase) \
        AROS_LC0(struct NewMenu *, BuildDesktopMenus, \
        struct Library *, (__DesktopBase), 10, Desktop)

#define BuildDesktopMenus() \
    __BuildDesktopMenus_WB(DesktopBase)

#endif /* DEFINES_DESKTOP_PROTOS_H*/
