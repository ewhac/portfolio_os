
/******************************************************************************
**
**  $Id: GetChunk.c,v 1.5 1994/10/05 18:23:43 vertex Exp $
**
**  Lib3DO routine to help parse 3DO chunky files.
**
**  Returns the next chunk_ID in this file. On exit, chunk_ID contains
**  the chunk_ID found in the chunk pointed to by buffer, the buffer
**  ptr is updated to point to the next chunk and the bufLen param
**  has the number of bytes remaining in the buffer.  Returns NULL when
**  no chunks left in buffer.
**
******************************************************************************/


#include "form3do.h"

char *GetChunk( uint32 *chunk_ID, char **buffer, int32 *bufLen )
{
	char *buf;

	if ( *bufLen > 0 ) {

		buf = *buffer;
		*chunk_ID = ((PixelChunk *)buf)->chunk_ID;

		/* jump to next chunk */

		*bufLen -= ((PixelChunk *)buf)->chunk_size;
		*buffer += ((PixelChunk *)buf)->chunk_size;

		return buf;
	}

	return NULL;
}
