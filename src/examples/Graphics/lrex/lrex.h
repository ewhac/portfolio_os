#ifndef __LREX_H
#define __LREX_H

#pragma force_top_level
#pragma include_only_once


/******************************************************************************
**
**  $Id: lrex.h,v 1.3 1994/10/27 21:05:22 vertex Exp $
**
******************************************************************************/

#include "debug3do.h"

#include "graphics.h"
#include "event.h"
#include "umemory.h"
#include "string.h"
#include "displayutils.h"
#include "utils3do.h"

#include "controlpad.h"

#include "lrexerror.h"

#define VERSION			"2.0"
#define MOVE_DELTA		2

#define CONTROL_ALL		( ControlUp | ControlDown | ControlLeft | ControlRight | ControlA | ControlB )

Item		gVramIOReq = -1, gVblIOReq = -1;
frac16		gFrameIncr, gMoveIncr;
int32		gCorner = 0;
bool		gMoveCorners = false;
Point		gP[4];
Item		gLREXErrorItem = -1;


	/* local function prototypes */

static void SetLRForm ( ScreenContext *sc, CCB *lrccb );
static bool HandleButton ( uint32 button, CCB *ccb );
static int32 Initialize ( ScreenContext *sc, int32 nScreens );
static void Usage ( void );

#endif /* _LREX_H */
