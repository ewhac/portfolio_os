
###############################################################################
##
##  Copyright (C) 1995, an unpublished work by The 3DO Company. All rights reserved.
##  This material contains confidential information that is the property of The 3DO Company.
##  Any unauthorized duplication, disclosure or use is prohibited.
##
###############################################################################
#
#   File:       Audio.make
#   Target:     Examples:Audio folder
#   Created:    Friday, November 18, 1994 4:19:14 PM
#
#	Description:	Makes the contents of the Audio folder and all its subdirectories.
#
#		Change History (most recent first):
#
#		01.27.95	Modified to support MPW's pre-3.4 skanky Make utility. jwb
#   	12.09.94	Initial implementation.	jwb

#####################################
#	Symbol definitions
#####################################

App				= Audio
DebugFlag		= 1

ObjectDir		= :Objects
TempDir			= :

MainDir					 = :
Advanced_Sound_PlayerDir = :Advanced_Sound_Player
Coal_RiverDir			 = :Coal_River
DrumBoxDir				 = :DrumBox
JugglerDir				 = :Juggler

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

OBJECTS			=	 {ObjectDir}:beep.c.o ∂
					 {ObjectDir}:capture_audio.c.o ∂
					 {ObjectDir}:minmax_audio.c.o ∂
					 {ObjectDir}:playmf.c.o ∂
					 {ObjectDir}:playsample.c.o ∂
					 {ObjectDir}:playsoundfile.c.o ∂
					 {ObjectDir}:simple_envelope.c.o ∂
					 {ObjectDir}:spoolsoundfile.c.o ∂
					 {ObjectDir}:ta_attach.c.o ∂
					 {ObjectDir}:ta_customdelay.c.o ∂
					 {ObjectDir}:ta_envelope.c.o ∂
					 {ObjectDir}:ta_pitchnotes.c.o ∂
					 {ObjectDir}:ta_spool.c.o ∂
					 {ObjectDir}:ta_sweeps.c.o ∂
					 {ObjectDir}:ta_timer.c.o ∂
					 {ObjectDir}:ta_tuning.c.o ∂
					 {ObjectDir}:ta_tweakknobs.c.o ∂
					 {ObjectDir}:tsc_soundfx.c.o ∂

# OBJECTS			=	 {ObjectDir}:beep.c.o 	
				 
ADVANCED_SOUND_PLAYER_OBJECTS	=	∂
					{Advanced_Sound_PlayerDir}{ObjectDir}:tsp_algorithmic.c.o ∂
					{Advanced_Sound_PlayerDir}{ObjectDir}:tsp_rooms.c.o ∂
					{Advanced_Sound_PlayerDir}{ObjectDir}:tsp_spoolsoundfile.c.o ∂
					{Advanced_Sound_PlayerDir}{ObjectDir}:tsp_switcher.c.o ∂
										
COAL_RIVER_OBJECTS	=	∂
					{Coal_RiverDir}{ObjectDir}:CoalRiver.c.o
					

DRUMBOX_OBJECTS		= 	∂
					{DrumBoxDir}{ObjectDir}:drumbox.c.o
					

JUGGLER_OBJECTS		= 	∂
					{JugglerDir}{ObjectDir}:tj_canon.c.o ∂
					{JugglerDir}{ObjectDir}:tj_multi.c.o ∂
					{JugglerDir}{ObjectDir}:tj_simple.c.o
					
LIBS			=	"{3DOLibs}lib3DO.lib"		∂
					"{3DOLibs}graphics.lib"		∂
					"{3DOLibs}music.lib"		∂
					"{3DOLibs}audio.lib"		∂
					"{3DOLibs}operamath.lib"	∂
					"{3DOLibs}filesystem.lib"		∂
					"{3DOLibs}input.lib"		∂
					"{3DOLibs}clib.lib"		∂
					"{3DOLibs}swi.lib"		∂
					"{3DOLibs}cstartup.o" 
#					"{3DOLibs}copyright.o" ∂
#					"{3DOLibs}exampleslib.lib" ∂
#					"{3DOLibs}compression.lib" ∂
#					"{3DOLibs}memdebug.lib" ∂

									

#####################################
#	Default build rules
#####################################

All				ƒ	{App}


.c.o	ƒ	.c		
	{CC} -i "{3DOIncludes}" {COptions} {CDebugOptions} -o {TargDir}{Default}.c.o {DepDir}{Default}.c
	set AudioLinkOK 1
	# The ExecutableDir business here gets around an MPW 3.3 and earlier make bug
	set ExecutableDir "{DepDir}Apps_Data"
	if {ExecutableDir} == "Apps_Data"
		set ExecutableDir ":Apps_Data"
	end
	{LINK} {LOptions} {LDebugOptions} ∂
		{TargDir}{Default}.c.o ∂
		{LIBS} ∂
		-o {Default}.nostrip || (delete {TargDir}{Default}.c.o; set AudioLinkOK 0)
	if {AudioLinkOK} == 1
		SetFile {TempDir}{Default}.nostrip -c 'EaDJ' -t PROJ
		modbin {TempDir}{Default}.nostrip -stack {LStackSize} {ModbinDebugOptions}	
		if "`Exists {ExecutableDir}:{Default}`"
			delete {ExecutableDir}:{Default}
		end	
		if "`Exists {TargDir}{Default}.sym`"
			delete {TargDir}{Default}.sym
		end	
		stripaif {TempDir}{Default}.nostrip -o {ExecutableDir}:{Default} -s {TargDir}{Default}.sym
		delete {TempDir}{Default}.nostrip
	end

###########################################
# Directory and subdirectory dependencies
###########################################

{ObjectDir}:									ƒ	{MainDir}

{Advanced_Sound_PlayerDir}{ObjectDir}:			ƒ	{Advanced_Sound_PlayerDir}:

{Coal_RiverDir}{ObjectDir}:						ƒ	{Coal_RiverDir}:

{DrumBoxDir}{ObjectDir}:						ƒ	{DrumBoxDir}:

{JugglerDir}{ObjectDir}:						ƒ	{JugglerDir}:

{App} ƒ {App}.make {OBJECTS} ∂
			{ADVANCED_SOUND_PLAYER_OBJECTS} ∂
			{COAL_RIVER_OBJECTS} ∂
			{DRUMBOX_OBJECTS} ∂
			{JUGGLER_OBJECTS} 
	echo 'Make of audio examples completed.'
	beep 2C,15 1G,5 1Gb,5 1G,5 1Ab,15 1G,30 1B,15 2C,15 
