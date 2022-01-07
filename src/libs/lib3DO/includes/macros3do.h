#ifndef __MACROS3DO_H
#define __MACROS3DO_H

#pragma force_top_level
#pragma include_only_once


/******************************************************************************
**
**  $Id: macros3do.h,v 1.3 1994/10/05 17:34:41 vertex Exp $
**
**  Lib3DO common utility macros.
**
**  AddToPtr() adds a byte offset to any type of pointer.  It casts its args
**  such that any datatype will work for either arg.
**
**  ArrayElements() evaluates to the number of elements the array was defined
**  with.  It works only for array types.
**
******************************************************************************/


#ifndef AddToPtr
  #define AddToPtr(ptr, val) ((void*)((((char *)(ptr)) + (long)(val))))
#endif

#ifndef ArrayElements
  #define ArrayElements(a)	(sizeof(a) / sizeof((a)[0]))
#endif

#endif /* __MACROS3DO_H */
