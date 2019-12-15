// 201008202106Ð»Ã÷ÕÜ.h : main header file for the 201008202106Ð»Ã÷ÕÜ application
//

#if !defined(AFX_201008202106_H__1BA5C686_87C9_44EA_B7A1_08DEFBFDFF0D__INCLUDED_)
#define AFX_201008202106_H__1BA5C686_87C9_44EA_B7A1_08DEFBFDFF0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106App:
// See 201008202106Ð»Ã÷ÕÜ.cpp for the implementation of this class
//

class CMy201008202106App : public CWinApp
{
public:
	CMy201008202106App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy201008202106App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy201008202106App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_201008202106_H__1BA5C686_87C9_44EA_B7A1_08DEFBFDFF0D__INCLUDED_)
