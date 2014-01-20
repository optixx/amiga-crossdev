* Startup.asm  - A working tested version of startup from Howtocode7
*
* Written by CJ of SAE... Freeware. Share and Enjoy!
*
* This code sets up one of two copperlists (one for PAL and one for NTSC)
* machines. It shows something to celebrate 3(?) years since the Berlin
* wall came down :-) Press left mouse button to return to normality.
* Tested on Amiga 3000 (ECS/V39 Kickstart) and Amiga 1200 (AGA/V39)
*
* $VER: startup.asm V7.tested (17.4.92)
* Valid on day of purchase only. No re-admission. No rain-checks.
* Now less bugs and more likely to work.
*
* Tested with Hisoft Devpac V3 and Argasm V1.09d
*
* Now added OS legal code to switch sprite resolutions. Ok, big deal
* this 'demo' doesn't use any sprites. But that's the sort of effort I
* go to on your behalf!   - CJ

DISABLE_MULTITASKING	equ		1			;set this if you don't want to risk ANY system interference (this also steals the blitter - if you don't use this, you have to ownblitter/disownblitter yourself
DISABLE_CACHE			equ		0			;set this if you write self modifying code (a better solution: use ClearCacheU instead, after having modified the code)
        opt     l-,CHKIMM                   ; auto link, optimise on

        section mycode,code             ; need not be in chipram
        incdir  "include:"

HAS_NDK equ 0
	ifne HAS_NDK
        include "exec/types.i"
        include "exec/exec.i"           ; the includes!
        include "graphics/gfxbase.i"
        include "intuition/screens.i"
        include "graphics/videocontrol.i"
		include "devices/input.i"
        include "hardware/intbits.i"
	else
		include "include/SysDefines.i"
	endc


        include "include/graphics_lib.i"    ; Well done CBM!
        include "include/exec_lib.i"        ; They keep on
        include "include/intuition_lib.i"   ; forgetting these!
        include "include/iconstartup.i"     ; Allows startup from icon
;dos libs
_LVOOutput equ -60
_LVOWrite equ -48

	xdef SystemAddVBlankRoutine
	xdef SystemRemoveVBlankRoutine
	xdef _ExitString

	xref	_main
	xref _VersionString


********** _InternalMain **********
* this is the mainloop called by the iconstartup code
* Returns:  d0=Result (currently always 0)


_InternalMain:
********** SystemStartup **********
        move.l  4.w,a6                  ; get ExecBase
        lea     intname(pc),a1          ;
        moveq   #39,d0                  ; Intuition lib needs Kickstart 3.0 or higher
        jsr     _LVOOpenLibrary(a6)
        move.l  d0,_IntuitionBase       ; store intuitionbase
;       Note! if this fails then kickstart is <V39.


        move.l  4.w,a6                  ; get ExecBase
        lea     gfxname(pc),a1          ; graphics name
        moveq   #33,d0                  ; Kickstart 1.2 or higher
        jsr     _LVOOpenLibrary(a6)
        tst.l   d0
        beq     .nogfxlibopen                     ; failed to open? Then quit
        move.l  d0,_GfxBase
        move.l  d0,a0
        move.l  gb_ActiView(a0),wbview  ; store current view address



        move.l  4.w,a6                  ; get ExecBase
        lea     dosname(pc),a1          ; dos name
        moveq   #33,d0                  ; Kickstart 1.2 or higher
        jsr     _LVOOpenLibrary(a6)
        tst.l   d0
        beq     .nodoslibopen                     ; failed to open? Then quit
        move.l  d0,_DosBase

        move.l  4.w,a6
        sub.l   a1,a1                   ; Zero - Find current task
        jsr     _LVOFindTask(a6)
        move.l  d0,_sigtask



;xxxxx inserted windows and input handler from piru
    move.l  4.w,a6
	; init msgport
	moveq	#-1,d0
	jsr	_LVOAllocSignal(a6)
	move.b	d0,_sigbit
	bmi	.nosignal

	; hide possible requesters since user has no way to
	; see or close them.
	move.l	_sigtask,a2
	moveq	#-1,d0
	move.l	pr_WindowPtr(a2),_oldwinptr
	move.l	d0,pr_WindowPtr(a2)

	; open input.device
	lea	inputname(pc),a0
	moveq	#0,d0
	moveq	#0,d1
	lea	_ioreq(pc),a1
	jsr	_LVOOpenDevice(a6)
	tst.b	d0
	bne	.noinput


	; install inputhandler
	lea	_ioreq(pc),a1
	move.w	#IND_ADDHANDLER,IO_COMMAND(a1)
	move.l	#_ih_is,IO_DATA(a1)
	jsr	_LVODoIO(a6)
	tst.b	d0
	bne	.inputhandlerinstallfail






        move.l  a2,a1
        moveq   #127,d0                 ; task priority to very high...
        jsr     _LVOSetTaskPri(a6)

        tst.l   _IntuitionBase          ; Intuition open? (V39 or higher)
        beq.s   .skip

        bsr     FixSpritesSetup         ; fix V39 sprite bug...


