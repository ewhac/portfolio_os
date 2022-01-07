#ifndef __BS_JOYSTICK_H
#define __BS_JOYSTICK_H

/******************************************************************************
**
**  $Id: bs_joystick.h,v 1.2 1994/11/22 00:03:41 vertex Exp $
**
******************************************************************************/

typedef struct {
    /* what we just got from the event broker */
	StickEventData raw;

	/* what we got last time (for filtering, etc) */
	StickEventData lastraw;

	/* the current filtered/debounced joystick data */
	StickEventData filtered;

	/* the filtered/debounced data from last time */
	StickEventData lastfilt;

	/* calibration data (min&max values for each axis) */
	short minX,minY,minZ;
	short maxX,maxY,maxZ;

	/* daisy chain info */
	short daisyNum,stickNum;
} BS_StickData;

/* clear out the struct */
#define BS_InitStickData(a) memset(a,0,sizeof(BS_StickData))

/* access to the StickData pointers */
#define BS_GetStickRaw(a) (&((a)->raw))
#define BS_GetStickLastRaw(a) (&((a)->lastraw))
#define BS_GetStickFiltered(a)(&((a)->filtered))
#define BS_GetStickLast(a) (&((a)->lastfilt))

/* get the current, filtered values */
#define BS_GetStickX(sd) (((sd)->filtered).stk_HorizPosition)
#define BS_GetStickY(sd) (((sd)->filtered).stk_VertPosition)
#define BS_GetStickZ(sd) (((sd)->filtered).stk_DepthPosition)
#define BS_GetStickButtons(sd) (((sd)->filtered).stk_ButtonBits)

/* set the current, filtered values */
#define BS_SetStickX(sd,v) ((((sd)->filtered).stk_HorizPosition)=(v))
#define BS_SetStickY(sd,v) ((((sd)->filtered).stk_VertPosition)=(v))
#define BS_SetStickZ(sd,v) ((((sd)->filtered).stk_DepthPosition)=(v))
#define BS_SetStickButtons(sd,v) ((((sd)->filtered).stk_ButtonBits)=(v))

/* get the filtered values from last time */
#define BS_GetStickLastX(sd) (((sd)->lastfilt).stk_HorizPosition)
#define BS_GetStickLastY(sd) (((sd)->lastfilt).stk_VertPosition)
#define BS_GetStickLastZ(sd) (((sd)->lastfilt).stk_DepthPosition)
#define BS_GetStickLastButtons(sd) (((sd)->lastfilt).stk_ButtonBits)

/* set the filtered history elements */
#define BS_SetStickLastX(sd,v) ((((sd)->lastfilt).stk_HorizPosition)=(v))
#define BS_SetStickLastY(sd,v) ((((sd)->lastfilt).stk_VertPosition)=(v))
#define BS_SetStickLastZ(sd,v) ((((sd)->lastfilt).stk_DepthPosition)=(v))
#define BS_SetStickLastButtons(sd,v) ((((sd)->lastfilt).stk_ButtonBits)=(v))

/* get the current raw data */
#define BS_GetStickRawX(sd) (((sd)->raw).stk_HorizPosition)
#define BS_GetStickRawY(sd) (((sd)->raw).stk_VertPosition)
#define BS_GetStickRawZ(sd) (((sd)->raw).stk_DepthPosition)
#define BS_GetStickRawButtons(sd) (((sd)->raw).stk_ButtonBits)

/* set the current raw data (unused, but here for form's sake) */
#define BS_SetStickRawX(sd,v) ((((sd)->raw).stk_HorizPosition)=(v))
#define BS_SetStickRawY(sd,v) ((((sd)->raw).stk_VertPosition)=(v))
#define BS_SetStickRawZ(sd,v) ((((sd)->raw).stk_DepthPosition)=(v))
#define BS_SetStickRawButtons(sd,v) ((((sd)->raw).stk_ButtonBits)=(v))

/* get the raw data from last time */
#define BS_GetStickLastRawX(sd) (((sd)->lastraw).stk_HorizPosition)
#define BS_GetStickLastRawY(sd) (((sd)->lastraw).stk_VertPosition)
#define BS_GetStickLastRawZ(sd) (((sd)->lastraw).stk_DepthPosition)
#define BS_GetStickLastRawButtons(sd) (((sd)->lastraw).stk_ButtonBits)

/* set the raw history */
#define BS_SetStickLastRawX(sd,v) ((((sd)->lastraw).stk_HorizPosition)=(v))
#define BS_SetStickLastRawY(sd,v) ((((sd)->lastraw).stk_VertPosition)=(v))
#define BS_SetStickLastRawZ(sd,v) ((((sd)->lastraw).stk_DepthPosition)=(v))
#define BS_SetStickLastRawButtons(sd,v) ((((sd)->lastraw).stk_ButtonBits)=(v))

/* get the calibration values */
#define BS_GetStickMinX(sd) ((sd)->minX)
#define BS_GetStickMinY(sd) ((sd)->minY)
#define BS_GetStickMinZ(sd) ((sd)->minZ)
#define BS_GetStickMaxX(sd) ((sd)->maxX)
#define BS_GetStickMaxY(sd) ((sd)->maxY)
#define BS_GetStickMaxZ(sd) ((sd)->maxZ)

/* set the calibration values */
#define BS_SetStickMinX(sd,v) (((sd)->minX)=(v))
#define BS_SetStickMinY(sd,v) (((sd)->minY)=(v))
#define BS_SetStickMinZ(sd,v) (((sd)->minZ)=(v))
#define BS_SetStickMaxX(sd,v) (((sd)->maxX)=(v))
#define BS_SetStickMaxY(sd,v) (((sd)->maxY)=(v))
#define BS_SetStickMaxZ(sd,v) (((sd)->maxZ)=(v))

/* get the stick's daisy and stick numbers */
#define BS_GetStickDaisyNum(sd) ((sd)->daisyNum)
#define BS_GetStickNum(sd) ((sd)->stickNum)

/* set the stick's daisy and stick numbers */
#define BS_SetStickDaisyNum(sd,v) (((sd)->daisyNum)=(v))
#define BS_SetStickNum(sd,v) (((sd)->stickNum)=(v))

/* copy the current raw data to the last (history) data */
#define BS_SetStickThisLastRaw(a) \
	BS_SetStickLastRawX(a,BS_GetStickRawX(a)),\
	BS_SetStickLastRawY(a,BS_GetStickRawY(a)),\
	BS_SetStickLastRawZ(a,BS_GetStickRawZ(a)),\
	BS_SetStickLastRawButtons(a,BS_GetStickRawButtons(a))

/* copy the current filtered to the last (history) data */
#define BS_SetStickThisLast(a) \
	BS_SetStickLastX(a,BS_GetStickX(a)),\
	BS_SetStickLastY(a,BS_GetStickY(a)),\
	BS_SetStickLastZ(a,BS_GetStickZ(a)),\
	BS_SetStickLastButtons(a,BS_GetStickButtons(a))


/* prototype for our filtering/debouncing routine */
extern int BS_ProcessStickData(BS_StickData *aStk,
						uint32 deBounceBits,int reCal);


#endif /* __BS_JOYSTICK_H */
