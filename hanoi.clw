; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "201008202106Ð»Ã÷ÕÜ.h"
LastPage=0

ClassCount=8
Class1=CMy201008202106App
Class2=CMy201008202106Doc
Class3=CMy201008202106View
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_LOGINICO
Resource2=IDD_CHOOSE
Class5=CAboutDlg
Class6=CChoose
Resource3=IDR_POPUP
Class7=Login
Resource4=IDR_MAINFRAME
Class8=TalkDialog
Resource5=IDD_ABOUTBOX
Resource6=IDD_TALK

[CLS:CMy201008202106App]
Type=0
HeaderFile=201008202106Ð»Ã÷ÕÜ.h
ImplementationFile=201008202106Ð»Ã÷ÕÜ.cpp
Filter=N

[CLS:CMy201008202106Doc]
Type=0
HeaderFile=201008202106Ð»Ã÷ÕÜDoc.h
ImplementationFile=201008202106Ð»Ã÷ÕÜDoc.cpp
Filter=N
LastObject=CMy201008202106Doc

[CLS:CMy201008202106View]
Type=0
HeaderFile=201008202106Ð»Ã÷ÕÜView.h
ImplementationFile=201008202106Ð»Ã÷ÕÜView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMy201008202106View


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_BGSOUND
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=201008202106Ð»Ã÷ÕÜ.cpp
ImplementationFile=201008202106Ð»Ã÷ÕÜ.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342312448
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_LOGIN
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_SPLIT
Command18=IDC_SOLVE
Command19=IDC_END
Command20=ID_BGSOUND
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=IDC_SOLVE
Command3=ID_BGSOUND
Command4=ID_FILE_NEW
Command5=ID_FILE_OPEN
Command6=ID_FILE_PRINT
Command7=ID_FILE_SAVE
Command8=ID_LOGIN
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_EDIT_CUT
Command17=ID_EDIT_UNDO
CommandCount=17

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_LOGIN
Command10=IDC_SOLVE
CommandCount=10

[DLG:IDD_CHOOSE]
Type=1
Class=CChoose
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COUNT,edit,1350633600
Control3=IDC_STATIC,static,1342308352
Control4=IDC_DISKNUM,combobox,1344340033
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO1,button,1342341129
Control7=IDC_RADIO2,button,1342210057
Control8=IDC_RADIO3,button,1342210057
Control9=IDC_SOLVE,button,1342279424
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_ShowStep,edit,1350633600
Control13=IDC_END,button,1342279424

[CLS:CChoose]
Type=0
HeaderFile=Choose.h
ImplementationFile=Choose.cpp
BaseClass=CFormView
Filter=D
LastObject=CChoose
VirtualFilter=VWC

[CLS:Login]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PASS
VirtualFilter=dWC

[DLG:IDD_TALK]
Type=1
Class=TalkDialog
ControlCount=16
Control1=ID_SEND,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_ADDR,edit,1350631552
Control7=IDC_PORT1,edit,1350631552
Control8=IDC_PORT2,edit,1350631552
Control9=IDC_STATIC,button,1342177287
Control10=IDC_SHOWTEXT,edit,1353779332
Control11=IDC_STATIC,button,1342177287
Control12=IDC_SENDTEXT,edit,1352728708
Control13=IDC_CONNECT,button,1342242816
Control14=IDC_BREAK,button,1342242816
Control15=IDC_SETFONT,button,1342242816
Control16=IDC_SETCOLOR,button,1342242816

[CLS:TalkDialog]
Type=0
HeaderFile=TalkDialog.h
ImplementationFile=TalkDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=TalkDialog
VirtualFilter=dWC

[MNU:IDR_POPUP]
Type=1
Class=?
Command1=ID_LOGIN
Command2=ID_VIEW_TOOLBAR
Command3=ID_VIEW_STATUS_BAR
Command4=ID_WINDOW_SPLIT
Command5=IDC_SOLVE
Command6=ID_BGSOUND
CommandCount=6

[DLG:IDD_LOGINICO]
Type=1
Class=Login
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_NAME,edit,1350631552
Control6=IDC_PASS,edit,1350631584
Control7=IDC_PICTURE,static,1342177294

