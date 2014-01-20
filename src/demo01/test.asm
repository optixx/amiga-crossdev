	idnt	"test.c"
	opt	0
	opt	NQLPSMRBT
	section	"CODE",code
	public	_TestCFuncFromAsm
	cnop	0,4
_TestCFuncFromAsm
	movem.l	l2,-(a7)
	move.l	a0,a2
	move.w	d0,d3
	move.l	#3840,d2
	jsr	_TestAsmFuncFromC
	move.w	d3,d1
	add.w	d0,d1
	move.w	d1,(a2)
	move.w	#3855,d0
l2	reg	a2/d2/d3
	movem.l	(a7)+,a2/d2/d3
l4	equ	12
	rts
	public	_testCVarFromAsm
	section	"DATA",data
	cnop	0,4
_testCVarFromAsm
	dc.l	14676352
	public	_TestAsmFuncFromC
