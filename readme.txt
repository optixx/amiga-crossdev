The Super Simple WinUAE Tool Chain For Amiga Demo Programmers, Version 4, released February 15, 2012
Put together by XXXXX


GOALS FOR TSSWUAETCFADP
1. Gather everything you need to start programming on the amiga into a single place
2. Set up a one-click-build, one-click-run system for amiga development in Windows, where you can see code running on screen in under 15 seconds
2. Provide a sample with c and assembler working seamlessly together
3. Include ship-quality system-friendly startup code for demos that works with all Amiga platforms.
4. Include a ship-quality music player 
5. Get it all to build and run from within Visual Studio 2010
6. Gather useful documents in a pc-friendly (and Kindle-friendly) format
7. (new) Make it easy to run your favorite flavor of protracker

BASIC INSTRUCTIONS
1. unpack all files into a folder
2. in command line, run build.bat to build dh0\mydemo.exe
3. run RunAros.bat to see the amiga automatically run the freshly built file, mydemo.exe, using the AROS rom on an A4000/40 (this rom is a replacement for Kickstart 3.1)
3b. if the run*.bat files doesn't boot the newly built file, and you may have used WinUAE before, you may have old info in your registry. In that case, try to run DestroyOldUAESettings.bat, and try the run*.bat files again

4. You may want to get Kickstart 1.3, 2.04 and 3.0 copied into the root of the WinUAE folder. You can always buy the Amiga Forever Plus DVD from http://www.amigaforever.com/, and copy the contents of the \Amiga Files\Shared\rom folder (remember to also copy rom.key). Or you can go hunting for the kick13.rom, kick204.rom and kick30.rom at your own peril :-)
5. This enables you to run runa500.bat, runa4000_40.bat, runa1200.bat, or runa500plus.bat to see the amiga automatically run the demo on any file, or RunAll.bat to see the demo run simultaneously in 5 different configs


MUSIC INSTRUCTIONS:
1. run startProtracker23d.bat, startProtracker315.bat, or startProtracker362.bat to start tracking

2. to convert samples to protracker-friendly raw format
	a. just put a wav-file (xxx.wav) in dh0\wavsamples
	b. run ConvertWavToRaw.bat xxx.wav
	c. you now have xxx.raw in dh0\rawsamples

3. to change the music in the sample,
	a. run startp61converter.bat
	b. press cancel on the env: requester
	c. pick a protracker mod-file, and convert it to p61 format
	d. put the new filename into main.asm instead of the old one
	e. build and run

CODE INSTRUCTIONS
1. If you have visual studio 2010, just 
	a. start by running StartVisualStudio.bat, 
	b. you can now build and run (but not debug)

2. open source\main.asm and start coding!

3. to delete temporary files (and final built file), run cleanup.bat

4. to debug, press shift+f12 inside WinUAE

5. you may want to download notepad++ or something else as notepad doesn't do well with unix format text files

6. download  "Amiga Hardware Reference Manual" - maybe look in http://amiga-manuals.xiik.net/ebooks? - and some manual for the 68000


STANDING ON THE SHOULDERS OF GIANTS. This was built using:
	 vasm/vbcc/vlink by Volker Barthelmann.  Repackaged with permission - this is a stock recompilation without changes. For vasm/vbcc/vlink licensing agreement please see manuals\vbcc.pdf, manuals\vasm.pdf, and manuals\vlink.pdf	
	This came from kusma's amiga-dev toolchain (precompiled versions of compiler, assembler, linker etc.)
		config file was changed
	startup code and howtocode7 documents from from cj of Share and Enjoy
		I fixed pal/ntsc check bug 
		I fixed crash on exit in <v39
		I merged all the howtocode7 documents into a single guide-file, so I could generate a PDF
	The player 6108 by Sahara surfers and lots of other people
		I fixed case sensitivity issues
	notes from krabob/rload on ada.untergrund.net about mixing c and asm
	piru's input handler
	winuae
	winguide to generate pdf files
	Protrackers by a lot of people
	SoundExchange	


KNOWN ISSUES/QUESTIONS
none

TODO
	 - add in avail and avail flush calls to check for memleaks

CHANGE LOG
V4
	toolchain changes
	- added adfview archive to toolchain folder - run this to browse adf files
	- got redistribution permissions from Volker Barthelmann
	- replaced NDK with alternative open source headers (but you can still put NDK back if you want - search for HAS_NDK
	- removed posix and netinclude libs and includes
	- added support for an exit string - this is printed to shell on exit
V3
	toolchain changes
	- added support for Aros rom - so no need to get regular kickstart files
	- added command line parameter to boot disks (runa500.bat [relativePathToFloppyImage])
	- created runall.bat that boots all configs simultaneously
	- added windows caption to winuae configs

	code changes
	- fixed broken disablecache
	- fixed borked workbench launch code - doh!
	- changed p61 config to be system friendly - doh again (caused crash on at least workbench 2.04)

V2
	toolchain changes
	- added protrackers including startup batch files
	- created batch file to start p61 converter
	- created a4000 batch file and config
	- updated run batch files to work both with amigaforever roms and other roms
	- added Visual Studio 2010 .user file, so debugger commands are already configured
	- minor change in setpaths to remove double backslash
	- updated notes on where to legally get the kickstart roms
	- moved files out of root folder where possible
	- create DestroyOldUAESettings.bat to fix problems with old users
	- added wav to raw conversion batch

	code changes
	- moved versionstring to top of file
	- added flag to shut off multitasking (DISABLE_MULTITASKING)
	- disable_multitasking safely blocks blitter access during execution
	- when detecting NTSC, code just quits on startup, because that's usually what you want when making demos :-)
	- added flag to shut off cache (DISABLE_CACHE)
	- moved music player into a system friendly vblank interrupt, 
	- restructured startup/main calling pattern to make it more readable and less error-prone
	- using Piru's input handler to "eat" input from the system, and to block requesters from popping up

V1 Initial Release
