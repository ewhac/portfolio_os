#####################################
##
## Copyright (C) 1995, an unpublished work by The 3DO Company. All rights reserved.
## This material contains confidential information that is the property of The 3DO Company.
## Any unauthorized duplication, disclosure or use is prohibited.
## $Id: nvram.make,v 1.3 1995/01/19 02:57:31 mattm Exp $
##
#####################################
#   File:       nvram.make
#   Target:     nvram
#   Sources:    nvram.c
#
#   Copyright (c) 1995, The 3DO Company
#   All rights reserved.
#

#####################################
#	Symbol definitions
#####################################

App				= nvram
DebugFlag		= 1
SourceDir		= {3DOFolder}Examples:NVRAM:File_Management:
ObjectDir		= :Objects:
Apps_Data		= :Apps_Data:
CC				= armcc
LINK			= armlink
WorkingDisk		=
3DOAutodup		= -y

#####################################
#	Default compiler options
#####################################

COptions			= -fa -zps0 -za1
CDebugOptions		= -g -d DEBUG={DebugFlag}
LOptions			= -aif -r -b 0x00
nvramtackSize		= 4096
LDebugOptions		= -d
ModbinDebugOptions	= -debug

#####################################
#	Object files
#####################################

OBJECTS			=	 {ObjectDir}nvram.c.o "{3DOLibs}"cstartup.o

LIBS			=	 ∂
					"{3DOLibs}clib.lib" ∂

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
	modbin "{WorkingDisk}"{Targ} -stack {nvramtackSize} {ModbinDebugOptions}
	stripaif "{WorkingDisk}"{Targ} -o {Targ} -s {Targ}.sym
	move {3DOAutodup} {Targ} "{Apps_Data}"
	move {3DOAutodup} {Targ}.sym "{Apps_Data}"

#####################################
#	Additional Target Dependencies
#####################################

{ObjectDir}nvram.c.o			ƒ	{App}.make
