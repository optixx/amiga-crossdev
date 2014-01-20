#ifndef CLIB_CYBERGRAPHICS_PROTOS_H
#define CLIB_CYBERGRAPHICS_PROTOS_H

/*
    *** Automatically generated from 'cybergraphics.conf'. Edits will be lost. ***
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>
#include <utility/tagitem.h>

AROS_LP1(BOOL, IsCyberModeID,
        AROS_LPA(ULONG, modeID, D0),
        struct Library *, CyberGfxBase, 9, Cybergraphics)

AROS_LP1(ULONG, BestCModeIDTagList,
        AROS_LPA(struct TagItem *, tags, A0),
        struct Library *, CyberGfxBase, 10, Cybergraphics)

AROS_LP1(struct List *, AllocCModeListTagList,
        AROS_LPA(struct TagItem *, tags, A1),
        struct Library *, CyberGfxBase, 12, Cybergraphics)

AROS_LP1(void, FreeCModeList,
        AROS_LPA(struct List *, modeList, A0),
        struct Library *, CyberGfxBase, 13, Cybergraphics)

AROS_LP10(LONG, ScalePixelArray,
        AROS_LPA(APTR, srcRect, A0),
        AROS_LPA(UWORD, SrcW, D0),
        AROS_LPA(UWORD, SrcH, D1),
        AROS_LPA(UWORD, SrcMod, D2),
        AROS_LPA(struct RastPort *, RastPort, A1),
        AROS_LPA(UWORD, DestX, D3),
        AROS_LPA(UWORD, DestY, D4),
        AROS_LPA(UWORD, DestW, D5),
        AROS_LPA(UWORD, DestH, D6),
        AROS_LPA(UBYTE, SrcFormat, D7),
        struct Library *, CyberGfxBase, 15, Cybergraphics)

AROS_LP2(ULONG, GetCyberMapAttr,
        AROS_LPA(struct BitMap *, bitMap, A0),
        AROS_LPA(ULONG, attribute, D0),
        struct Library *, CyberGfxBase, 16, Cybergraphics)

AROS_LP2(ULONG, GetCyberIDAttr,
        AROS_LPA(ULONG, attribute, D0),
        AROS_LPA(ULONG, DisplayModeID, D1),
        struct Library *, CyberGfxBase, 17, Cybergraphics)

AROS_LP3(ULONG, ReadRGBPixel,
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(UWORD, x, D0),
        AROS_LPA(UWORD, y, D1),
        struct Library *, CyberGfxBase, 18, Cybergraphics)

AROS_LP4(LONG, WriteRGBPixel,
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(UWORD, x, D0),
        AROS_LPA(UWORD, y, D1),
        AROS_LPA(ULONG, pixel, D2),
        struct Library *, CyberGfxBase, 19, Cybergraphics)

AROS_LP10(ULONG, ReadPixelArray,
        AROS_LPA(APTR, dst, A0),
        AROS_LPA(UWORD, destx, D0),
        AROS_LPA(UWORD, desty, D1),
        AROS_LPA(UWORD, dstmod, D2),
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(UWORD, srcx, D3),
        AROS_LPA(UWORD, srcy, D4),
        AROS_LPA(UWORD, width, D5),
        AROS_LPA(UWORD, height, D6),
        AROS_LPA(UBYTE, dstformat, D7),
        struct Library *, CyberGfxBase, 20, Cybergraphics)

AROS_LP10(ULONG, WritePixelArray,
        AROS_LPA(APTR, src, A0),
        AROS_LPA(UWORD, srcx, D0),
        AROS_LPA(UWORD, srcy, D1),
        AROS_LPA(UWORD, srcmod, D2),
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(UWORD, destx, D3),
        AROS_LPA(UWORD, desty, D4),
        AROS_LPA(UWORD, width, D5),
        AROS_LPA(UWORD, height, D6),
        AROS_LPA(UBYTE, srcformat, D7),
        struct Library *, CyberGfxBase, 21, Cybergraphics)

AROS_LP7(ULONG, MovePixelArray,
        AROS_LPA(UWORD, SrcX, D0),
        AROS_LPA(UWORD, SrcY, D1),
        AROS_LPA(struct RastPort *, RastPort, A1),
        AROS_LPA(UWORD, DstX, D2),
        AROS_LPA(UWORD, DstY, D3),
        AROS_LPA(UWORD, SizeX, D4),
        AROS_LPA(UWORD, SizeY, D5),
        struct Library *, CyberGfxBase, 22, Cybergraphics)

AROS_LP5(ULONG, InvertPixelArray,
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(UWORD, destx, D0),
        AROS_LPA(UWORD, desty, D1),
        AROS_LPA(UWORD, width, D2),
        AROS_LPA(UWORD, height, D3),
        struct Library *, CyberGfxBase, 24, Cybergraphics)

AROS_LP6(ULONG, FillPixelArray,
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(UWORD, destx, D0),
        AROS_LPA(UWORD, desty, D1),
        AROS_LPA(UWORD, width, D2),
        AROS_LPA(UWORD, height, D3),
        AROS_LPA(ULONG, pixel, D4),
        struct Library *, CyberGfxBase, 25, Cybergraphics)

AROS_LP2(void, CVideoCtrlTagList,
        AROS_LPA(struct ViewPort *, vp, A0),
        AROS_LPA(struct TagItem *, tags, A1),
        struct Library *, CyberGfxBase, 27, Cybergraphics)

AROS_LP2(APTR, LockBitMapTagList,
        AROS_LPA(APTR, bitmap, A0),
        AROS_LPA(struct TagItem *, tags, A1),
        struct Library *, CyberGfxBase, 28, Cybergraphics)

AROS_LP1(void, UnLockBitMap,
        AROS_LPA(APTR, Handle, A0),
        struct Library *, CyberGfxBase, 29, Cybergraphics)

AROS_LP2(void, UnLockBitMapTagList,
        AROS_LPA(APTR, Handle, A0),
        AROS_LPA(struct TagItem *, Tags, A1),
        struct Library *, CyberGfxBase, 30, Cybergraphics)

AROS_LP7(ULONG, ExtractColor,
        AROS_LPA(struct RastPort *, RastPort, A0),
        AROS_LPA(struct BitMap *, SingleMap, A1),
        AROS_LPA(ULONG, Colour, D0),
        AROS_LPA(ULONG, sX, D1),
        AROS_LPA(ULONG, sY, D2),
        AROS_LPA(ULONG, Width, D3),
        AROS_LPA(ULONG, Height, D4),
        struct Library *, CyberGfxBase, 31, Cybergraphics)

AROS_LP11(LONG, WriteLUTPixelArray,
        AROS_LPA(APTR, srcRect, A0),
        AROS_LPA(UWORD, SrcX, D0),
        AROS_LPA(UWORD, SrcY, D1),
        AROS_LPA(UWORD, SrcMod, D2),
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(APTR, CTable, A2),
        AROS_LPA(UWORD, DestX, D3),
        AROS_LPA(UWORD, DestY, D4),
        AROS_LPA(UWORD, SizeX, D5),
        AROS_LPA(UWORD, SizeY, D6),
        AROS_LPA(UBYTE, CTabFormat, D7),
        struct Library *, CyberGfxBase, 33, Cybergraphics)

AROS_LP10(ULONG, WritePixelArrayAlpha,
        AROS_LPA(APTR, src, A0),
        AROS_LPA(UWORD, srcx, D0),
        AROS_LPA(UWORD, srcy, D1),
        AROS_LPA(UWORD, srcmod, D2),
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(UWORD, destx, D3),
        AROS_LPA(UWORD, desty, D4),
        AROS_LPA(UWORD, width, D5),
        AROS_LPA(UWORD, height, D6),
        AROS_LPA(ULONG, globalalpha, D7),
        struct Library *, CyberGfxBase, 36, Cybergraphics)

AROS_LP8(void, BltTemplateAlpha,
        AROS_LPA(APTR, src, A0),
        AROS_LPA(LONG, srcx, D0),
        AROS_LPA(LONG, srcmod, D1),
        AROS_LPA(struct RastPort *, rp, A1),
        AROS_LPA(LONG, destx, D2),
        AROS_LPA(LONG, desty, D3),
        AROS_LPA(LONG, width, D4),
        AROS_LPA(LONG, height, D5),
        struct Library *, CyberGfxBase, 37, Cybergraphics)

#endif /* CLIB_CYBERGRAPHICS_PROTOS_H */
