# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=update - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to update - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "iterator - Win32 Debug" && "$(CFG)" != "update - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Registry.mak" CFG="update - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "iterator - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "update - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "update - Win32 Debug"
RSC=rc.exe
CPP=cl.exe

!IF  "$(CFG)" == "iterator - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "iterator\Debug"
# PROP BASE Intermediate_Dir "iterator\Debug"
# PROP BASE Target_Dir "iterator"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "debug"
# PROP Target_Dir "iterator"
OUTDIR=.\.
INTDIR=.\debug

ALL : "$(OUTDIR)\iterator.exe"

CLEAN : 
	-@erase "$(INTDIR)\test_registry_iterator.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\iterator.exe"
	-@erase "$(OUTDIR)\iterator.ilk"
	-@erase "$(OUTDIR)\iterator.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\STL" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
CPP_OBJS=.\debug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/iterator.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 aced.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=aced.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib\
 odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/iterator.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/iterator.exe" 
LINK32_OBJS= \
	"$(INTDIR)\test_registry_iterator.obj"

"$(OUTDIR)\iterator.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "update - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "update\Debug"
# PROP BASE Intermediate_Dir "update\Debug"
# PROP BASE Target_Dir "update"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "debug"
# PROP Target_Dir "update"
OUTDIR=.\.
INTDIR=.\debug

ALL : "$(OUTDIR)\update.exe"

CLEAN : 
	-@erase "$(INTDIR)\test_registry_update.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\update.exe"
	-@erase "$(OUTDIR)\update.ilk"
	-@erase "$(OUTDIR)\update.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\STL" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
CPP_OBJS=.\debug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/update.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 aced.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=aced.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib\
 odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/update.pdb" /debug /machine:I386 /out:"$(OUTDIR)/update.exe" 
LINK32_OBJS= \
	"$(INTDIR)\test_registry_update.obj"

"$(OUTDIR)\update.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\STL" /D "WIN32" /D "_DEBUG"\
 /D "_CONSOLE" /Fp"$(INTDIR)/iterator.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/"\
 /c 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "iterator - Win32 Debug"
################################################################################
# Begin Source File

SOURCE=.\test_registry_iterator.cpp
DEP_CPP_TEST_=\
	"..\..\STL\algobase.h"\
	"..\..\STL\bool.h"\
	"..\..\STL\bstring.h"\
	"..\..\STL\defalloc.h"\
	"..\..\STL\function.h"\
	"..\..\STL\iterator.h"\
	"..\..\STL\pair.h"\
	"..\..\STL\vector.h"\
	{$(INCLUDE)}"\ace\ACE.h"\
	{$(INCLUDE)}"\ace\ACE.i"\
	{$(INCLUDE)}"\ace\Auto_Ptr.cpp"\
	{$(INCLUDE)}"\ace\Auto_Ptr.h"\
	{$(INCLUDE)}"\ace\Auto_Ptr.i"\
	{$(INCLUDE)}"\ace\config-win32-common.h"\
	{$(INCLUDE)}"\ace\config-win32.h"\
	{$(INCLUDE)}"\ace\config.h"\
	{$(INCLUDE)}"\ace\Log_Msg.h"\
	{$(INCLUDE)}"\ace\Log_Priority.h"\
	{$(INCLUDE)}"\ace\Log_Record.h"\
	{$(INCLUDE)}"\ace\Log_Record.i"\
	{$(INCLUDE)}"\ace\Object_Manager.h"\
	{$(INCLUDE)}"\ace\Object_Manager.i"\
	{$(INCLUDE)}"\ace\OS.h"\
	{$(INCLUDE)}"\ace\OS.i"\
	{$(INCLUDE)}"\ace\Registry.h"\
	{$(INCLUDE)}"\ace\SString.h"\
	{$(INCLUDE)}"\ace\SString.i"\
	{$(INCLUDE)}"\ace\stdcpp.h"\
	{$(INCLUDE)}"\ace\Trace.h"\
	{$(INCLUDE)}"\ace\ws2tcpip.h"\
	

"$(INTDIR)\test_registry_iterator.obj" : $(SOURCE) $(DEP_CPP_TEST_) "$(INTDIR)"


# End Source File
# End Target
################################################################################
# Begin Target

# Name "update - Win32 Debug"
################################################################################
# Begin Source File

SOURCE=.\test_registry_update.cpp
DEP_CPP_TEST_R=\
	"..\..\STL\algobase.h"\
	"..\..\STL\bool.h"\
	"..\..\STL\bstring.h"\
	"..\..\STL\defalloc.h"\
	"..\..\STL\function.h"\
	"..\..\STL\iterator.h"\
	"..\..\STL\pair.h"\
	"..\..\STL\vector.h"\
	{$(INCLUDE)}"\ace\ACE.h"\
	{$(INCLUDE)}"\ace\ACE.i"\
	{$(INCLUDE)}"\ace\Auto_Ptr.cpp"\
	{$(INCLUDE)}"\ace\Auto_Ptr.h"\
	{$(INCLUDE)}"\ace\Auto_Ptr.i"\
	{$(INCLUDE)}"\ace\config-win32-common.h"\
	{$(INCLUDE)}"\ace\config-win32.h"\
	{$(INCLUDE)}"\ace\config.h"\
	{$(INCLUDE)}"\ace\Log_Msg.h"\
	{$(INCLUDE)}"\ace\Log_Priority.h"\
	{$(INCLUDE)}"\ace\Log_Record.h"\
	{$(INCLUDE)}"\ace\Log_Record.i"\
	{$(INCLUDE)}"\ace\Object_Manager.h"\
	{$(INCLUDE)}"\ace\Object_Manager.i"\
	{$(INCLUDE)}"\ace\OS.h"\
	{$(INCLUDE)}"\ace\OS.i"\
	{$(INCLUDE)}"\ace\Registry.h"\
	{$(INCLUDE)}"\ace\SString.h"\
	{$(INCLUDE)}"\ace\SString.i"\
	{$(INCLUDE)}"\ace\stdcpp.h"\
	{$(INCLUDE)}"\ace\Trace.h"\
	{$(INCLUDE)}"\ace\ws2tcpip.h"\
	

"$(INTDIR)\test_registry_update.obj" : $(SOURCE) $(DEP_CPP_TEST_R) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
