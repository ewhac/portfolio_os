#####################################
##
## Copyright (C) 1995, an unpublished work by The 3DO Company. All rights reserved.
## This material contains confidential information that is the property of The 3DO Company.
## Any unauthorized duplication, disclosure or use is prohibited.
## $Id: menu.make,v 1.7 1995/01/19 02:47:23 mattm Exp $
##
#####################################
#   File:       menu.make
#   Target:     menu
#   Sources:    menu.c
#
#   Copyright (c) 1995, The 3DO Company
#   All rights reserved.
#

#####################################
#	Symbol definitions
#####################################

App				= menu
DebugFlag		= 1
SourceDir		= {3DOFolder}Examples:Miscellaneous:Menu:
ObjectDir		= :Objects:
ExecutableDir	= {SourceDir}Apps_Data:
CC				= armcc
LINK			= armlink
WorkingDisk		=
TempDir			= :

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

OBJECTS			=	 {ObjectDir}menu.c.o 		∂
					 {ObjectDir}gfxutils.c.o	∂
					 {ObjectDir}programlist.c.o	∂
					 "{3DOLibs}"cstartup.o

LIBS			=	 ∂
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
	{LINK} {LOptions} ∂
		{OBJECTS} ∂
		{LIBS} ∂
		-o "{WorkingDisk}"{Targ}.nostrip
	SetFile "{WorkingDisk}"{Targ}.nostrip -c 'EaDJ' -t 'PROJ'
	modbin "{WorkingDisk}"{Targ}.nostrip -stack {LStackSize} {ModbinDebugOptions}
	stripaif "{WorkingDisk}"{Targ}.nostrip -o {ExecutableDir}{Targ} -s {ExecutableDir}{Targ}.sym
	delete "{WorkingDisk}"{Targ}.nostrip

#####################################
#	Additional Target Dependencies
#####################################

{ObjectDir}menu.c.o			ƒ	{App}.make
{ObjectDir}gfxutils.c.o		ƒ	{App}.make
{ObjectDir}programlist.c.o	ƒ	{App}.make
