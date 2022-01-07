#ifndef __H_DIRECTORYFUNCTIONS
#define __H_DIRECTORYFUNCTIONS

#pragma force_top_level
#pragma include_only_once


/******************************************************************************
**
**  $Id: directoryfunctions.h,v 1.6 1994/09/10 01:36:15 peabody Exp $
**
**  Function prototypes for the userland interface to the directory walker.
**
******************************************************************************/


#ifndef __TYPES_H
#include "types.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */

Directory *OpenDirectoryItem(Item openFileItem);
Directory *OpenDirectoryPath(char *thePath);
int32 ReadDirectory (Directory *dir, DirectoryEntry *de);
void CloseDirectory (Directory *dir);

#ifdef __cplusplus
}
#endif /* __cplusplus */


/*****************************************************************************/

#endif /* __H_DIRECTORYFUNCTIONS */
