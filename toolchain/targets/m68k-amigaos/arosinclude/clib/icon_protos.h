#ifndef CLIB_ICON_PROTOS_H
#define CLIB_ICON_PROTOS_H

/*
    *** Automatically generated from 'icon.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>
#include <intuition/intuition.h>
#include <workbench/workbench.h>
#include <workbench/icon.h>
#include <utility/tagitem.h>

AROS_LP1(void, FreeFreeList,
        AROS_LPA(struct FreeList *, freelist, A0),
        struct Library *, IconBase, 9, Icon)

AROS_LP3(BOOL, AddFreeList,
        AROS_LPA(struct FreeList *, freelist, A0),
        AROS_LPA(APTR, mem, A1),
        AROS_LPA(unsigned long, size, A2),
        struct Library *, IconBase, 12, Icon)

AROS_LP1(struct DiskObject *, GetDiskObject,
        AROS_LPA(CONST_STRPTR, name, A0),
        struct Library *, IconBase, 13, Icon)

AROS_LP2(BOOL, PutDiskObject,
        AROS_LPA(CONST_STRPTR, name, A0),
        AROS_LPA(struct DiskObject *, icon, A1),
        struct Library *, IconBase, 14, Icon)

AROS_LP1(void, FreeDiskObject,
        AROS_LPA(struct DiskObject *, diskobj, A0),
        struct Library *, IconBase, 15, Icon)

AROS_LP2(UBYTE *, FindToolType,
        AROS_LPA(const STRPTR *, toolTypeArray, A0),
        AROS_LPA(const STRPTR, typeName, A1),
        struct Library *, IconBase, 16, Icon)

AROS_LP2(BOOL, MatchToolValue,
        AROS_LPA(UBYTE *, typeString, A0),
        AROS_LPA(UBYTE *, value, A1),
        struct Library *, IconBase, 17, Icon)

AROS_LP2(UBYTE *, BumpRevision,
        AROS_LPA(UBYTE *, newname, A0),
        AROS_LPA(UBYTE *, oldname, A1),
        struct Library *, IconBase, 18, Icon)

AROS_LP1(struct DiskObject *, GetDefDiskObject,
        AROS_LPA(LONG, type, D0),
        struct Library *, IconBase, 20, Icon)

AROS_LP1(BOOL, PutDefDiskObject,
        AROS_LPA(struct DiskObject *, icon, A0),
        struct Library *, IconBase, 21, Icon)

AROS_LP1(struct DiskObject *, GetDiskObjectNew,
        AROS_LPA(CONST_STRPTR, name, A0),
        struct Library *, IconBase, 22, Icon)

AROS_LP1(BOOL, DeleteDiskObject,
        AROS_LPA(UBYTE *, name, A0),
        struct Library *, IconBase, 23, Icon)

AROS_LP2(struct DiskObject *, DupDiskObjectA,
        AROS_LPA(struct DiskObject *, icon, A0),
        AROS_LPA(struct TagItem *, tags, A1),
        struct Library *, IconBase, 25, Icon)

AROS_LP2(ULONG, IconControlA,
        AROS_LPA(struct DiskObject *, icon, A0),
        AROS_LPA(struct TagItem *, tags, A1),
        struct Library *, IconBase, 26, Icon)

AROS_LP7(void, DrawIconStateA,
        AROS_LPA(struct RastPort *, rp, A0),
        AROS_LPA(struct DiskObject *, icon, A1),
        AROS_LPA(STRPTR, label, A2),
        AROS_LPA(LONG, leftEdge, D0),
        AROS_LPA(LONG, topEdge, D1),
        AROS_LPA(ULONG, state, D2),
        AROS_LPA(struct TagItem *, tags, A3),
        struct Library *, IconBase, 27, Icon)

AROS_LP5(BOOL, GetIconRectangleA,
        AROS_LPA(struct RastPort *, rp, A0),
        AROS_LPA(struct DiskObject *, icon, A1),
        AROS_LPA(STRPTR, label, A2),
        AROS_LPA(struct Rectangle *, rectangle, A3),
        AROS_LPA(struct TagItem *, tags, A4),
        struct Library *, IconBase, 28, Icon)

AROS_LP1(struct DiskObject *, NewDiskObject,
        AROS_LPA(ULONG, type, D0),
        struct Library *, IconBase, 29, Icon)

AROS_LP2(struct DiskObject *, GetIconTagList,
        AROS_LPA(CONST_STRPTR, name, A0),
        AROS_LPA(struct TagItem *, tags, A1),
        struct Library *, IconBase, 30, Icon)

AROS_LP3(BOOL, PutIconTagList,
        AROS_LPA(CONST_STRPTR, name, A0),
        AROS_LPA(struct DiskObject *, icon, A1),
        AROS_LPA(struct TagItem *, tags, A2),
        struct Library *, IconBase, 31, Icon)

AROS_LP3(BOOL, LayoutIconA,
        AROS_LPA(struct DiskObject *, icon, A0),
        AROS_LPA(struct Screen *, screen, A1),
        AROS_LPA(struct TagItem *, tags, A2),
        struct Library *, IconBase, 32, Icon)

AROS_LP1(void, ChangeToSelectedIconColor,
        AROS_LPA(struct ColorRegister *, cr, A0),
        struct Library *, IconBase, 33, Icon)

#endif /* CLIB_ICON_PROTOS_H */
