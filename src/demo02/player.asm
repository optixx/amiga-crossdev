
  opt   l+,o+,ow+,ow1-,ow2-,ow6-,d+,CHKIMM

	xdef P61_Init
	xdef P61_End
	xdef P61_Music
	xdef P61_SetPosition

use	=-1	;Change! to the USE hexcode from P61con for a big CPU-time gain
		;for this module by Gladiator: $9410.
C	=0	;$dff000+C is any custom base you happen to have in a6
		;just set to 0 if you're using the normal $dff000.





fade	=0	;enable channel volume fading from your demo
exec	=1	;0 if execbase is destroyed, such as in a trackmo.
noshorts=0	;0 if any inst shorter than ~300 bytes? Or pad short insts.
lev6=1		;"FBI mode" - ie. "Free the B-timer Interrupt".
		;1 to keep the timer B int at least for setting DMA.

		;Requirements: noshorts=1, system=0 (this is a hardware mode
		;only implementation.). CIA=1 likely works if YOU make sure DMA
		;is set at 11 scanlines (700 usecs) after the CIA-A interrupt.
		;AsmOne will warn you if requirements are wrong.

		;DMA bits will be poked in the address you pass in A4 to
		;P61_init. (Update P61_DMApokeAddr during playing if necessary,
		;for example if switching Coppers.)

		;P61_Init will still save old timer B settings, and initialize
		;it. P61_End will still restore timer B settings from P61_Init.
		;So don't count on it 'across calls' to these routines.
		;Using it after P61_Init and before P61_End is fine.

optjmp	=1 ;0=check for jump beyond end of song. Perhaps enable if you
		;play unknown P61 songs with erroneous Bxx/Dxx commands in them

splitchans=0	;#channels to be split off to be decrunched at "playtime frame"
		;0=use normal "decrunch all channels in the same frame"
		;Experiment to find minimum rastertime, but it should be 1 or 2
		;for 3-4 channels songs and 0 or 1 with less channels.

split4	=0	;overrides splitchans to decrunch 1 chan/frame.
		;Incompatible with F03, F02, and F01 speeds in the song!
		;if enabled, will insert an up to 2 frames extra wait, if you
		;use "instant" setposition.

playflag=1	;1 if you want be able to disable music at runtime. If 0, you
		;can still do this by just, you know, not call P61_Music...

suppF01	=1	;1=support the F01 command (step 1 note per frame=50/second)

dupedec	=0	;0=save 500 bytes and lose 26 cycles - I don't blame you. :)
		;Only usable with splitchans or split4 enabled.
;;    ---  non time opti flags  ---
oscillo	=0	;approx pointer to and count of samples heard during this frame
quietstart=1	;avoid the very first click in some modules
clraudxdat=0	;enable smoother start of quiet sounds. doesn't affect max.
use1Fx=1
jump=1
channels=4
CIA=0
asmone=1
system=1
opt020=0

	include "p6108/p6108-play.s"