.skip
        move.l  _GfxBase,a6
		sub.l   a1,a1                   ; clear a1
        jsr     _LVOLoadView(a6)        ; Flush View to nothing
        jsr     _LVOWaitTOF(a6)         ; Wait once
        jsr     _LVOWaitTOF(a6)         ; Wait again.

; Note: Something could come along inbetween the LoadView and
; your copper setup. But only if you decide to run something
; else after you start loading the demo. That's far to stupid
; to bother testing for in my opininon!!!  If you want
; to stop this, then a Forbid() won't work (WaitTOF() disables
; Forbid state) so you'll have to do Forbid() *and* write your
; own WaitTOF() replacement. No thanks... I'll stick to running
; one demo at a time :-)


;xxxxx added
	ifne DISABLE_MULTITASKING
        move.l  4.w,a6
        jsr		_LVOForbid(a6)

        move.l	_GfxBase,a6
        jsr		_LVOOwnBlitter(a6)
	endc
        move.l	_GfxBase,a6
        jsr		_LVOWaitBlit(a6)
	ifne DISABLE_CACHE
        move.l   $4.w,a6
        cmp.w   #37,LIB_VERSION(a6)     ; check for Kickstart 2.04	;xxxxx change from v36
        blt.s   .oldks2                  ; nope...
        moveq   #0,d0
        moveq   #-1,d1
        jsr     _LVOCacheControl(a6)
		move.l	d0,OldCacheBits
.oldks2 
    endc
;xxxxx added end




        move.l  4.w,a6
        cmp.w   #37,LIB_VERSION(a6)     ; check for Kickstart 2.04
        blt.s   .oldks                  ; nope...

; kickstart 2 or higher.. We can check for NTSC properly...
        move.l  _GfxBase,a6
;xxxxx fixed to check at proper bit
;        btst    #2,gb_DisplayFlags(a6)  ; Check for PAL
        move.w  gb_DisplayFlags(a6),d0
        btst    #2,d0  ; Check for PAL
        bne.s   .pal
        bra.s   .ntsc

.oldks  ; you really should upgrade!  Check for V1.x kickstart

        move.l  4.w,a6                  ; execbase
        cmp.b   #50,VBlankFrequency(a6) ; Am I *running* PAL?
        bne.s   .ntsc

.pal
		move.l	#0,d0	;pal
		bra		.done
.ntsc
		moveq	#1,d0	;ntsc
.done
		jsr		_main

********** SystemShutdown **********
;xxxxx added
        move.l  4.w,a6                  ; execbase
	ifne DISABLE_CACHE
        cmp.w   #37,LIB_VERSION(a6)     ; check for Kickstart 2.04	;xxxxx changed from 36
        blt.s   .oldks3                  ; nope...		
        move.l   OldCacheBits,d0
        moveq   #-1,d1
        jsr     _LVOCacheControl(a6)
.oldks3
	endc
        move.l	_GfxBase,a6
        jsr		_LVOWaitBlit(a6)

	ifne DISABLE_MULTITASKING
        move.l   _GfxBase,a6
        jsr		_LVODisownBlitter(a6)		;give blitter back
        move.l  4.w,a6
        jsr		_LVOPermit(a6)
	endc
;xxxxx added end




        tst.l   _IntuitionBase          ; Intuiton open?
        beq.s   .sk                     ; if not, skip...

        bsr     ReturnSpritesToNormal

.sk
        move.l  _GfxBase,a6
		sub.l	a1,a1
        jsr     _LVOLoadView(a6)        ; Fix view
	     move.l  wbview(pc),a1
        jsr     _LVOLoadView(a6)        ; Fix view
        jsr     _LVOWaitTOF(a6)
        jsr     _LVOWaitTOF(a6)         ; wait for LoadView()

        move.l  gb_copinit(a6),$dff080.L  ; Kick it into life

