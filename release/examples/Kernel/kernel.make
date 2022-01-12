#####################################
##
## Copyright (C) 1995, an unpublished work by The 3DO Company. All rights reserved.
## This material contains confidential information that is the property of The 3DO Company.
## Any unauthorized duplication, disclosure or use is prohibited.
## $Id: kernel.make,v 1.3 1995/01/19 02:10:54 mattm Exp $
##
#####################################
#   File:       kernel.make
#   Target:     allocmem memdebug msgpassing signals timerread timersleep
#   Sources:    allocmem.c memdebug.c msgpassing.c signals.c timerread.c timersleep.c
#
#   Copyright (c) 1995, The 3DO Company
#   All rights reserved.
#

#####################################
#	Symbol definitions
#####################################

App				= Kernel
DebugFlag		= 1

SourceDir		= {3DOFolder}Examples:Kernel:
ObjectDir		= :Objects:
ExecutableDir	= {SourceDir}Apps_Data:
TempDir			= :

CC				= armcc
LINK			= armlink

#####################################
#	Default compiler options
#####################################

COptions			= -fa -zps0 -za1
CDebugOptions		= -g -d DEBUG={DebugFlag}
LOptions			= -aif -r -b 0x00 -workspace 0x10000
LStackSize			= 6000
LDebugOptions		= -d
ModbinDebugOptions	= -debug

#####################################
#	Object files
#####################################

OBJECTS			=	{ObjectDir}allocmem.c.o		∂
					{ObjectDir}memdebug.c.o		∂
					{ObjectDir}msgpassing.c.o	∂
					{ObjectDir}signals.c.o		∂
					{ObjectDir}timerread.c.o	∂
					{ObjectDir}timersleep.c.o
					
LIBS			=	"{3DOLibs}Lib3DO.lib" ∂
					"{3DOLibs}audio.lib" ∂
					"{3DOLibs}music.lib" ∂
					"{3DOLibs}operamath.lib" ∂
					"{3DOLibs}filesystem.lib" ∂
					"{3DOLibs}graphics.lib" ∂
					"{3DOLibs}input.lib" ∂
					"{3DOLibs}memdebug.lib" ∂
					"{3DOLibs}clib.lib"
					
#####################################
#	Default build rules
#####################################

All				ƒ	{App}

{ObjectDir}		ƒ	:

.c.o	ƒ	.c
	{CC} -i "{3DOIncludes}" {COptions} {CDebugOptions} -o {TargDir}{Default}.c.o {DepDir}{Default}.c
	{LINK} {LOptions} {LDebugOptions} ∂
		{TargDir}{Default}.c.o ∂
		"{3DOLibs}"cstartup.o ∂
		{LIBS} ∂
		-o {TempDir}{Default}.nostrip
	SetFile {TempDir}{Default}.nostrip -c 'EaDJ' -t 'PROJ'
	modbin {TempDir}{Default}.nostrip -stack {LStackSize} {ModbinDebugOptions}
	stripaif {TempDir}{Default}.nostrip -o {ExecutableDir}{Default} -s {ExecutableDir}{Default}.sym
	delete {TempDir}{Default}.nostrip

{App} ƒ {App}.make {OBJECTS}
