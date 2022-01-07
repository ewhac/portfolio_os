#ifndef __ANIMSAMPLE_H
#define __ANIMSAMPLE_H

#pragma force_top_level
#pragma include_only_once


/******************************************************************************
**
**  $Id: animsample.h,v 1.3 1994/10/27 21:30:32 vertex Exp $
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

#include "animerror.h"

#define VERSION			"2.0"
#define MOVE_DELTA		2

#define CONTROL_ALL		( ControlUp | ControlDown | ControlLeft | ControlRight | ControlA | ControlB )

Item		gVramIOReq = -1, gVblIOReq = -1;
frac16		gFrameIncr, gMoveIncr;
int32		gCorner = 0;
bool		gMoveCorners = false;
Point		gP[4];
Item		gAnimErrorItem = -1;


	/* local function prototypes */

static bool HandleButton ( uint32 button, CCB *ccb );
static int32 Initialize ( ScreenContext *sc, int32 nScreens );
static void Usage ( void );

#endif /* __ANIMSAMPLE_H */