;xxxxx added intuitionbase skip
        tst.l   _IntuitionBase          ; Intuition open? (V39 or higher)
        beq.s   .skip2
        move.l   _IntuitionBase,a6
        jsr      _LVORethinkDisplay(a6)     ; and rethink....
.skip2


;xxxxx added cleanup for piru's input handler
	move.l	4.w,a6
	; remove inputhandler
	lea	_ioreq(pc),a1
	move.w	#IND_REMHANDLER,IO_COMMAND(a1)
	move.l	#_ih_is,IO_DATA(a1)
	jsr	_LVODoIO(a6)
.inputhandlerinstallfail

	move.l	4.w,a6
	lea	_ioreq(pc),a1
	jsr	_LVOCloseDevice(a6)
.noinput:

	move.l	4.w,a6
	move.l	_sigtask(pc),a0
	move.l	_oldwinptr(pc),pr_WindowPtr(a0)

	moveq	#0,d0
	move.b	_sigbit(pc),d0
	jsr	_LVOFreeSignal(a6)
.nosignal:

		move.l	#_VersionString+7,a0		;Skip past $VER:
		jsr		_OutputString
		move.l	#_LineFeedString,a0
		jsr		_OutputString

		;print exit text if it has been set
		move.l	_ExitString,a0
		cmp.l	#0,a0
		beq		.noExitString
		jsr		_OutputString
		move.l	#_LineFeedString,a0
		jsr		_OutputString
.noExitString

        move.l  _DosBase,a1
        move.l  4.w,a6
        jsr     _LVOCloseLibrary(a6)    ; close dos.library
.nodoslibopen:

        move.l  _GfxBase,a1
        move.l  4.w,a6
        jsr     _LVOCloseLibrary(a6)    ; close graphics.library

.nogfxlibopen:

        move.l  _IntuitionBase,d0
        beq.s   .nointuitionlib                     ; if not open, don't close!
        move.l  d0,a1
        jsr     _LVOCloseLibrary(a6)
.nointuitionlib:

    moveq   #0,d0                   ; clear d0 for exit
        rts                             ; back to workbench/cli


;
; This bit fixes problems with sprites in V39 kickstart
; it is only called if intuition.library opens, which in this
; case is only if V39 or higher kickstart is installed. If you
; require intuition.library you will need to change the
; openlibrary code to open V33+ Intuition and add a V39 test before
; calling this code (which is only required for V39+ Kickstart)
;

FixSpritesSetup:
        move.l   _IntuitionBase,a6          ; open intuition.library first!
        lea      wbname,a0
        jsr      _LVOLockPubScreen(a6)

        tst.l    d0                         ; Could I lock Workbench?
        beq.s    .error                     ; if not, error
        move.l   d0,wbscreen
        move.l   d0,a0

        move.l   sc_ViewPort+vp_ColorMap(a0),a0
        lea      taglist,a1
        move.l   _GfxBase,a6                ; open graphics.library first!
        jsr      _LVOVideoControl(a6)       ;

        move.l   resolution,oldres          ; store old resolution

        move.l   #SPRITERESN_140NS,resolution
        move.l   #VTAG_SPRITERESN_SET,taglist

        move.l   wbscreen,a0
        move.l   sc_ViewPort+vp_ColorMap(a0),a0
        lea      taglist,a1
        jsr      _LVOVideoControl(a6)       ; set sprites to lores

        move.l   wbscreen,a0
        move.l   _IntuitionBase,a6
        jsr      _LVOMakeScreen(a6)
        jsr      _LVORethinkDisplay(a6)     ; and rebuild system copperlists

; Sprites are now set back to 140ns in a system friendly manner!

.error
        rts

ReturnSpritesToNormal:
; If you mess with sprite resolution you must return resolution
; back to workbench standard on return! This code will do that...

        move.l   wbscreen,d0
        beq.s    .error
        move.l   d0,a0

        move.l   oldres,resolution          ; change taglist
        lea      taglist,a1
        move.l   sc_ViewPort+vp_ColorMap(a0),a0
        move.l   _GfxBase,a6
        jsr      _LVOVideoControl(a6)       ; return sprites to normal.

        move.l   _IntuitionBase,a6
        move.l   wbscreen,a0
        jsr      _LVOMakeScreen(a6)         ; and rebuild screen

        move.l   wbscreen,a1
        sub.l    a0,a0
        jsr      _LVOUnlockPubScreen(a6)

.error
        rts


