#ifndef _SYS_PARAM_H_
#define _SYS_PARAM_H_
/*
    Copyright � 1995-2002, The AROS Development Team. All rights reserved.
    $Id: param.h 19609 2003-09-04 10:21:05Z iaint $

    sys/param.h header file.

    Derived from FreeBSD since it is a BSD header, and SUSv2 doesn't
    mention it at all.

    Many of these things are Unix kernel or just plain BSD specific, and as
    such have been left out.
*/

#include <sys/types.h>

/* Apparently we look a bit like a BSD system. */
#define	BSD	199506L
#define BSD4_3	1
#define BSD4_4	1

#define MAXCOMLEN	19	    /* max command name remembered */
#define MAXINTERP	32	    /* max interpreter file name length */
#define MAXLOGNAME	17	    /* max login name length */
#define NGROUPS		16	    /* max number groups */
#define NOFILE		64	    /* max open files per process */
#define MAXHOSTNAMELEN	256	    /* max hostname size */

/* Others:
    MAXUPRC, NCARGS, NOGROUP, SPECNAMELEN
*/

/* From <sys/syslimits.h> */
#define NAME_MAX	32	    /* max bytes in a file name */
#ifndef PATH_MAX
#   define PATH_MAX	4095	    /* max bytes in a pathname */
#endif
#define IOV_MAX		1024	    /* max elements in i/o vector */
#define LINE_MAX	2048	    /* max bytes in an input line */
#define MAXPATHLEN	PATH_MAX    /* max path after symlink deref */
#define MAXSYMLINKS	32	    /* max no of symlinks */

/* Others:
    ARG_MAX, CHILD_MAX, LINK_MAX, MAX_CANON, MAX_INPUT,
    PIPE_BUF, COLL_WEIGHTS_MAX, EXPR_NEST_MAX, RE_DUP_MAX

    For bc(1):
	BC_BASE_MAX, BC_DIM_MAX, BC_SCALE_MAX, BC_STRING_MAX
*/

/* From <machine/param.h>:

    Most of these have a problem in that we have no useful way of
    defining them. Although, since most of these are too Unix specific
    for most well behaved AROS software, I will leave them undefined until
    somebody really needs them.

    MACHINE, MACHINE_ARCH, MAXCPU,

    PAGE_SHIFT, PAGE_SIZE, PAGE_MASK, NPTEPG, NPDEPG, PDRSHIFT,
    NBPDR, PDRMASK,

    DEV_BSHIFT, DEV_BSIZE,

    BLKDEV_IOSIZE, DFLTPHYS, MAXPHYS, MAXDUMPPGS

    IOPAGES, KSTACK_PAGES, UAREA_PAGES, KSTACK_GUARD

    MBSIZE, MCLSHIFT, MCLBYTES

    ctob(), btoc(), trunc_page(), round_page(), atop(), ptoa(),
    btop(), ptob(), pgtok()
*/

/* BSD typically includes <machine/limits.h> here, which is <limits.h> */

/* Back to <sys/param.h> */
#define NBPW	sizeof (int)	/* number of bytes per word (integer) */
#define CMASK	022		/* default file mask: S_IWGRP|S_OWOTH */
#define NODEV	(dev_t)(-1)	/* non-existent device */

/* Others:
    PRIMASK, PCATCH, PDROP, NZERO, CBLOCK, CBQSIZE, CBSIZE, CROUND
    MAXBSIZE, BKVASIZE, BKVAMASK, MAXFRAG,

    setbit(), clrbit(), isset(), isclr(),
    howmany(), rounddown(), roundup(), roundup2(), powerof2()

    <sys/param.h> unconditionally defines MIN(), MAX().
*/
#define MIN(a,b)    (((a)<(b))?(a):(b))
#define MAX(a,b)    (((a)>(b))?(a):(b))

/* Others:
    MINBUCKET, MAXALLOCSAVE, FSHIFT, FSCALE, dbtoc(), ctodb()
*/

#endif /* _SYS_PARAM_H_ */
