#ifndef TOOLLIB_STDIOCB_H
#define TOOLLIB_STDIOCB_H

/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: stdiocb.h 12561 2001-10-30 20:02:33Z chodorowski $
*/

#include <stdio.h>
#ifndef TOOLLIB_TOOLLIB_H
#   include <toollib/toollib.h>
#endif
#ifndef TOOLLIB_MYSTREAM_H
#   include <toollib/mystream.h>
#endif

typedef struct
{
    MyStream stream;

    FILE * in;
    FILE * out;
    int closein, closeout;
}
StdioStream;

extern StdioStream * StdStr_New     PARAMS ((const char * path, const char * mode));
extern void	     StdStr_Delete  PARAMS ((StdioStream *));

#endif /* TOOLLIB_STDIOCB_H */
