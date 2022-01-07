
/******************************************************************************
**
**  $Id: ReadFile.c,v 1.7 1994/11/01 03:49:01 vertex Exp $
**
**  Lib3DO routine to load a file (or a portion of it) into a buffer. If you
**  want to load an entire file at once, LoadFile() is MUCH faster.
**
******************************************************************************/


#include "parse3do.h"
#include "filestream.h"
#include "filestreamfunctions.h"


int32 ReadFile(char *filename, int32 size, int32 *buffer, int32 offset)
{
	int32 retval;
	Stream *fs;

	fs = OpenDiskStream(filename, 0);
	if ( fs == NULL)
		return (-1);

	if (offset == 0) {
		retval = 0;
	} else {
		retval = SeekDiskStream(fs, offset, SEEK_SET);
	}

	if (retval >= 0)
	    retval = ReadDiskStream(fs, (char *)buffer, size);

	CloseDiskStream(fs);

	return (int)retval;
}
