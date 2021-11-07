# Microsoft Developer Studio Project File - Name="proDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=proDemo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "proDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "proDemo.mak" CFG="proDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "proDemo - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "proDemo - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "proDemo - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "proDemo - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "proDemo - Win32 Release"
# Name "proDemo - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CAddGoods.cpp
# End Source File
# Begin Source File

SOURCE=.\CAddGoodsMenuWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CBeginWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CButton.cpp
# End Source File
# Begin Source File

SOURCE=.\CControl.cpp
# End Source File
# Begin Source File

SOURCE=.\CEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\CFile.cpp
# End Source File
# Begin Source File

SOURCE=.\CGoods.cpp
# End Source File
# Begin Source File

SOURCE=.\CGoodsSearch.cpp
# End Source File
# Begin Source File

SOURCE=.\CInputGoodsWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\CLogin.cpp
# End Source File
# Begin Source File

SOURCE=.\CManagerMenuWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CNewOrderWin.cpp
# End Source File
# Begin Source File

SOURCE=.\COrderCheckWin.cpp
# End Source File
# Begin Source File

SOURCE=.\COrderCheckWin_2.cpp
# End Source File
# Begin Source File

SOURCE=.\COrderManWin.cpp
# End Source File
# Begin Source File

SOURCE=.\COrderManWin_Menu.cpp
# End Source File
# Begin Source File

SOURCE=.\COrderTableWin.cpp
# End Source File
# Begin Source File

SOURCE=.\COutGoodsWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CRegisterWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CTable.cpp
# End Source File
# Begin Source File

SOURCE=.\CTable_2.cpp
# End Source File
# Begin Source File

SOURCE=.\CTable_3.cpp
# End Source File
# Begin Source File

SOURCE=.\CTips_Check_Win.cpp
# End Source File
# Begin Source File

SOURCE=.\CTipsWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CTipsWin_2.cpp
# End Source File
# Begin Source File

SOURCE=.\CTool.cpp
# End Source File
# Begin Source File

SOURCE=.\CUser.cpp
# End Source File
# Begin Source File

SOURCE=.\CWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CAddGoods.h
# End Source File
# Begin Source File

SOURCE=.\CAddGoodsMenuWin.h
# End Source File
# Begin Source File

SOURCE=.\CBeginWin.h
# End Source File
# Begin Source File

SOURCE=.\CButton.h
# End Source File
# Begin Source File

SOURCE=.\CControl.h
# End Source File
# Begin Source File

SOURCE=.\CEdit.h
# End Source File
# Begin Source File

SOURCE=.\CFile.h
# End Source File
# Begin Source File

SOURCE=.\CGoods.h
# End Source File
# Begin Source File

SOURCE=.\CGoodsSearch.h
# End Source File
# Begin Source File

SOURCE=.\CInputGoodsWin.h
# End Source File
# Begin Source File

SOURCE=.\CLabel.h
# End Source File
# Begin Source File

SOURCE=.\CLogin.h
# End Source File
# Begin Source File

SOURCE=.\CManagerMenuWin.h
# End Source File
# Begin Source File

SOURCE=.\CNewOrderWin.h
# End Source File
# Begin Source File

SOURCE=.\COrderCheckWin.h
# End Source File
# Begin Source File

SOURCE=.\COrderCheckWin_2.h
# End Source File
# Begin Source File

SOURCE=.\COrderManWin.h
# End Source File
# Begin Source File

SOURCE=.\COrderManWin_Menu.h
# End Source File
# Begin Source File

SOURCE=.\COrderTableWin.h
# End Source File
# Begin Source File

SOURCE=.\COutGoodsWin.h
# End Source File
# Begin Source File

SOURCE=.\CRegisterWin.h
# End Source File
# Begin Source File

SOURCE=.\CTable.h
# End Source File
# Begin Source File

SOURCE=.\CTable_2.h
# End Source File
# Begin Source File

SOURCE=.\CTable_3.h
# End Source File
# Begin Source File

SOURCE=.\CTips_Check_Win.h
# End Source File
# Begin Source File

SOURCE=.\CTipsWin.h
# End Source File
# Begin Source File

SOURCE=.\CTipsWin_2.h
# End Source File
# Begin Source File

SOURCE=.\CTool.h
# End Source File
# Begin Source File

SOURCE=.\CUser.h
# End Source File
# Begin Source File

SOURCE=.\CWindow.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
