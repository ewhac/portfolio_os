
/******************************************************************************
**
**  $Id: CenterRectf16.c,v 1.5 1994/10/05 17:50:25 vertex Exp $
**
**  Lib3DO routine to center a frac16 rect within another rect.
**
**  This function takes frac16 inputs and returns an int32 quad result.
**
******************************************************************************/


#include "utils3do.h"

void CenterRectf16( Point *q, Rectf16 *rect, Rectf16 *frame)
{
	frac16	xmid, ymid, ydiff, xdiff;
	frac16	rem;

	xmid = DivRemSF16(&rem, frame->rectf16_XRight, Convert32_F16(2));
	ymid = DivRemSF16(&rem, frame->rectf16_YBottom, Convert32_F16(2));

	ydiff = rect->rectf16_YBottom >> 1 ;
	xdiff = rect->rectf16_XRight>> 1;

	q[0].pt_X = ((xmid - xdiff)+0x8000)>>16;
	q[0].pt_Y = ((ymid - ydiff)+0x8000)>>16;
	q[1].pt_X = ((xmid + xdiff)+0x8000)>>16;
	q[1].pt_Y = ((ymid - ydiff)+0x8000)>>16;
	q[2].pt_X = ((xmid + xdiff)+0x8000)>>16;
	q[2].pt_Y = ((ymid + ydiff)+0x8000)>>16;
	q[3].pt_X = ((xmid - xdiff)+0x8000)>>16;
	q[3].pt_Y = ((ymid + ydiff)+0x8000)>>16;
}
