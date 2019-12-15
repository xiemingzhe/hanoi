#if !defined(AFX_TALKDIALOG_H__E9AAD52F_6E60_46BF_86C0_D0FC2D443896__INCLUDED_)
#define AFX_TALKDIALOG_H__E9AAD52F_6E60_46BF_86C0_D0FC2D443896__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TalkDialog.h : header file

/////////////////////////////////////////////////////////////////////////////
// TalkDialog dialog
#include "MainFrm.h"
#define WM_SOCKET WM_USER+99
class TalkDialog : public CDialog
{
// Construction
public:
    int Cred;
	int Cgreen;
	int Cblue; 
	int Fred;
	int Fgreen;
	int Fblue;
	CTime time;
	SOCKET s;
	WORD w;
	WSADATA data;
    struct sockaddr_in addr1,addr2;
	TalkDialog(CWnd* pParent = NULL);   // standard constructor
     
// Dialog Data
	//{{AFX_DATA(TalkDialog)
	enum { IDD = IDD_TALK };
	int		m_port1;
	int		m_port2;
	CString	m_sendtext;
	CString	m_showtext;
	CString	m_addr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TalkDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TalkDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnConnect();
	afx_msg void OnSend();
	afx_msg LRESULT OnSocket(WPARAM wParam,LPARAM lParam);
	afx_msg void OnBreak();
	afx_msg void OnSetFontColor();
	afx_msg void OnSetColor();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TALKDIALOG_H__E9AAD52F_6E60_46BF_86C0_D0FC2D443896__INCLUDED_)
