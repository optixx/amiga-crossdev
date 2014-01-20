#ifndef CLIB_UTILITY_PROTOS_H
#define CLIB_UTILITY_PROTOS_H

/*
    *** Automatically generated from 'utility.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <exec/ports.h>
#include <utility/tagitem.h>
#include <utility/date.h>
#include <utility/hooks.h>
#include <utility/name.h>

/* Prototypes for stubs in amiga.lib */
#ifndef AllocNamedObject
struct NamedObject *AllocNamedObject(STRPTR name, ULONG tag1, ...);
#endif

AROS_LP2(struct TagItem *, FindTagItem,
        AROS_LPA(Tag, tagValue, D0),
        AROS_LPA(const struct TagItem *, tagList, A0),
        struct UtilityBase *, UtilityBase, 5, Utility)

AROS_LP3(IPTR, GetTagData,
        AROS_LPA(Tag, tagValue, D0),
        AROS_LPA(IPTR, defaultVal, D1),
        AROS_LPA(const struct TagItem *, tagList, A0),
        struct UtilityBase *, UtilityBase, 6, Utility)

AROS_LP3(ULONG, PackBoolTags,
        AROS_LPA(ULONG, initialFlags, D0),
        AROS_LPA(struct TagItem *, tagList, A0),
        AROS_LPA(struct TagItem *, boolMap, A1),
        struct UtilityBase *, UtilityBase, 7, Utility)

AROS_LP1(struct TagItem *, NextTagItem,
        AROS_LPA(const struct TagItem **, tagListPtr, A0),
        struct UtilityBase *, UtilityBase, 8, Utility)

AROS_LP3(void, FilterTagChanges,
        AROS_LPA(struct TagItem *, changeList, A0),
        AROS_LPA(const struct TagItem *, originalList, A1),
        AROS_LPA(BOOL, apply, D0),
        struct UtilityBase *, UtilityBase, 9, Utility)

AROS_LP3(void, MapTags,
        AROS_LPA(struct TagItem *, tagList, A0),
        AROS_LPA(struct TagItem *, mapList, A1),
        AROS_LPA(ULONG, mapType, D0),
        struct UtilityBase *, UtilityBase, 10, Utility)

AROS_LP1(struct TagItem *, AllocateTagItems,
        AROS_LPA(ULONG, numTags, D0),
        struct UtilityBase *, UtilityBase, 11, Utility)

AROS_LP1(struct TagItem *, CloneTagItems,
        AROS_LPA(const struct TagItem *, tagList, A0),
        struct UtilityBase *, UtilityBase, 12, Utility)

AROS_LP1(void, FreeTagItems,
        AROS_LPA(struct TagItem *, tagList, A0),
        struct UtilityBase *, UtilityBase, 13, Utility)

AROS_LP2(void, RefreshTagItemClones,
        AROS_LPA(struct TagItem *, clone, A0),
        AROS_LPA(const struct TagItem *, original, A1),
        struct UtilityBase *, UtilityBase, 14, Utility)

AROS_LP2(BOOL, TagInArray,
        AROS_LPA(Tag, tagValue, D0),
        AROS_LPA(Tag *, tagArray, A0),
        struct UtilityBase *, UtilityBase, 15, Utility)

AROS_LP3(ULONG, FilterTagItems,
        AROS_LPA(struct TagItem *, tagList, A0),
        AROS_LPA(Tag *, filterArray, A1),
        AROS_LPA(ULONG, logic, D0),
        struct UtilityBase *, UtilityBase, 16, Utility)

AROS_LP3(IPTR, CallHookPkt,
        AROS_LPA(struct Hook *, hook, A0),
        AROS_LPA(APTR, object, A2),
        AROS_LPA(APTR, paramPacket, A1),
        struct UtilityBase *, UtilityBase, 17, Utility)

AROS_LP2(void, Amiga2Date,
        AROS_LPA(ULONG, seconds, D0),
        AROS_LPA(struct ClockData *, result, A0),
        struct UtilityBase *, UtilityBase, 20, Utility)

AROS_LP1(ULONG, Date2Amiga,
        AROS_LPA(struct ClockData *, date, A0),
        struct UtilityBase *, UtilityBase, 21, Utility)

AROS_LP1(ULONG, CheckDate,
        AROS_LPA(struct ClockData *, date, A0),
        struct UtilityBase *, UtilityBase, 22, Utility)

AROS_LP2(LONG, SMult32,
        AROS_LPA(LONG, arg1, D0),
        AROS_LPA(LONG, arg2, D1),
        struct UtilityBase *, UtilityBase, 23, Utility)

