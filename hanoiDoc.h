// 201008202106谢明哲Doc.h : interface of the CMy201008202106Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_201008202106DOC_H__18EF5EBE_7CE4_4873_941B_E6C88144D79E__INCLUDED_)
#define AFX_201008202106DOC_H__18EF5EBE_7CE4_4873_941B_E6C88144D79E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	CRect rect; //记录圆盘区域的位置
	int Holder; //记录圆盘所在位置(A盘、B盘、C盘)
	int order;  //记录圆盘的大小
}HANOI;

class CMy201008202106Doc : public CDocument
{
protected: // create from serialization only
	CMy201008202106Doc();
	DECLARE_DYNCREATE(CMy201008202106Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy201008202106Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL IsOpen;
	HANOI hanoi[64];   //声明汉诺塔结构体数组
	BOOL IsCpmputer;
	int from;
	int to;
	int handle;
	BOOL Solve;
	BOOL change;
	int diskNum;
	int bg;
	int Step; //记录总步数
	int pos[64];
	virtual ~CMy201008202106Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy201008202106Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_201008202106DOC_H__18EF5EBE_7CE4_4873_941B_E6C88144D79E__INCLUDED_)
