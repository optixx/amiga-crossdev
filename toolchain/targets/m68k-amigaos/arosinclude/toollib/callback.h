#ifndef TOOLLIB_CALLBACK_H
#define TOOLLIB_CALLBACK_H

/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: callback.h 12561 2001-10-30 20:02:33Z chodorowski $
*/

typedef void * CBD;
typedef int (*CB) (void * obj, int, CBD);

#define CallCB(cb,obj,cmd,data)     ((*(cb))(obj,cmd,data))

#endif /* TOOLLIB_CALLBACK_H */
