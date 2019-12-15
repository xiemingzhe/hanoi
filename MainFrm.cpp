// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "201008202106谢明哲.h"

#include "MainFrm.h"

#include "Login.h"
#include "TalkDialog.h"

#include "201008202106谢明哲Doc.h"
//包含分割的两个窗体
#include "201008202106谢明哲View.h"
#include "Choose.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_LOGIN, OnLogin)
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_COMMAND(ID_BGSOUND, OnBgsound)
	ON_UPDATE_COMMAND_UI(ID_BGSOUND, OnUpdateBgsound)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	BgSound = false;
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//添加状态栏面板
	UINT  Indicates[4]; 
	for (int i = 0; i<4;i++)
		Indicates[i]= 40+i;
    m_wndStatusBar.SetIndicators(Indicates,4);
	CRect rect;
	GetClientRect(rect);
	UINT PaneWidth = rect.Width()/4;
	
	//设置面板宽度
	for(int n = 0;n<4;n++)
	{
		m_wndStatusBar.SetPaneInfo(n,45+n*10,SBPS_NORMAL,PaneWidth);
	}
	//设置状态栏面板文本
	
	m_wndStatusBar.SetPaneInfo(3,100,SBPS_NORMAL,800);
	m_wndStatusBar.SetPaneText(0,"当前无任何操作!");
	m_wndStatusBar.SetPaneText(1,"学号：201008202106");
	m_wndStatusBar.SetPaneText(2,"姓名：谢明哲");
	m_wndStatusBar.SetPaneText(3,"系统时间：获取系统时间……");

	SetTimer(0,1000,NULL);

	// be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	VERIFY(m_wndSplitter.CreateStatic(this,1,2));
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CChoose),CSize(0,0),pContext);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CMy201008202106View),CSize(0,0),pContext); 
	CChoose* pWnd=(CChoose*)m_wndSplitter.GetPane(0,0);
	CSize size=pWnd->GetTotalSize();
    m_wndSplitter.SetColumnInfo(0,size.cx,1);
	return true ;

}
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.cx=1100;
	cs.cy=610;
	//禁止窗口最大化
	//cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
    cs.style &= ~WS_MAXIMIZEBOX; //禁止窗口最大化
    //cs.style &= ~WS_MINIMIZEBOX; //禁止窗口最小化
	//cs.style &= ~WS_SYSMENU; //取消Title上的按钮
    cs.style &= ~WS_THICKFRAME;//使窗口不能用鼠标改变大小
    //cs.lpszClass = AfxRegisterWndClass(0);
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    m_strTitle = "谢明哲2106";

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnLogin() 
{
	// TODO: Add your command handler code here
	Login login;
	if(login.DoModal()==IDOK)
	{
        UpdateData(TRUE);
		/*if(login.m_name=="admin"&&login.m_password=="123456")
		{
           TalkDialog mytalk;
		   mytalk.DoModal();
		}
		else
		{
			MessageBox("账号或者密码错误,请重新输入！","信息提示");
			CMainFrame::OnLogin();
		}*/
		if(ConDataBase(login.m_name,login.m_password))
		{   

			TalkDialog mytalk = new TalkDialog();
		    mytalk.DoModal();		
		}
		else
		{
			MessageBox("账号或者密码错误,请重新输入！","信息提示");
			CMainFrame::OnLogin();
		}
		
	}
}
//数据库链接
BOOL CMainFrame::ConDataBase(CString username, CString password)
{
	 BOOL Exist;
	_ConnectionPtr m_Connection;
	_RecordsetPtr m_Recordset;
	::CoInitialize(NULL);
	//链接数据库
	try
    {
		m_Connection.CreateInstance(__uuidof(Connection));//创建实例
		m_Recordset.CreateInstance(__uuidof(Recordset));
        _bstr_t strConnect="Provider=Microsoft.Jet.OLEDB.4.0;Data Source=user.mdb;Jet OLEDB:DataBase";
		m_Connection->Open(strConnect,"","",adConnectUnspecified);
		CString sql ="select * from [user] where Username='"+username+"'and Password='"+password+"'";
        m_Recordset->Open(sql.GetBuffer(0),m_Connection.GetInterfacePtr(),adOpenForwardOnly,adLockOptimistic,adCmdText);
       
	}    
	catch (_com_error &e)
    {
		MessageBox(e.Description());
	}
	if(!m_Recordset->adoEOF)
		Exist = TRUE;
	else
		Exist = FALSE;
    //断开数据库链接
	try
	{
		m_Connection->Close();
	}
	catch(_com_error &e){MessageBox(e.Description());}
    return Exist;
	
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime time;
	time = CTime::GetCurrentTime();
	CString s = time.Format("%H:%M:%S");
	m_wndStatusBar.SetPaneText(3,"系统时间："+s);
	
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnBgsound() 
{   
	if(BgSound==false)
	{
	   PlaySound("3.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);//循环播放
	   BgSound = true ;
	}
	else
	{
	   PlaySound(NULL,NULL,SND_FILENAME);
       BgSound = false;
	}
	
}

void CMainFrame::OnUpdateBgsound(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(BgSound);
	
}