AROS_LP2(ULONG, UMult32,
        AROS_LPA(ULONG, arg1, D0),
        AROS_LPA(ULONG, arg2, D1),
        struct UtilityBase *, UtilityBase, 24, Utility)

AROS_LP2(QUAD, SDivMod32,
        AROS_LPA(LONG, dividend, D0),
        AROS_LPA(LONG, divisor, D1),
        struct UtilityBase *, UtilityBase, 25, Utility)

AROS_LP2(ULONG, UDivMod32,
        AROS_LPA(ULONG, dividend, D0),
        AROS_LPA(ULONG, divisor, D1),
        struct UtilityBase *, UtilityBase, 26, Utility)

AROS_LP2(LONG, Stricmp,
        AROS_LPA(CONST_STRPTR, string1, A0),
        AROS_LPA(CONST_STRPTR, string2, A1),
        struct UtilityBase *, UtilityBase, 27, Utility)

AROS_LP3(LONG, Strnicmp,
        AROS_LPA(CONST_STRPTR, string1, A0),
        AROS_LPA(CONST_STRPTR, string2, A1),
        AROS_LPA(LONG, length, D0),
        struct UtilityBase *, UtilityBase, 28, Utility)

AROS_LP1(UBYTE, ToUpper,
        AROS_LPA(ULONG, character, D0),
        struct UtilityBase *, UtilityBase, 29, Utility)

AROS_LP1(UBYTE, ToLower,
        AROS_LPA(ULONG, character, D0),
        struct UtilityBase *, UtilityBase, 30, Utility)

AROS_LP2(void, ApplyTagChanges,
        AROS_LPA(struct TagItem *, list, A0),
        AROS_LPA(struct TagItem *, changelist, A1),
        struct UtilityBase *, UtilityBase, 31, Utility)

AROS_LP2(QUAD, SMult64,
        AROS_LPA(LONG, arg1, D0),
        AROS_LPA(LONG, arg2, D1),
        struct UtilityBase *, UtilityBase, 33, Utility)

AROS_LP2(UQUAD, UMult64,
        AROS_LPA(ULONG, arg1, D0),
        AROS_LPA(ULONG, arg2, D1),
        struct UtilityBase *, UtilityBase, 34, Utility)

AROS_LP3(ULONG, PackStructureTags,
        AROS_LPA(APTR, pack, A0),
        AROS_LPA(ULONG *, packTable, A1),
        AROS_LPA(struct TagItem *, tagList, A2),
        struct UtilityBase *, UtilityBase, 35, Utility)

AROS_LP3(ULONG, UnpackStructureTags,
        AROS_LPA(APTR, pack, A0),
        AROS_LPA(ULONG *, packTable, A1),
        AROS_LPA(struct TagItem *, tagList, A2),
        struct UtilityBase *, UtilityBase, 36, Utility)

AROS_LP2(BOOL, AddNamedObject,
        AROS_LPA(struct NamedObject *, nameSpace, A0),
        AROS_LPA(struct NamedObject *, object, A1),
        struct UtilityBase *, UtilityBase, 37, Utility)

AROS_LP2(struct NamedObject *, AllocNamedObjectA,
        AROS_LPA(CONST_STRPTR, name, A0),
        AROS_LPA(struct TagItem *, tagList, A1),
        struct UtilityBase *, UtilityBase, 38, Utility)

AROS_LP1(LONG, AttemptRemNamedObject,
        AROS_LPA(struct NamedObject *, object, A0),
        struct UtilityBase *, UtilityBase, 39, Utility)

AROS_LP3(struct NamedObject *, FindNamedObject,
        AROS_LPA(struct NamedObject *, nameSpace, A0),
        AROS_LPA(STRPTR, name, A1),
        AROS_LPA(struct NamedObject *, lastObject, A2),
        struct UtilityBase *, UtilityBase, 40, Utility)

AROS_LP1(void, FreeNamedObject,
        AROS_LPA(struct NamedObject *, object, A0),
        struct UtilityBase *, UtilityBase, 41, Utility)

AROS_LP1(STRPTR, NamedObjectName,
        AROS_LPA(struct NamedObject *, object, A0),
        struct UtilityBase *, UtilityBase, 42, Utility)

AROS_LP1(void, ReleaseNamedObject,
        AROS_LPA(struct NamedObject *, object, A0),
        struct UtilityBase *, UtilityBase, 43, Utility)

AROS_LP2(void, RemNamedObject,
        AROS_LPA(struct NamedObject *, object, A0),
        AROS_LPA(struct Message *, message, A1),
        struct UtilityBase *, UtilityBase, 44, Utility)

AROS_LP0(ULONG, GetUniqueID,
        struct UtilityBase *, UtilityBase, 45, Utility)

#endif /* CLIB_UTILITY_PROTOS_H */
