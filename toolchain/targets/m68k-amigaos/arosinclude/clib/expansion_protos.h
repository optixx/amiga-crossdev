#ifndef CLIB_EXPANSION_PROTOS_H
#define CLIB_EXPANSION_PROTOS_H

/*
    *** Automatically generated from 'expansion.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

AROS_LP1(void, AddConfigDev,
        AROS_LPA(struct ConfigDev *, configDev, A0),
        struct Library *, ExpansionBase, 5, Expansion)

AROS_LP4(BOOL, AddBootNode,
        AROS_LPA(LONG, bootPri, D0),
        AROS_LPA(ULONG, flags, D1),
        AROS_LPA(struct DeviceNode *, deviceNode, A0),
        AROS_LPA(struct ConfigDev *, configDev, A1),
        struct Library *, ExpansionBase, 6, Expansion)

AROS_LP1(void, AllocBoardMem,
        AROS_LPA(ULONG, slotSpec, D0),
        struct Library *, ExpansionBase, 7, Expansion)

AROS_LP0(struct ConfigDev *, AllocConfigDev,
        struct Library *, ExpansionBase, 8, Expansion)

AROS_LP2(APTR, AllocExpansionMem,
        AROS_LPA(ULONG, numSlots, D0),
        AROS_LPA(ULONG, slotAlign, D1),
        struct Library *, ExpansionBase, 9, Expansion)

AROS_LP2(void, ConfigBoard,
        AROS_LPA(APTR, board, A0),
        AROS_LPA(struct ConfigDev *, configDev, A1),
        struct Library *, ExpansionBase, 10, Expansion)

AROS_LP1(void, ConfigChain,
        AROS_LPA(APTR, baseAddr, A0),
        struct Library *, ExpansionBase, 11, Expansion)

AROS_LP3(struct ConfigDev *, FindConfigDev,
        AROS_LPA(struct ConfigDev *, oldConfigDev, A0),
        AROS_LPA(LONG, manufacturer, D0),
        AROS_LPA(LONG, product, D1),
        struct Library *, ExpansionBase, 12, Expansion)

AROS_LP2(void, FreeBoardMem,
        AROS_LPA(ULONG, startSlot, D0),
        AROS_LPA(ULONG, slotSpec, D1),
        struct Library *, ExpansionBase, 13, Expansion)

AROS_LP1(void, FreeConfigDev,
        AROS_LPA(struct ConfigDev *, configDev, A0),
        struct Library *, ExpansionBase, 14, Expansion)

AROS_LP2(void, FreeExpansionMem,
        AROS_LPA(ULONG, startSlot, D0),
        AROS_LPA(ULONG, numSlots, D1),
        struct Library *, ExpansionBase, 15, Expansion)

AROS_LP2(UBYTE, ReadExpansionByte,
        AROS_LPA(APTR, board, A0),
        AROS_LPA(ULONG, offset, D0),
        struct Library *, ExpansionBase, 16, Expansion)

AROS_LP2(void, ReadExpansionRom,
        AROS_LPA(APTR, board, A0),
        AROS_LPA(struct ConfigDev *, configDev, A1),
        struct Library *, ExpansionBase, 17, Expansion)

AROS_LP1(void, RemConfigDev,
        AROS_LPA(struct ConfigDev *, configDev, A0),
        struct Library *, ExpansionBase, 18, Expansion)

AROS_LP3(void, WriteExpansionByte,
        AROS_LPA(APTR, board, A0),
        AROS_LPA(ULONG, offset, D0),
        AROS_LPA(ULONG, byte, D1),
        struct Library *, ExpansionBase, 19, Expansion)

AROS_LP0(void, ObtainConfigBinding,
        struct Library *, ExpansionBase, 20, Expansion)

AROS_LP0(void, ReleaseConfigBinding,
        struct Library *, ExpansionBase, 21, Expansion)

AROS_LP2(void, SetCurrentBinding,
        AROS_LPA(struct CurrentBinding *, currentBinding, A0),
        AROS_LPA(ULONG, bindingSize, D0),
        struct Library *, ExpansionBase, 22, Expansion)

AROS_LP2(ULONG, GetCurrentBinding,
        AROS_LPA(struct CurrentBinding *, currentBinding, A0),
        AROS_LPA(ULONG, bindingSize, D0),
        struct Library *, ExpansionBase, 23, Expansion)

AROS_LP1(struct DeviceNode *, MakeDosNode,
        AROS_LPA(APTR, parmPacket, A0),
        struct Library *, ExpansionBase, 24, Expansion)

AROS_LP3(BOOL, AddDosNode,
        AROS_LPA(LONG, bootPri, D0),
        AROS_LPA(ULONG, flags, D1),
        AROS_LPA(struct DeviceNode *, deviceNode, A0),
        struct Library *, ExpansionBase, 25, Expansion)

#endif /* CLIB_EXPANSION_PROTOS_H */
