#ifndef __H_FILEFUNCTIONS
#define __H_FILEFUNCTIONS

#pragma force_top_level
#pragma include_only_once


/******************************************************************************
**
**  $Id: filefunctions.h,v 1.22 1994/10/21 21:06:16 shawn Exp $
**
**  Function prototypes for the userland interfaces to the File Folio.
**
******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */

#define FILEFOLIOSWI 0x00030000

extern Item  __swi(FILEFOLIOSWI+0) OpenDiskFile(char *path);
extern int32 __swi(FILEFOLIOSWI+1) CloseDiskFile(Item fileItem);
extern Item  __swi(FILEFOLIOSWI+4) MountFileSystem(Item deviceItem,
						   int32 unit,
						   uint32 blockOffset);
extern Item  __swi(FILEFOLIOSWI+5) OpenDiskFileInDir(Item dirItem, char *path);
extern Item  __swi(FILEFOLIOSWI+6) MountMacFileSystem(char *path);
extern Item  __swi(FILEFOLIOSWI+7) ChangeDirectory(char *path);
extern Item  __swi(FILEFOLIOSWI+8) GetDirectory(char *pathBuf, int pathBufLen);
extern Item  __swi(FILEFOLIOSWI+9) CreateFile(char *path);
extern Err   __swi(FILEFOLIOSWI+10) DeleteFile(char *path);
extern Item  __swi(FILEFOLIOSWI+11) CreateAlias(char *aliasPath,
						char *realPath);
#ifndef EXTERNAL_RELEASE
extern int32 __swi(FILEFOLIOSWI+12) LoadOverlay(void *mumble); /* internal */
#endif /* EXTERNAL_RELEASE */
extern Err   __swi(FILEFOLIOSWI+13) DismountFileSystem(char *name);
#ifndef EXTERNAL_RELEASE
extern Err   __swi(FILEFOLIOSWI+14) CreateLink(char *firstPath,
					       char *secondPath, int funci);
#endif /* EXTERNAL_RELEASE */


extern Item                        LoadProgram(char *path);
extern Item                        LoadProgramPrio(char *path, int32 prio);
extern Err                         LoadCode(char *fileName, CodeHandle *code);
extern Err                         UnloadCode(CodeHandle code);
extern int32                       ExecuteAsSubroutine(CodeHandle code,
						       uint32 argc,
						       char **argv);
extern Item                        ExecuteAsThread(CodeHandle code,
						   uint32 argc,
						   char **argv,
						   char *threadName,
						   int32 priority);

#ifndef EXTERNAL_RELEASE
extern void                        InitFileFolioGlue(void);
#endif /* EXTERNAL_RELEASE */
extern void                        OpenFileFolio(void);
extern void                        CloseFileFolio(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */


/*****************************************************************************/


#endif /* __H_FILEFUNCTIONS */
