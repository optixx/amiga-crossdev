    opt   l+,o+,ow+,ow1-,ow2-,ow6-,d+,CHKIMM

    xref SystemAddVBlankRoutine
    xref SystemRemoveVBlankRoutine
    xref P61_Init
    xref P61_Music
    xref P61_End
    xdef _main
    xref _GfxBase

    section code,code             ; need not be in chipram

    include "include/exec_lib.i"
    include "include/graphics_lib.i"

_customBase     equ $dff000
_CIAA           equ $bfe001
_CIAB           equ $bfd000

    xdef _customBase
    xdef _CIAA
    xdef _CIAB
    xdef _VersionString

_VersionString  dc.b    0,"$VER: Demo 2.0 Jan 20 2014",0
even

_main:                              ;startup code is complete, this is where the main code starts,  - called from startup.asm
    tst.w   d0                      ;is it pal
    bne     .quitOnStartup          ;not pal, exit now!

    lea     _customBase,a6
    move.l  #copperlist,$80(a6)     ; bang it straight in.

    lea     module,a0               ;the P61converted module you want to start
    moveq   #0,d0                   ;if CIA=1: 1=PAL,2=NTSC,0=auto (only if exec=1)
    sub.l   a1,a1                   ;0 if no external samples
    sub.l   a2,a2                   ;if crunched samples: Samplebuffer-addr
    bsr     P61_Init                ;Init. Trashes all but a6, d0=0 on return if ok

.lp0
    move.l  _GfxBase,a6
    jsr     _LVOWaitTOF(a6)         ; Wait for one frame - this allows system to run its' stuff (disk etc.)
    btst    #6,$bfe001              ; make sure mouse is NOT held down when starting (avoid instant exit)
    beq.s   .lp0

    lea     VBlankInterrupt(PC),a0
    bsr     SystemAddVBlankRoutine
.lp
    move.l  _GfxBase,a6
    jsr     _LVOWaitTOF(a6)         ; Wait for one frame - this allows system to run its' stuff (disk etc.)

    move.w  #$0f0,d0
    lea     $dff180,a0

    btst    #6,$bfe001              ; ok.. I'll do an input
    bne.s   .lp                     ; handler next time.

    bsr     SystemRemoveVBlankRoutine

    lea     _customBase,a6
    bsr     P61_End
.quitOnStartup
    rts

VBlankInterrupt:
    movem.l  d2-d7/a2-a4,-(sp)      ; all other registers can be trashed
    move.l    a1,a6                 ; customBase - coming from is_data
    bsr       P61_Music             ; P61_Music. Trashes all, a6=$dff000+C at exit.
    movem.l  (sp)+,d2-d7/a2-a4

                                    ; If you set your interrupt to priority 10 or higher then
                                    ; a0 must point at $dff000 on exit.

    lea       _customBase,a0
    moveq    #0,d0                  ; must set Z flag on exit!
    rts                             ; Not rte!!!



    section data,data_c           ;  keep data & code seperate!

copperlist:
    dc.w    $100,$0200      ; otherwise no display!
    dc.w    $180,$fff
    dc.w    $8107,$fffe     ; wait for $8107,$fffe
    dc.w    $180
    dc.w    $f0f            ; background red
    dc.w    $d607,$fffe     ; wait for $d607,$fffe
    dc.w    $180,$ff0       ; background yellow
    dc.w    $ffff,$fffe
    dc.w    $ffff,$fffe


    section music,data_c

module:
    incbin "assets/song02.mod"

end
