#if !defined(AFX_LOGIN_H__946B1216_6A5F_43ED_A591_8B4CC0C17D90__INCLUDED_)
#define AFX_LOGIN_H__946B1216_6A5F_43ED_A591_8B4CC0C17D90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Login dialog

class Login : public CDialog
{
// Construction
public:
	Login(CWnd* pParent = NULL);   // standard constructor

	CBitmap LoginBmp;

// Dialog Data
	//{{AFX_DATA(Login)
	enum { IDD = IDD_LOGIN };
	CString	m_name;
	CString	m_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Login)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Login)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__946B1216_6A5F_43ED_A591_8B4CC0C17D90__INCLUDED_)
