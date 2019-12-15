// TalkDialog.cpp : implementation file
//

#include "stdafx.h"
#include "201008202106谢明哲.h"
#include "TalkDialog.h"
#include <winsock.h>
#include <windows.h>
#pragma comment(lib,"WS2_32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TalkDialog dialog


TalkDialog::TalkDialog(CWnd* pParent /*=NULL*/)
: CDialog(TalkDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(TalkDialog)
	m_port1 = 55555;
	m_port2 = 55556;
	m_sendtext = _T("");
	m_showtext = _T("");
	m_addr = _T("127.0.0.1");
	//}}AFX_DATA_INIT
	Cred= 255;
	Cgreen= 255;
	Cblue= 255;
	Fred = 0;
	Fgreen = 0;
	Fblue = 0;

}


void TalkDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TalkDialog)
	DDX_Text(pDX, IDC_PORT1, m_port1);
	DDV_MinMaxInt(pDX, m_port1, 0, 65535);
	DDX_Text(pDX, IDC_PORT2, m_port2);
	DDV_MinMaxInt(pDX, m_port2, 0, 65535);
	DDX_Text(pDX, IDC_SENDTEXT, m_sendtext);
	DDX_Text(pDX, IDC_SHOWTEXT, m_showtext);
	DDX_Text(pDX, IDC_ADDR, m_addr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TalkDialog, CDialog)
//{{AFX_MSG_MAP(TalkDialog)
ON_BN_CLICKED(IDC_CONNECT, OnConnect)
ON_BN_CLICKED(ID_SEND, OnSend)
ON_MESSAGE(WM_SOCKET,OnSocket)   //自定义消息映射项
	ON_BN_CLICKED(IDC_BREAK, OnBreak)
	ON_BN_CLICKED(IDC_SETFONT, OnSetFontColor)
	ON_BN_CLICKED(IDC_SETCOLOR, OnSetColor)
	ON_WM_DESTROY()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TalkDialog message handlers

