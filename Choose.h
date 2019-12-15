#if !defined(AFX_CHOOSE_H__4DF28CDE_38C3_4F26_807F_6C694F60C019__INCLUDED_)
#define AFX_CHOOSE_H__4DF28CDE_38C3_4F26_807F_6C694F60C019__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Choose.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoose form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CChoose : public CFormView
{
protected:
	CChoose();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CChoose)

// Form Data
public:
	//{{AFX_DATA(CChoose)
	enum { IDD = IDD_CHOOSE };
	CComboBox	m_combo;
	int		m_step;
	CString	m_showstep;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoose)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CChoose();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CChoose)
	afx_msg void OnBackGround1();
	afx_msg void OnBackGround2();
	afx_msg void OnBackGround3();
	afx_msg void OnSelchange();
	afx_msg void OnSolve();
	afx_msg void OnEnd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSE_H__4DF28CDE_38C3_4F26_807F_6C694F60C019__INCLUDED_)
