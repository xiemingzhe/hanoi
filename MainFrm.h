// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__CA341F30_11A8_48A6_8E6C_7A2E1E59202B__INCLUDED_)
#define AFX_MAINFRM_H__CA341F30_11A8_48A6_8E6C_7A2E1E59202B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TalkDialog.h"
#include "201008202106谢明哲Doc.h"
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
protected:
	CSplitterWnd m_wndSplitter;
public:
    HWND statu;
	// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL BgSound;
	BOOL ConDataBase(CString username,CString password);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members

	CToolBar    m_wndToolBar;
public:
	CStatusBar  m_wndStatusBar; //必须设置为公有类型，否则View视图中不能操作

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLogin();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBgsound();
	afx_msg void OnUpdateBgsound(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__CA341F30_11A8_48A6_8E6C_7A2E1E59202B__INCLUDED_)
