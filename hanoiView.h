// 201008202106谢明哲View.h : interface of the CMy201008202106View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_201008202106VIEW_H__D8E9A0CC_3D0E_4A92_B0B3_BFAD83EA19AA__INCLUDED_)
#define AFX_201008202106VIEW_H__D8E9A0CC_3D0E_4A92_B0B3_BFAD83EA19AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//包含文档视图的头文件
#include "201008202106谢明哲Doc.h"
#include "Choose.h"
#include "Login.h"

#include "MainFrm.h"

#pragma comment(lib,"Winmm.lib")//播放音乐
#include "Mmsystem.h" //播放音乐

//#define DiscNum    5   
#define PositionA 100  //柱子A的X坐标
#define PositionB 320
#define PositionC 540
#define ColHeight 400

class CMy201008202106View : public CView
{
protected: // create from serialization only
	CMy201008202106View();
	DECLARE_DYNCREATE(CMy201008202106View)

// Attributes
public:
	CMy201008202106Doc* GetDocument();

// Operations
public:
	int  SelectDisc;        //选中了哪个圆盘
	bool IsTopRect;         //是否选中顶盘
	int  PosLine;           //记录移到的圆柱位置
	CRect InitialRect;      //记录选中矩形的初始位置
	int PointInRectWidth;   //记录鼠标X坐标在矩形中长度
	int PointInRectHeight;  //记录鼠标Y坐标在矩形中的宽度
	int TotalStep;          //自动移动时记录总步数
	int HandleDisk[65535];
	int From[65535];
	int To[65535];
	int m;                 //记录步数

	CBrush BackgroundBrush1;
	CBitmap Background1 ;
	CBrush BackgroundBrush2;
	CBitmap Background2 ;
	CBrush BackgroundBrush3;
	CBitmap Background3 ;
   
	CBrush rectbg1;
    CBitmap RectBg1;

	CBrush rectbg2;
	CBitmap RectBg2;
    

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy201008202106View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void MovePath(int from,int with,int to,int disknum);
	void Drawhanoi();
	BOOL IsWIn();
	virtual ~CMy201008202106View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy201008202106View)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnFileNew();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 201008202106谢明哲View.cpp
inline CMy201008202106Doc* CMy201008202106View::GetDocument()
   { return (CMy201008202106Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_201008202106VIEW_H__D8E9A0CC_3D0E_4A92_B0B3_BFAD83EA19AA__INCLUDED_)