BOOL TalkDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	w = MAKEWORD(2,0); 
	::WSAStartup(w,&data);
	this->SetWindowText("谢明哲");
	
	GetDlgItem(IDC_SENDTEXT)->EnableWindow(false);
	GetDlgItem(ID_SEND)->EnableWindow(false);
	GetDlgItem(IDC_BREAK)->EnableWindow(false);
    
	s=::socket(AF_INET,SOCK_DGRAM,0);
	ASSERT(s!=NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void TalkDialog::OnConnect() 
{
	// TODO: Add your control notification handler code here
	w = MAKEWORD(2,0); 
	::WSAStartup(w,&data);
	s=::socket(AF_INET,SOCK_DGRAM,0);
	UpdateData(TRUE);
	if(m_addr=="")
		MessageBox("地址或端口不能为空！","提示信息");
    else
	{
		addr1.sin_family=AF_INET;
		addr1.sin_addr.S_un.S_addr=INADDR_ANY;
		addr1.sin_port=htons(m_port2);
		
		if(bind(s,(sockaddr*)&addr1,sizeof(addr1))==SOCKET_ERROR)
		{
			MessageBox("地址绑定失败!","提示信息");
			return ;
		}
		
		addr2.sin_family=AF_INET;
		addr2.sin_addr.S_un.S_addr=inet_addr(m_addr.GetBuffer(0));
		addr2.sin_port=htons(m_port1);
		
		if(::WSAAsyncSelect(s,this->m_hWnd,WM_SOCKET,FD_READ)>0)
			MessageBox("设置异步模式失败！","提示信息");
		
		m_showtext="设定成功，开始聊天……";
		UpdateData(FALSE);
		
		GetDlgItem(IDC_SENDTEXT)->EnableWindow(true);
		GetDlgItem(IDC_CONNECT)->EnableWindow(false);
		GetDlgItem(IDC_BREAK)->EnableWindow(true);
		GetDlgItem(ID_SEND)->EnableWindow(true);
		GetDlgItem(IDC_ADDR)->EnableWindow(false);
		GetDlgItem(IDC_PORT1)->EnableWindow(false);
		GetDlgItem(IDC_PORT2)->EnableWindow(false);
	}	
}

void TalkDialog::OnSend() 
{
	// TODO: Add your control notification handler code here
	CString timestr;
	CClientDC dc(this);

	UpdateData(TRUE);
	if(m_sendtext=="")
	{
		MessageBox("消息不能为空!");
	}
    else
	{    
		//HWND hWnd;  
        //hWnd = GetDlgItem(IDC_SHOWTEXT)->GetSafeHwnd();  
		//::RedrawWindow(hWnd,NULL,NULL,RDW_INVALIDATE|RDW_ERASE|RDW_ERASENOW); //清空背景

		CEdit *pEt = (CEdit *)GetDlgItem(IDC_SHOWTEXT);
		
		int nLen=pEt->SendMessage(WM_GETTEXTLENGTH);
        pEt->SetSel(nLen,nLen); 

		char *snedtext=m_sendtext.GetBuffer(m_sendtext.GetLength()+1);
		if(::sendto(s,snedtext,m_sendtext.GetLength(),0,(sockaddr*)&addr2,sizeof(addr2))==SOCKET_ERROR)
			MessageBox("消息发送失败!");

        time = CTime::GetCurrentTime();
        timestr = time.Format("%H:%M:%S");
		timestr+="\r\n";

        pEt->ReplaceSel("\r\nI Say: "+timestr+m_sendtext);
        
		GetDlgItem(IDC_SENDTEXT)->SetWindowText(NULL);

		//UpdateData(FALSE);
	}
	
}

LRESULT TalkDialog::OnSocket(WPARAM wParam,LPARAM lParam)
{
	char recv[1024]={0};
	CString timestr;
	int length =sizeof(addr2);

	if(lParam==FD_READ)
	{   
     	int pos=::recvfrom(s,recv,1024,0,(sockaddr*)&addr2,&length);
		::WSAAsyncSelect(s,this->m_hWnd,WM_SOCKET,FD_READ);
		recv[pos]=NULL;

		CEdit *pEt = (CEdit *)GetDlgItem(IDC_SHOWTEXT);


		int nLen=pEt->SendMessage(WM_GETTEXTLENGTH);
        pEt->SetSel(nLen,nLen); 

		time = CTime::GetCurrentTime();
        timestr = time.Format("%H:%M:%S");
		timestr+="\r\n";

		pEt->ReplaceSel("\r\nSomebody: "+timestr+recv);

		CWnd * pWnd = GetDlgItem(IDC_SHOWTEXT);
		pWnd->Invalidate();//刷新调用OnCtlColor()

		//UpdateData(FALSE);
	}
	return 0;
}


void TalkDialog::OnBreak() 
{
	// TODO: Add your control notification handler code here
	::closesocket(s);
	::WSACleanup(); 

	GetDlgItem(IDC_SENDTEXT)->EnableWindow(false);
	GetDlgItem(ID_SEND)->EnableWindow(false);
	GetDlgItem(IDC_ADDR)->EnableWindow(true);
	GetDlgItem(IDC_PORT1)->EnableWindow(true);
	GetDlgItem(IDC_PORT2)->EnableWindow(true);
	GetDlgItem(IDC_CONNECT)->EnableWindow(true);
	GetDlgItem(IDC_BREAK)->EnableWindow(false);

	m_showtext="已经断开绑定……";
	UpdateData(FALSE);

	
}

void TalkDialog::OnSetFontColor() 
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	CColorDialog dlg;
	if(dlg.DoModal()==IDOK)
	{
		COLORREF m_cc;
		m_cc = dlg.GetColor();
		Fred = GetRValue(m_cc);
		Fgreen = GetGValue(m_cc);
		Fblue = GetBValue(m_cc);
		CWnd * pWnd = GetDlgItem(IDC_SHOWTEXT);		
		pWnd->Invalidate();//刷新调用OnCtlColor()
	
	}
}

void TalkDialog::OnSetColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if(dlg.DoModal()==IDOK)
	{   
		COLORREF m_cc;
		m_cc = dlg.GetColor();
		Cred = GetRValue(m_cc);
		Cgreen = GetGValue(m_cc);
	    Cblue = GetBValue(m_cc);
		CWnd * pWnd = GetDlgItem(IDC_SHOWTEXT);
		pWnd->Invalidate();//刷新调用OnCtlColor()
	}
	
}

HBRUSH TalkDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(pWnd->GetDlgCtrlID()==IDC_SHOWTEXT)
	{   
		pDC->SetTextColor(RGB(Fred,Fgreen,Fblue));
		//pDC->SetBkMode(OPAQUE);
        pDC->SetBkMode(TRANSPARENT);
		return ::CreateSolidBrush(RGB(Cred,Cgreen,Cblue));	
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
