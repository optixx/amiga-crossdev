



//how to access asm functions from c


extern __reg("d0") short TestAsmFuncFromC(  __reg("d2") short testvariable);


short* testCVarFromAsm=(short*)0xdff180;

__reg("d0") short TestCFuncFromAsm( __reg("d0") short testvar, __reg("a0") short *bgcolorptr)
{
	*bgcolorptr=TestAsmFuncFromC(0xf00)+testvar;
	return 0xf0f;
}

