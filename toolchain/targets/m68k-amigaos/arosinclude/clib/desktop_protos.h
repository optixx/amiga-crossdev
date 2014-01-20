#ifndef CLIB_DESKTOP_PROTOS_H
#define CLIB_DESKTOP_PROTOS_H

/*
    *** Automatically generated from 'desktop.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>
#include <utility/tagitem.h>
#include <intuition/classes.h>

AROS_LP2(Object *, CreateDesktopObjectA,
        AROS_LPA(ULONG, kind, D0),
        AROS_LPA(struct TagItem *, tags, A0),
        struct Library *, DesktopBase, 7, Desktop)

AROS_LP2(ULONG, DoDesktopOperationA,
        AROS_LPA(ULONG, operationCode, D0),
        AROS_LPA(struct TagItem *, tags, D2),
        struct Library *, DesktopBase, 8, Desktop)

AROS_LP1(struct DesktopOperationItem *, GetMenuItemList,
        AROS_LPA(ULONG, operationType, D0),
        struct Library *, DesktopBase, 9, Desktop)

AROS_LP0(struct NewMenu *, BuildDesktopMenus,
        struct Library *, DesktopBase, 10, Desktop)

#endif /* CLIB_DESKTOP_PROTOS_H */
