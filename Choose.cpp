// Choose.cpp : implementation file
//

#include "stdafx.h"
#include "201008202106谢明哲.h"
#include "Choose.h"

#include "201008202106谢明哲View.h"
#include "201008202106谢明哲Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoose

IMPLEMENT_DYNCREATE(CChoose, CFormView)

CChoose::CChoose()
	: CFormView(CChoose::IDD)
{
	//{{AFX_DATA_INIT(CChoose)
	m_step = 0;
	m_showstep = _T("用户模式中......");
	//}}AFX_DATA_INIT
}

CChoose::~CChoose()
{
}

void CChoose::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChoose)
	DDX_Control(pDX, IDC_DISKNUM, m_combo);
	DDX_Text(pDX, IDC_COUNT, m_step);
	DDX_Text(pDX, IDC_ShowStep, m_showstep);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChoose, CFormView)
	//{{AFX_MSG_MAP(CChoose)
	ON_BN_CLICKED(IDC_RADIO1, OnBackGround1)
	ON_BN_CLICKED(IDC_RADIO2, OnBackGround2)
	ON_BN_CLICKED(IDC_RADIO3, OnBackGround3)
	ON_CBN_SELCHANGE(IDC_DISKNUM, OnSelchange)
	ON_BN_CLICKED(IDC_SOLVE, OnSolve)
	ON_BN_CLICKED(IDC_END, OnEnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChoose diagnostics

#ifdef _DEBUG
void CChoose::AssertValid() const
{
	CFormView::AssertValid();
}

void CChoose::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

void CChoose::OnDraw(CDC* pDC) 
{  
	// TODO: Add your specialized code here and/or call the base class
	CMy201008202106Doc *pDoc=(CMy201008202106Doc *)GetDocument();
	m_step=pDoc->Step;
	if(pDoc->IsCpmputer==TRUE)
	{
		CString from;
		CString to;
		CString handle;
		from.Format("%d",pDoc->from);
		to.Format("%d",pDoc->to);
		handle.Format("%d",pDoc->handle);
		m_showstep="第"+handle+"个盘子:"+from+"--->"+to;
	}
	if(pDoc->IsCpmputer==FALSE)
	{
		GetDlgItem(IDC_SOLVE)->EnableWindow(TRUE);
	    GetDlgItem(IDC_END)->EnableWindow(FALSE);
		
		m_showstep="用户模式中......";
	}
	UpdateData(FALSE);
	
}

void CChoose::OnBackGround1() 
{
	// TODO: Add your control notification handler code here
    CMy201008202106Doc *pDoc=(CMy201008202106Doc *)GetDocument();
	pDoc->bg=1;
	pDoc->UpdateAllViews(this);
	
}

void CChoose::OnBackGround2() 
{
	// TODO: Add your control notification handler code here
	CMy201008202106Doc *pDoc=(CMy201008202106Doc *)GetDocument();
	pDoc->bg=2;
	pDoc->UpdateAllViews(this);
}

void CChoose::OnBackGround3() 
{
	// TODO: Add your control notification handler code here
	CMy201008202106Doc *pDoc=(CMy201008202106Doc *)GetDocument();
	pDoc->bg=3;
	pDoc->UpdateAllViews(this);
}

void CChoose::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetDlgItem(IDC_END)->EnableWindow(FALSE);//初始时，演示结束按钮不能点击
    ((CComboBox*)GetDlgItem(IDC_DISKNUM))->SetCurSel(2);
	CButton *pB=(CButton*)GetDlgItem(IDC_RADIO1);
    pB->SetCheck(true);
}

void CChoose::OnSelchange() 
{
	// TODO: Add your control notification handler code here
    int nIndex = m_combo.GetCurSel();
	CString str;
    m_combo.GetLBText(nIndex,str); 
	int disknum=atoi(str);
	if(MessageBox("你真的要放弃当前游戏吗？","信息提示",MB_OKCANCEL)==IDOK)
	{
		CMy201008202106Doc *doc = (CMy201008202106Doc *)GetDocument();
		doc->diskNum=disknum;
		doc->change=true;
		m_showstep="用户模式中......";
		doc->Step = 0;
		doc->IsCpmputer=FALSE;//重新选中盘子后，默认进入用户模式
		UpdateData(FALSE);
		doc->UpdateAllViews(this);
	}		   
}

void CChoose::OnSolve() 
{   
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_SOLVE)->EnableWindow(FALSE);
	GetDlgItem(IDC_END)->EnableWindow(TRUE);
	CMy201008202106Doc *doc = (CMy201008202106Doc *)GetDocument();
	doc->Solve=TRUE;
	doc->IsCpmputer=TRUE;
	doc->Step =0;
	GetDlgItem(IDC_ShowStep)->SetWindowText("电脑模式中......");
    int i =1;
	while(i<=doc->diskNum)
	{
		doc->pos[i]=doc->hanoi[i].Holder;
		i++;
	}
	doc->UpdateAllViews(this);
	
}

void CChoose::OnEnd() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_SOLVE)->EnableWindow(TRUE);
	GetDlgItem(IDC_END)->EnableWindow(FALSE);
	CMy201008202106Doc *doc = (CMy201008202106Doc *)GetDocument();
	doc->Solve=FALSE;//可有可无
	doc->change=true;//以改变盘子数目的方式，结束自动演示
	doc->Step = 0;//必须加上，等候要调用OnDraw初始化，步数控件
	m_showstep="用户模式中......";
	doc->IsCpmputer=FALSE;//结束电脑模式后，默认进入用户模式
	UpdateData(FALSE);
	doc->UpdateAllViews(this);
}
