// 201008202106Ð»Ã÷ÕÜDoc.cpp : implementation of the CMy201008202106Doc class
//

#include "stdafx.h"
#include "201008202106Ð»Ã÷ÕÜ.h"

#include "201008202106Ð»Ã÷ÕÜDoc.h"
#include "201008202106Ð»Ã÷ÕÜView.h"

#include "Choose.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106Doc

IMPLEMENT_DYNCREATE(CMy201008202106Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy201008202106Doc, CDocument)
	//{{AFX_MSG_MAP(CMy201008202106Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106Doc construction/destruction

CMy201008202106Doc::CMy201008202106Doc()
{
	// TODO: add one-time construction code here
    Step=0;
	bg=1;
	diskNum = 5;
	change = false;
	Solve = false;
	IsOpen = FALSE;
}

CMy201008202106Doc::~CMy201008202106Doc()
{
}

BOOL CMy201008202106Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    SetTitle("ÆÚÄ©¿¼ÊÔ");
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106Doc serialization
void CMy201008202106Doc::Serialize(CArchive& ar)
{   
	
	if(ar.IsStoring())
	{	// storing code
		IsOpen = TRUE ;
		ar<<bg<<diskNum<<Step<<IsOpen;
		for (int i=1;i<=diskNum;i++)
		{
			ar<<hanoi[i].Holder;
			ar<<hanoi[i].order;
			ar<<hanoi[i].rect;
		}
	}
	else
	{	// loading code
		ar>>bg>>diskNum>>Step>>IsOpen;
		for (int i=1;i<=diskNum;i++)
		{
			ar>>hanoi[i].Holder;
			ar>>hanoi[i].order;
			ar>>hanoi[i].rect;
		}
	}
	  
}

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106Doc diagnostics

#ifdef _DEBUG
void CMy201008202106Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy201008202106Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106Doc commands

