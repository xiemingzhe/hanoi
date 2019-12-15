# Microsoft Developer Studio Project File - Name="201008202106Ð»Ã÷ÕÜ" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=201008202106Ð»Ã÷ÕÜ - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "201008202106Ð»Ã÷ÕÜ.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "201008202106Ð»Ã÷ÕÜ.mak" CFG="201008202106Ð»Ã÷ÕÜ - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "201008202106Ð»Ã÷ÕÜ - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "201008202106Ð»Ã÷ÕÜ - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "201008202106Ð»Ã÷ÕÜ - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "201008202106Ð»Ã÷ÕÜ - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ws2_32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "201008202106Ð»Ã÷ÕÜ - Win32 Release"
# Name "201008202106Ð»Ã÷ÕÜ - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=".\201008202106Ð»Ã÷ÕÜ.cpp"
# End Source File
# Begin Source File

SOURCE=".\201008202106Ð»Ã÷ÕÜ.rc"
# End Source File
# Begin Source File

SOURCE=".\201008202106Ð»Ã÷ÕÜDoc.cpp"
# End Source File
# Begin Source File

SOURCE=".\201008202106Ð»Ã÷ÕÜView.cpp"
# End Source File
# Begin Source File

SOURCE=.\Choose.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TalkDialog.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=".\201008202106Ð»Ã÷ÕÜ.h"
# End Source File
# Begin Source File

SOURCE=".\201008202106Ð»Ã÷ÕÜDoc.h"
# End Source File
# Begin Source File

SOURCE=".\201008202106Ð»Ã÷ÕÜView.h"
# End Source File
# Begin Source File

SOURCE=.\Choose.h
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TalkDialog.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\201008202106Ð»Ã÷ÕÜ.ico"
# End Source File
# Begin Source File

SOURCE=".\res\201008202106Ð»Ã÷ÕÜ.rc2"
# End Source File
# Begin Source File

SOURCE=".\res\201008202106Ð»Ã÷ÕÜDoc.ico"
# End Source File
# Begin Source File

SOURCE=.\arrow.cur
# End Source File
# Begin Source File

SOURCE=.\res\BG.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BG1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BG2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BG3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BG4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BG4~1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Hanio1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Hanio2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\idr_my20.ico
# End Source File
# Begin Source File

SOURCE=.\res\link.cur
# End Source File
# Begin Source File

SOURCE=.\res\Login.bmp
# End Source File
# Begin Source File

SOURCE=.\nodrop.cur
# End Source File
# Begin Source File

SOURCE=".\res\QQ½ØÍ¼20130523161827.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\QQ½ØÍ¼20130523162901.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\QQ½ØÍ¼20130523164140.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\QQ½ØÍ¼20130523165259.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\QQ½ØÍ¼20130523165340.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\RectBg1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RectBg2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\save.ico
# End Source File
# Begin Source File

SOURCE=.\res\Solve.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Solve.ico
# End Source File
# Begin Source File

SOURCE=.\res\Title.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=".\201008202106Ð»Ã÷ÕÜ.reg"
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
