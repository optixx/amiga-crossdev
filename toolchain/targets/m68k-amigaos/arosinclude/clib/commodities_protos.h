#ifndef CLIB_COMMODITIES_PROTOS_H
#define CLIB_COMMODITIES_PROTOS_H

/*
    *** Automatically generated from 'commodities.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <exec/nodes.h>
#include <devices/inputevent.h>
#include <devices/keymap.h>
#include <libraries/commodities.h>

AROS_LP3(CxObj *, CreateCxObj,
        AROS_LPA(ULONG, type, D0),
        AROS_LPA(IPTR, arg1, A0),
        AROS_LPA(IPTR, arg2, A1),
        struct Library *, CxBase, 5, Commodities)

AROS_LP2(CxObj *, CxBroker,
        AROS_LPA(struct NewBroker *, nb, A0),
        AROS_LPA(LONG *, error, D0),
        struct Library *, CxBase, 6, Commodities)

AROS_LP2(LONG, ActivateCxObj,
        AROS_LPA(CxObj *, co, A0),
        AROS_LPA(LONG, true, D0),
        struct Library *, CxBase, 7, Commodities)

AROS_LP1(void, DeleteCxObj,
        AROS_LPA(CxObj *, co, A0),
        struct Library *, CxBase, 8, Commodities)

AROS_LP1(void, DeleteCxObjAll,
        AROS_LPA(CxObj *, co, A0),
        struct Library *, CxBase, 9, Commodities)

AROS_LP1(ULONG, CxObjType,
        AROS_LPA(CxObj *, co, A0),
        struct Library *, CxBase, 10, Commodities)

AROS_LP1(LONG, CxObjError,
        AROS_LPA(CxObj *, co, A0),
        struct Library *, CxBase, 11, Commodities)

AROS_LP1(void, ClearCxObjError,
        AROS_LPA(CxObj *, co, A0),
        struct Library *, CxBase, 12, Commodities)

AROS_LP2(LONG, SetCxObjPri,
        AROS_LPA(CxObj *, co, A0),
        AROS_LPA(LONG, pri, D0),
        struct Library *, CxBase, 13, Commodities)

AROS_LP2(void, AttachCxObj,
        AROS_LPA(CxObj *, headObj, A0),
        AROS_LPA(CxObj *, co, A1),
        struct Library *, CxBase, 14, Commodities)

AROS_LP2(void, EnqueueCxObj,
        AROS_LPA(CxObj *, headObj, A0),
        AROS_LPA(CxObj *, co, A1),
        struct Library *, CxBase, 15, Commodities)

AROS_LP3(void, InsertCxObj,
        AROS_LPA(CxObj *, headObj, A0),
        AROS_LPA(CxObj *, co, A1),
        AROS_LPA(CxObj *, pred, A2),
        struct Library *, CxBase, 16, Commodities)

AROS_LP1(void, RemoveCxObj,
        AROS_LPA(CxObj *, co, A0),
        struct Library *, CxBase, 17, Commodities)

AROS_LP2(void, SetTranslate,
        AROS_LPA(CxObj *, translator, A0),
        AROS_LPA(struct InputEvent *, events, A1),
        struct Library *, CxBase, 19, Commodities)

AROS_LP2(void, SetFilter,
        AROS_LPA(CxObj *, filter, A0),
        AROS_LPA(STRPTR, text, A1),
        struct Library *, CxBase, 20, Commodities)

AROS_LP2(void, SetFilterIX,
        AROS_LPA(CxObj *, filter, A0),
        AROS_LPA(IX *, ix, A1),
        struct Library *, CxBase, 21, Commodities)

AROS_LP2(LONG, ParseIX,
        AROS_LPA(CONST_STRPTR, desc, A0),
        AROS_LPA(IX *, ix, A1),
        struct Library *, CxBase, 22, Commodities)

AROS_LP1(ULONG, CxMsgType,
        AROS_LPA(CxMsg *, cxm, A0),
        struct Library *, CxBase, 23, Commodities)

AROS_LP1(APTR, CxMsgData,
        AROS_LPA(CxMsg *, cxm, A0),
        struct Library *, CxBase, 24, Commodities)

AROS_LP1(LONG, CxMsgID,
        AROS_LPA(CxMsg *, cxm, A0),
        struct Library *, CxBase, 25, Commodities)

AROS_LP3(void, DivertCxMsg,
        AROS_LPA(CxMsg *, cxm, A0),
        AROS_LPA(CxObj *, headObj, A1),
        AROS_LPA(CxObj *, returnObj, A2),
        struct Library *, CxBase, 26, Commodities)

AROS_LP2(void, RouteCxMsg,
        AROS_LPA(CxMsg *, cxm, A0),
        AROS_LPA(CxObj *, co, A1),
        struct Library *, CxBase, 27, Commodities)

AROS_LP1(void, DisposeCxMsg,
        AROS_LPA(CxMsg *, cxm, A0),
        struct Library *, CxBase, 28, Commodities)

AROS_LP3(BOOL, InvertKeyMap,
        AROS_LPA(ULONG, ansiCode, D0),
        AROS_LPA(struct InputEvent *, event, A0),
        AROS_LPA(struct KeyMap *, km, A1),
        struct Library *, CxBase, 29, Commodities)

AROS_LP1(void, AddIEvents,
        AROS_LPA(struct InputEvent *, events, A0),
        struct Library *, CxBase, 30, Commodities)

AROS_LP1(LONG, GetBrokerList,
        AROS_LPA(struct List *, CopyofList, A0),
        struct Library *, CxBase, 31, Commodities)

AROS_LP1(void, FreeBrokerList,
        AROS_LPA(struct List *, brokerList, A0),
        struct Library *, CxBase, 32, Commodities)

AROS_LP2(ULONG, CxNotify,
        AROS_LPA(STRPTR, name, A0),
        AROS_LPA(ULONG, command, D0),
        struct Library *, CxBase, 33, Commodities)

AROS_LP2(BOOL, MatchIX,
        AROS_LPA(struct InputEvent *, event, A0),
        AROS_LPA(IX *, ix, A1),
        struct Library *, CxBase, 34, Commodities)

#endif /* CLIB_COMMODITIES_PROTOS_H */
