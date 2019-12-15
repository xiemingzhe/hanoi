// Login.cpp : implementation file
//

#include "stdafx.h"
#include "201008202106Ð»Ã÷ÕÜ.h"
#include "Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Login dialog


Login::Login(CWnd* pParent /*=NULL*/)
	: CDialog(Login::IDD, pParent)
{
	//{{AFX_DATA_INIT(Login)
	m_name = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Login)
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_PASS, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Login, CDialog)
	//{{AFX_MSG_MAP(Login)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

