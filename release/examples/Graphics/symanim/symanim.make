#####################################
##
## Copyright (C) 1995, an unpublished work by The 3DO Company. All rights reserved.
## This material contains confidential information that is the property of The 3DO Company.
## Any unauthorized duplication, disclosure or use is prohibited.
## $Id: symanim.make,v 1.5 1995/01/16 19:47:42 gyld Exp $
##
#####################################

#####################################
#		Symbol definitions
#####################################
Application		=	symanim
DebugFlag		=	1
AppsDir			= 	:Apps_Data:
ObjectDir		=	:Objects:
CC				=	armcc
ASM				=	armasm
LINK			=	armlink


#####################################
#	Default compiler options
#####################################
# USE THE FOLLOWING LINE FOR SYMBOLIC DEBUGGING
CDebugOptions	= -g
# USE THE FOLLOWING LINE FOR OPTIMIZED CODE
#CDebugOptions	=

COptions		= {CDebugOptions} -zps0 -za1 -i "{3DOIncludes}" -d DEBUG={DebugFlag}

SOptions		= -bi -g -i "{3DOIncludes}"

# USE THE FOLLOWING LINE FOR SYMBOLIC DEBUGGING
LDebugOptions	= -d		# turn on symbolic information
# USE THE FOLLOWING LINE FOR OPTIMIZED CODE
#LDebugOptions	=			# turn off symbolic information

LOptions		= {LDebugOptions} -aif -r -b 0x00 -workspace 4096

#####################################
#		Object files
#####################################
LIBS			=	"{3DOLibs}Lib3DO.lib"		∂
					"{3DOLibs}operamath.lib"	∂
					"{3DOLibs}graphics.lib"	∂
					"{3DOLibs}filesystem.lib"	∂
					"{3DOLibs}input.lib"		∂
					"{3DOLibs}clib.lib"

# NOTE: Add object files here...
OBJECTS			=	"{ObjectDir}{Application}.c.o"∂
					"{ObjectDir}Sprite.c.o"

#####################################
#	Default build rules
#####################################
All				ƒ	{Application}

{ObjectDir}		ƒ	:

.c.o			ƒ	.c
	{CC} {COptions} -o {TargDir}{Default}.c.o {DepDir}{Default}.c

.s.o			ƒ	.s
	{ASM} {SOptions} -o {TargDir}{Default}.s.o {DepDir}{Default}.s


#####################################
#	Target build rules
#####################################
{Application}		ƒƒ	{Application}.make {LIBS} {OBJECTS}
	{LINK}	{LOptions}					∂
			-o {Application}				∂
			"{3DOLibs}cstartup.o"		∂
			{OBJECTS}					∂
			{LIBS}
	SetFile {Application} -c 'EaDJ' -t 'PROJ'
	modbin {Application} -stack 0x2000 -debug
	stripaif {Application} -o {Application}
	if not `exists "{AppsDir}"`
		newFolder "{AppsDir}"
	end
	move -y {Targ} "{AppsDir}"
	move -y {Targ}.sym "{AppsDir}"

#####################################
#	Include file dependencies
#####################################
#{Application}.c		ƒ	{Application}.h


symanim.c	ƒ Sprite.h
sprite.c ƒ Sprite.h
