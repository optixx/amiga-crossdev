#ifndef CLIB_LOCALE_PROTOS_H
#define CLIB_LOCALE_PROTOS_H

/*
    *** Automatically generated from 'locale.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>
#include <utility/hooks.h>
#include <dos/datetime.h>
#include <libraries/locale.h>

struct Catalog *OpenCatalog
(
    struct Locale  *locale,
    STRPTR          name,
    ULONG           tag1,
    ...
);

AROS_LP1(void, CloseCatalog,
        AROS_LPA(struct Catalog *, catalog, A0),
        struct LocaleBase *, LocaleBase, 6, Locale)

AROS_LP1(void, CloseLocale,
        AROS_LPA(struct Locale *, locale, A0),
        struct LocaleBase *, LocaleBase, 7, Locale)

AROS_LP2(ULONG, ConvToLower,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 8, Locale)

AROS_LP2(ULONG, ConvToUpper,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 9, Locale)

AROS_LP4(void, FormatDate,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(STRPTR, formatString, A1),
        AROS_LPA(struct DateStamp *, date, A2),
        AROS_LPA(struct Hook *, hook, A3),
        struct LocaleBase *, LocaleBase, 10, Locale)

AROS_LP4(APTR, FormatString,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(STRPTR, fmtTemplate, A1),
        AROS_LPA(APTR, dataStream, A2),
        AROS_LPA(struct Hook *, putCharFunc, A3),
        struct LocaleBase *, LocaleBase, 11, Locale)

AROS_LP3(CONST_STRPTR, GetCatalogStr,
        AROS_LPA(const struct Catalog *, catalog, A0),
        AROS_LPA(ULONG, stringNum, D0),
        AROS_LPA(CONST_STRPTR, defaultString, A1),
        struct LocaleBase *, LocaleBase, 12, Locale)

AROS_LP2(STRPTR, GetLocaleStr,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, stringNum, D0),
        struct LocaleBase *, LocaleBase, 13, Locale)

AROS_LP2(ULONG, IsAlNum,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 14, Locale)

AROS_LP2(ULONG, IsAlpha,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 15, Locale)

AROS_LP2(ULONG, IsCntrl,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 16, Locale)

AROS_LP2(ULONG, IsDigit,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 17, Locale)

AROS_LP2(ULONG, IsGraph,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 18, Locale)

AROS_LP2(ULONG, IsLower,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 19, Locale)

AROS_LP2(ULONG, IsPrint,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 20, Locale)

AROS_LP2(ULONG, IsPunct,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 21, Locale)

AROS_LP2(ULONG, IsSpace,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 22, Locale)

AROS_LP2(ULONG, IsUpper,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 23, Locale)

AROS_LP2(ULONG, IsXDigit,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(ULONG, character, D0),
        struct LocaleBase *, LocaleBase, 24, Locale)

AROS_LP3(struct Catalog *, OpenCatalogA,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(STRPTR, name, A1),
        AROS_LPA(struct TagItem *, tags, A2),
        struct LocaleBase *, LocaleBase, 25, Locale)

AROS_LP1(struct Locale *, OpenLocale,
        AROS_LPA(STRPTR, name, A0),
        struct LocaleBase *, LocaleBase, 26, Locale)

AROS_LP4(BOOL, ParseDate,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(struct DateStamp *, date, A1),
        AROS_LPA(STRPTR, fmtTemplate, A2),
        AROS_LPA(struct Hook *, getCharFunc, A3),
        struct LocaleBase *, LocaleBase, 27, Locale)

AROS_LP1(struct Locale *, LocalePrefsUpdate,
        AROS_LPA(struct Locale *, locale, A0),
        struct LocaleBase *, LocaleBase, 28, Locale)

AROS_LP5(ULONG, StrConvert,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(STRPTR, string, A1),
        AROS_LPA(APTR, buffer, A2),
        AROS_LPA(ULONG, bufferSize, D0),
        AROS_LPA(ULONG, type, D1),
        struct LocaleBase *, LocaleBase, 29, Locale)

AROS_LP5(LONG, StrnCmp,
        AROS_LPA(struct Locale *, locale, A0),
        AROS_LPA(STRPTR, string1, A1),
        AROS_LPA(STRPTR, string2, A2),
        AROS_LPA(LONG, length, D0),
        AROS_LPA(ULONG, type, D1),
        struct LocaleBase *, LocaleBase, 30, Locale)

#endif /* CLIB_LOCALE_PROTOS_H */