********** SystemAddVBlankRoutine **********
* adds vblank handler
* Input:  a0=vblank interrupt routine
* Return: none
SystemAddVBlankRoutine
		move.l	a0,VBlankServerRoutine
        move.l   $4.w,a6
	    moveq.l  #INTB_VERTB,d0
        lea      VBlankServer(pc),a1
        jsr      _LVOAddIntServer(a6)       ;Add my interrupt to system list
		rts
********** SystemRemoveVBlankRoutine **********
* remove the vblank handler set in SystemAddVBlankRoutine
* Input:  none
* Return: none
SystemRemoveVBlankRoutine
        move.l   $4.w,a6
        moveq.l  #INTB_VERTB,d0		       ;Change for copper interrupt.
        lea      VBlankServer(pc),a1
        jsr      _LVORemIntServer(a6)         ;Remove my interrupt
		rts

			cnop 0,4
_msgport:
	dc.l	0,0		; LN_SUCC, LN_PRED
	dc.b	NT_MSGPORT,0	; LN_TYPE, LN_PRI
	dc.l	0		; LN_NAME
	dc.b	PA_SIGNAL	; MP_FLAGS
_sigbit:
	dc.b	-1		; MP_SIGBIT
_sigtask:
	dc.l	0		; MP_SIGTASK
.head:
	dc.l	.tail		; MLH_HEAD
.tail:
	dc.l	0		; MLH_TAIL
	dc.l	.head		; MLH_TAILPRED

_ioreq:
	dc.l	0,0		; LN_SUCC, LN_PRED
	dc.b	NT_REPLYMSG,0	; LN_TYPE, LN_PRI
	dc.l	0		; LN_NAME
	dc.l	_msgport	; MN_REPLYPORT
	dc.w	IOSTD_SIZE	; MN_LENGTH
	dc.l	0		; IO_DEVICE
	dc.l	0		; IO_UNIT
	dc.w	0		; IO_COMMAND
	dc.b	0,0		; IO_FLAGS, IO_ERROR
	dc.l	0		; IO_ACTUAL
	dc.l	0		; IO_LENGTH
	dc.l	0		; IO_DATA
	dc.l	0		; IO_OFFSET

_ih_is:
	dc.l	0,0		; LN_SUCC, LN_PRED
	dc.b	NT_INTERRUPT,127	; LN_TYPE, LN_PRI ** highest priority ** 
	dc.l	ih_name	; LN_NAME
	dc.l	0		; IS_DATA
	dc.l	.ih_code	; IS_CODE

.ih_code:
	move.l	a0,d0
.loop:
	move.b	#IECLASS_NULL,ie_Class(a0)
	move.l	(a0),a0
	move.l	a0,d1
	bne.b	.loop

	; d0 is the original a0
	rts

********** _OutputString **********
* call this to print text in the shell output window
* Input: a0=text string to print
* Destroys: a0/a1/d0/d1
* Returns:  nothing

_OutputString
	movem.l	d2-d3/a6,-(a7)
	move.l	_DosBase,a6
	move.l	a0,-(a7)
	jsr		_LVOOutput(a6)
	move	d0,d1
	move.l	(a7)+,d2
	move.l	d2,a0
	moveq.l	#-1,d3
.countchars
	addq.l	#1,d3
	tst.b	(a0)+
	bne		.countchars
	jsr		_LVOWrite(a6)

	movem.l	(a7)+,d2-d3/a6
	rts


VBlankServer:
      dc.l  0,0                     ;ln_Succ,ln_Pred
      dc.b  NT_INTERRUPT,12                     ;ln_Type,ln_Pri
      dc.l  VBlankName                 ;ln_Name
      dc.l  $dff000						;is_Data
VBlankServerRoutine
      dc.l  0             ;is_Code
VBlankName:
      dc.b "VBlank",0

ih_name:
	dc.b	'eat-events inputhandler',0
_LineFeedString:
	dc.b	$d,$a,0
			cnop 0,4
_ExitString		dc.l	0
_oldwinptr:		dc.l	0

OldCacheBits	dc.l	0

wbview          dc.l  0
	xdef _GfxBase
_GfxBase        dc.l  0
	xdef _DosBase
_DosBase        dc.l  0
_IntuitionBase  dc.l  0
oldres          dc.l  0
wbscreen        dc.l  0

taglist         dc.l  VTAG_SPRITERESN_GET
resolution      dc.l  SPRITERESN_ECS
                dc.l  TAG_DONE,0

wbname          dc.b  "Workbench",0
gfxname         dc.b  "graphics.library",0
dosname         dc.b  "dos.library",0
intname         dc.b  "intuition.library",0
inputname:		dc.b	'input.device',0



