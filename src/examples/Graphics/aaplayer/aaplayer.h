#ifndef __AAPLAYER_H
#define __AAPLAYER_H

#pragma force_top_level
#pragma include_only_once


/******************************************************************************
**
**  $Id: aaplayer.h,v 1.4 1994/10/27 19:03:26 vertex Exp $
**
******************************************************************************/


#include "debug3do.h"

#include "graphics.h"
#include "event.h"
#include "umemory.h"
#include "string.h"
#include "displayutils.h"
#include "utils3do.h"
#include "io.h"

#include "controlpad.h"

#include "aaerror.h"

#define VERSION			"2.0"
#define MOVE_DELTA		2

#define CONTROL_ALL		( ControlUp | ControlDown | ControlLeft | ControlRight | ControlA | ControlB )

Item		gVramIOReq = -1, gVblIOReq = -1;
frac16		gFrameIncr, gMoveIncr;
int32		gCorner = 0;
bool		gMoveCorners = false;
Point		gP[4];
Item		gAAErrorItem = -1;
Item		gTimerDevice = -1, gTimerReq = -1;
int32		gFrameRate = 15;



	/* local function prototypes */

static bool HandleButton ( uint32 button, CCB *ccb );
static int32 Initialize ( ScreenContext *sc, int32 nScreens );
static void Usage ( void );
static int32 AdvanceFrame ( IOReq *pIOReq, struct timeval *lastTime );
static int32 GetTime ( IOReq *pIOReq, struct timeval *tv );


#endif /* _AAPLAYER_H */
