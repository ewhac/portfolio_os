#####################################
##
## Copyright (C) 1995, an unpublished work by The 3DO Company. All rights reserved.
## This material contains confidential information that is the property of The 3DO Company.
## Any unauthorized duplication, disclosure or use is prohibited.
## $Id: lightgundemo.make,v 1.3 1995/01/19 01:18:46 mattm Exp $
##
#####################################
#   File:       lightgundemo.make
#   Target:     lightgundemo
#   Sources:    lightgun.c lightgundemo.c
#
#   Copyright 3DO Company, 1995
#   All rights reserved.
#

#####################################
#	Symbol definitions
#####################################

App				= lightgundemo
DebugFlag		= 1
SourceDir		= {3DOFolder}Examples:EventBroker:LightGun:
ObjectDir		= :Objects:
Apps_Data		= :Apps_Data:
CC				= armcc
LINK			= armlink
WorkingDisk		=
3DOAutoDup		= -y

#####################################
#	Default compiler options
#####################################

COptions			= -fa -zps0 -za1
CDebugOptions		= -g -d DEBUG={DebugFlag}
LOptions			= -aif -r -b 0x00
LStackSize			= 4096
LDebugOptions		= -d
ModbinDebugOptions	= -debug

#####################################
#	Object files
#####################################

OBJECTS			=	 {ObjectDir}lightgun.c.o {ObjectDir}lightgundemo.c.o "{3DOLibs}"cstartup.o

LIBS			=	 ∂
					"{3DOLibs}Lib3DO.lib" ∂
					"{3DOLibs}audio.lib" ∂
					"{3DOLibs}music.lib" ∂
					"{3DOLibs}operamath.lib" ∂
					"{3DOLibs}filesystem.lib" ∂
					"{3DOLibs}graphics.lib" ∂
					"{3DOLibs}input.lib" ∂
					"{3DOLibs}clib.lib"

#####################################
#	Default build rules
#####################################

All				ƒ	{App}

{ObjectDir}		ƒ	:

.c.o	ƒ	.c
	{CC} -i "{3DOIncludes}" {COptions} {CDebugOptions} -o {TargDir}{Default}.c.o {DepDir}{Default}.c

#####################################
#	Target build rules
#####################################

{App} ƒ {App}.make {OBJECTS}
	{LINK} {LOptions} {LDebugOptions} ∂
		{OBJECTS} ∂
		{LIBS} ∂
		-o "{WorkingDisk}"{Targ}
	SetFile "{WorkingDisk}"{Targ} -c 'EaDJ' -t 'PROJ'
	modbin "{WorkingDisk}"{Targ} -stack {LStackSize} {ModbinDebugOptions}
	stripaif "{WorkingDisk}"{Targ} -o {Targ} -s {Targ}.sym
	move {3DOAutodup} {Targ} "{Apps_Data}"
	move {3DOAutodup} {Targ}.sym "{Apps_Data}"

#####################################
#	Additional Target Dependencies
#####################################

{ObjectDir}lightgun.c.o			ƒ	{App}.make
{ObjectDir}lightgundemo.c.o			ƒ	{App}.make

