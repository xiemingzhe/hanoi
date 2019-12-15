// 201008202106л����View.cpp : implementation of the CMy201008202106View class
//

#include "stdafx.h"
#include "201008202106л����.h"

#include "201008202106л����Doc.h"
#include "201008202106л����View.h"
#include "MainFrm.h"

#include "Choose.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106View
IMPLEMENT_DYNCREATE(CMy201008202106View, CView) 

BEGIN_MESSAGE_MAP(CMy201008202106View, CView)
	//{{AFX_MSG_MAP(CMy201008202106View)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106View construction/destruction

CMy201008202106View::CMy201008202106View()
{
	// TODO: add construction code here
	Background1.LoadBitmap(IDB_BG1);
    BackgroundBrush1.CreatePatternBrush(&Background1);//λͼ��ˢ
	Background2.LoadBitmap(IDB_BG2);
    BackgroundBrush2.CreatePatternBrush(&Background2);//λͼ��ˢ
	Background3.LoadBitmap(IDB_BG3);
    BackgroundBrush3.CreatePatternBrush(&Background3);//λͼ��ˢ

	RectBg1.LoadBitmap(IDB_RECTBG1);
	rectbg1.CreatePatternBrush(&RectBg1);//λͼ��ˢ

	RectBg2.LoadBitmap(IDB_RECTBG2);
	rectbg2.CreatePatternBrush(&RectBg2);//λͼ��ˢ
}

CMy201008202106View::~CMy201008202106View()
{
}

BOOL CMy201008202106View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106View drawing

void CMy201008202106View::OnDraw(CDC* pDC)
{    
	CMy201008202106Doc* pDoc = GetDocument();
	
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect Clientrect;
	GetClientRect(&Clientrect);
	switch(pDoc->bg)
	{		
	case 1:
		pDC->FillRect(Clientrect,&BackgroundBrush1);
		break;
	case 2:
		pDC->FillRect(Clientrect,&BackgroundBrush2);
		break;
	case 3:
		pDC->FillRect(Clientrect,&BackgroundBrush3);
		break;		
	}

	if(pDoc->change==TRUE)//����Ϸ
	{   
		KillTimer(0); //������ʱ��
		PlaySound(NULL,NULL,SND_FILENAME);//����ֹͣ
	
		CMy201008202106Doc *doc = (CMy201008202106Doc *)GetDocument();
		doc->UpdateAllViews(this);
		TotalStep=0;	
		pDoc->change=false;
		CMy201008202106View::OnInitialUpdate();
	}

    pDoc->change=FALSE;
    CMy201008202106View::Drawhanoi();//���ƺ�ŵ������

	int i = 1;
	while(i<=pDoc->diskNum)
	{
		pDC->FillRect(&pDoc->hanoi[i].rect,&rectbg1);
		i++;
	}
	if(pDoc->Solve==TRUE)//ѡ���Զ��ⷨ
	{   
		TotalStep=0;
		pDoc->Step=0;
		MovePath(1,2,3,pDoc->diskNum);
		CString str;
		/*for(i = 1 ;i<=TotalStep;i++)
		{
	     	str.Format("%d %d %d",HandleDisk[i],From[i],To[i]);
			MessageBox(str);
		}*/
		
		pDoc->Solve=FALSE;
		pDoc->IsCpmputer=TRUE;//��������ͼ��Ondraw��ִ��
		//CString str;
		//str.Format("%d",TotalStep);
		//MessageBox(str);
		//PlaySound("3.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);//ѭ������
		pDoc->Step =0; //������ʼ��Ϊ0
		//CMy201008202106View::OnInitialUpdate();
		CMy201008202106View::OnDraw(pDC);
	    m=1; //��ʼ����
		SetTimer(0,1000,NULL);
	}	
}
/////////////////////////////////////////////////////////////////////////////
// CMy201008202106View printing

BOOL CMy201008202106View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy201008202106View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy201008202106View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106View diagnostics

#ifdef _DEBUG
void CMy201008202106View::AssertValid() const
{
	CView::AssertValid();
}

void CMy201008202106View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy201008202106Doc* CMy201008202106View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy201008202106Doc)));
	return (CMy201008202106Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy201008202106View message handlers

void CMy201008202106View::OnInitialUpdate() 
{   
	CView::OnInitialUpdate();
	CMy201008202106Doc* pDoc = GetDocument();
	// TODO: Add your specialized code here and/or call the base class
	float Interval=(float)((100.0-20.0)/pDoc->diskNum); //����֮��ĳ��̼��
	float width=PositionA*2;             //����εĳ���
	int height=ColHeight;              //���ӵĸ߶�	
    SelectDisc=-1;                      //�趨��ʼֵ-1��δѡ���κ�����
	IsTopRect = false;
	PosLine =-1;
	m=1;
	//ȷ������
	if(pDoc->IsOpen==FALSE)
	{
		int i=pDoc->diskNum;
		while(i>0)
		{
			pDoc->hanoi[i].rect.left =(int)(PositionA-width/2);
			pDoc->hanoi[i].rect.right=(int)(PositionA+width/2);
			pDoc->hanoi[i].rect.top=height-20+2; //ÿ���������¼��2����λ
			pDoc->hanoi[i].rect.bottom=height;   //���εĵײ�λ��
			pDoc->hanoi[i].Holder=1;             //��¼����������Բ��
			pDoc->hanoi[i].order=i;              //��¼���εĳ���
			width=width-Interval*2;        
			height=height-20;
			i--;      
		}
	}
	pDoc->IsOpen=FALSE;
}

void CMy201008202106View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CMy201008202106Doc *pDoc=(CMy201008202106Doc*)GetDocument();
	if(pDoc->IsCpmputer==TRUE)
		return;
	CClientDC dc(this);
	CMy201008202106View::Drawhanoi();//���ƺ�ŵ�����ӣ��ػ��ַ�ABC��
	//��mousr����Rectʱ
	PosLine = -1;
	int i = 1;
	while(i<=pDoc->diskNum)
	{
		if(pDoc->hanoi[i].rect.PtInRect(point))
		{
            dc.FillRect(&pDoc->hanoi[i].rect,&rectbg2);//����ʱ���
		}
		else
		{
			dc.FillRect(&pDoc->hanoi[i].rect,&rectbg1);
		}
		i++;
	}
	
	//ѡ�е��Ƕ��˵����ӣ������ƶ�
	if(IsTopRect==true)//&&withDraw==0
	{
		//�������
		//CMy201008202106Doc *doc=(CMy201008202106Doc*)GetDocument();
        
		CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
		CString str;
		str.Format("�����ƶ���%d",pDoc->hanoi[SelectDisc].order);
		str +="����";
	    pFrame->m_wndStatusBar.SetPaneText(0,str);

		if(pDoc->bg==1)
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush1);
		if(pDoc->bg==2)
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush2);
		if(pDoc->bg==3)
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush3);
		
		//�ػ�
		int w=pDoc->hanoi[SelectDisc].rect.right-pDoc->hanoi[SelectDisc].rect.left;
		int h=pDoc->hanoi[SelectDisc].rect.bottom-pDoc->hanoi[SelectDisc].rect.top;
		
        pDoc->hanoi[SelectDisc].rect.left=point.x-PointInRectWidth;
		pDoc->hanoi[SelectDisc].rect.right=pDoc->hanoi[SelectDisc].rect.left+w;
		pDoc->hanoi[SelectDisc].rect.top=point.y-PointInRectHeight;
		pDoc->hanoi[SelectDisc].rect.bottom=pDoc->hanoi[SelectDisc].rect.top+h;
		
		dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&rectbg2);
		
		//�ж�ѡ�е������Ƿ����������
		CPen RedNew(PS_DASH,2,RGB(255,0,0));
		dc.SelectObject(&RedNew);
		if(pDoc->hanoi[SelectDisc].rect.left<=PositionA&&pDoc->hanoi[SelectDisc].rect.right>=PositionA)
		{
			PosLine=1;
			dc.MoveTo(PositionA,75);
			dc.LineTo(PositionA,ColHeight);		
		}
		else if(pDoc->hanoi[SelectDisc].rect.left<=PositionB&&pDoc->hanoi[SelectDisc].rect.right>=PositionB)
		{
			PosLine=2;
			dc.MoveTo(PositionB,75);
			dc.LineTo(PositionB,ColHeight);
		}
		else if(pDoc->hanoi[SelectDisc].rect.left<=PositionC&&pDoc->hanoi[SelectDisc].rect.right>=PositionC)
		{
			PosLine=3;
			dc.MoveTo(PositionC,75);
			dc.LineTo(PositionC,ColHeight);
		}
		else
		{
			PosLine=-1;
			CMy201008202106View::Drawhanoi();//���ƺ�ŵ������			
		}	
	}
	CView::OnMouseMove(nFlags, point);
}

void CMy201008202106View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMy201008202106Doc *pDoc=(CMy201008202106Doc*)GetDocument();
	if(pDoc->IsCpmputer==TRUE)
		return;
	CClientDC dc(this);
	IsTopRect = false ;//��Ҫ��,��갴��֮ǰû��ѡ���κ����ӣ�
	                   //���Բ������Ƿ�ѡ�񶥶�����֮˵
	                   //������ʱδ�������ӻῨ����Bug��������
	SelectDisc =-1 ;   //����֮ǰδѡ���κ�����
    HCURSOR pt=AfxGetApp()->LoadCursor(IDC_MOVE);
	::SetCursor(pt);
    SetCapture();
    //���ѡ�е�����
	int i =1;
	while(i<=pDoc->diskNum)
	{
		if(pDoc->hanoi[i].rect.PtInRect(point))
		{
			SelectDisc=i;
			break;
		}
		i++;
	}
	if(SelectDisc!=-1)
		dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&rectbg2);//ѡ�м���䣡

	//�ж��Ƿ�Ϊ���˺���
    i=1;
	while(i<=pDoc->diskNum&&SelectDisc!=-1)//ѡ��������
	{
        if(pDoc->hanoi[i].Holder==pDoc->hanoi[SelectDisc].Holder)
		  if(i!=SelectDisc&&(pDoc->hanoi[i].order<pDoc->hanoi[SelectDisc].order))
				break;
		 i++;
	}
 
	if(i>pDoc->diskNum)//�Ƕ�������
	{
		IsTopRect=true; //���ѡ�е��Ƕ�������
        InitialRect=pDoc->hanoi[SelectDisc].rect;//��¼��ʼλ��
		//����mouse��rect�ڵ�λ��
		PointInRectWidth =point.x-pDoc->hanoi[SelectDisc].rect.left;
		PointInRectHeight=point.y-pDoc->hanoi[SelectDisc].rect.top;
	}

	CView::OnLButtonDown(nFlags, point);
}

void CMy201008202106View::OnLButtonUp(UINT nFlags, CPoint point) 
{   
	
	CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	CString str;
	pFrame->m_wndStatusBar.SetPaneText(0,"��ǰ���κβ���!");

	CMy201008202106Doc *pDoc=(CMy201008202106Doc*)GetDocument();
	if(pDoc->IsCpmputer==TRUE)
		return;
	CClientDC dc(this);
    int i=0,m,j,width;
	int Havehanoi=0;
	int posX=0;  //��¼���ӵ�λ��
	int Isline=0;//��־���Ӵ��������ӣ��ǳ���Ҫ
    float length=(float)((100.0-20.0)/pDoc->diskNum);

	HCURSOR pt=AfxGetApp()->LoadCursor(IDC_POINTER);
	::SetCursor(pt);
    ReleaseCapture();//��mouse�Ƶ�window��,��mouse�Ѱ���,�򲻲�׽mouse!!!!!!!����ر�X��������
   
	if(IsTopRect==true)
	{    
		CMy201008202106Doc *doc=(CMy201008202106Doc*)GetDocument();
		if(doc->bg==1)
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush1);
		if(doc->bg==2)
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush2);
		if(doc->bg==3)
	        dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush3);

        i=1;
		m=64;  
		while(i<=doc->diskNum&&PosLine!=-1)
		{
			if(pDoc->hanoi[i].Holder==PosLine)
			{   
				Havehanoi=1;//������
				if(pDoc->hanoi[i].order<m)
				{
					m=pDoc->hanoi[i].order;//����������£��ҳ���Ӧ����PosLine�ϵ���С����
					j=i;
				}	   
			}
			i++;
		   Isline=1;//��־���������ӣ�
		}
		if(PosLine==1)
			posX = PositionA;
		if(PosLine==2)
			posX = PositionB;
		if(PosLine==3)
			posX = PositionC;

		//��������
		if(Havehanoi==1)
		{   
			//�ŵ���
			if(pDoc->hanoi[SelectDisc].order<pDoc->hanoi[j].order)
			{    
				//������1
				if(pDoc->hanoi[SelectDisc].Holder!=PosLine&&PosLine!=-1)
				{
					pDoc->Step++;
					pDoc->UpdateAllViews(this);//ˢ��������ͼ
				}
                
				pDoc->hanoi[SelectDisc].rect.bottom=pDoc->hanoi[j].rect.top-2;
				pDoc->hanoi[SelectDisc].rect.top=pDoc->hanoi[j].rect.top-20;
				width=pDoc->hanoi[SelectDisc].rect.right-pDoc->hanoi[SelectDisc].rect.left;			 
				pDoc->hanoi[SelectDisc].rect.left=posX-width/2; 
				pDoc->hanoi[SelectDisc].rect.right=posX+width/2;
				pDoc->hanoi[SelectDisc].Holder=PosLine;
				
				PlaySound("1.wav",NULL,SND_FILENAME|SND_ASYNC);//��������
			}
			else//�Ų���
			{
				pDoc->hanoi[SelectDisc].rect=InitialRect;//����
				PlaySound("2.wav",NULL,SND_FILENAME|SND_ASYNC);
			}

		}
		else if(Isline==1&&Havehanoi==0)//�������ӵ�ǰ���£����Ҵ�����û�����ӣ����ڽ����������ʧ��Bug��������
		{                               //������Ӵ����ƣ���δ�������ӵ�������Ҳ�ᱻִ�У���������������
			                            //���򱾸�ԭ·���ص�Ҳ����г�ˣ���������������������������������
            if(pDoc->hanoi[SelectDisc].Holder!=PosLine&&PosLine!=-1)
			{
				doc->Step++;
				doc->UpdateAllViews(this);//ˢ��������ͼ
			}
			pDoc->hanoi[SelectDisc].rect.bottom=ColHeight;
			pDoc->hanoi[SelectDisc].rect.top=ColHeight-20+2;
			width=pDoc->hanoi[SelectDisc].rect.right-pDoc->hanoi[SelectDisc].rect.left;
			pDoc->hanoi[SelectDisc].rect.left=posX-width/2;
			pDoc->hanoi[SelectDisc].rect.right=posX+width/2;
			pDoc->hanoi[SelectDisc].Holder=PosLine;
			PlaySound("1.wav",NULL,SND_FILENAME|SND_ASYNC);
		}

		if(PosLine==-1)
		{
        	pDoc->hanoi[SelectDisc].rect=InitialRect;//����
			PlaySound("2.wav",NULL,SND_FILENAME|SND_ASYNC);
		}
		dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&rectbg1);//�����ж�֮��ͱ������
	}

	IsTopRect=false;
	SelectDisc=-1;
	PosLine=-1;
	
	if(IsWIn()==TRUE)
	{
		if(MessageBox("��ϲ��ʤ���ˣ��������ս��","��Ϣ��ʾ",MB_OKCANCEL)==IDOK)
		{
			pDoc->Step = 0 ; //������ʼ��Ϊ0
			CMy201008202106View::OnInitialUpdate();
			pDoc->UpdateAllViews(this);
		}	
	}	
    CMy201008202106View::Drawhanoi();//���ƺ�ŵ������
	CView::OnLButtonUp(nFlags, point);
}

void CMy201008202106View::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu,*pPopup ;
	menu.LoadMenu(IDR_POPUP);
	pPopup = menu.GetSubMenu(0);
    CWnd * pWndPopOwner = this ;
	pWndPopOwner = pWndPopOwner->GetParent();
	pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON,point.x,point.y,pWndPopOwner);
	
}

BOOL CMy201008202106View::IsWIn()
{  
   CMy201008202106Doc *pDoc=(CMy201008202106Doc*)GetDocument();
   int i=1;
   BOOL s2 = true; 
   BOOL s3 = true; 
   while(i<=pDoc->diskNum)
   {
	   if(pDoc->hanoi[i].Holder!=2)
		   s2 = false ;
	   if(pDoc->hanoi[i].Holder!=3)
		   s3 = false ;
	   i++;
   }
   return (s2||s3);
}

void CMy201008202106View::Drawhanoi()
{
	CClientDC dc(this);
	CPen penNew(PS_DASH,2,RGB(0,0,0));
	CPen *oldPen = dc.SelectObject(&penNew); 
	
	dc.MoveTo(PositionA,75);
	dc.LineTo(PositionA,ColHeight);
	
	dc.MoveTo(PositionB,75);
	dc.LineTo(PositionB,ColHeight);
	
    dc.MoveTo(PositionC,75);
	dc.LineTo(PositionC,ColHeight);
	
	CRect rectL(0,ColHeight,640,ColHeight+8);	
	//COLORREF Color = RGB(50,200,100);
	COLORREF Color = RGB(200,100,200);
	CBrush brush(Color);
	dc.FillRect(rectL,&brush);
	
	dc.TextOut(PositionA-10,ColHeight+10,"A");
	dc.TextOut(PositionB-10,ColHeight+10,"B");
    dc.TextOut(PositionC-10,ColHeight+10,"C");
	dc.TextOut(PositionB-45,ColHeight+40,"��ŵ��С��Ϸ");

	dc.SelectObject(&oldPen);
	penNew.DeleteObject();
   
}

void CMy201008202106View::OnFileNew() 
{
	// TODO: Add your command handler code here
	CMy201008202106Doc *doc = (CMy201008202106Doc *)GetDocument();
	doc->Step = 0 ; //������ʼ��Ϊ0
	CMy201008202106View::OnInitialUpdate();
	doc->UpdateAllViews(this);
}

void CMy201008202106View::MovePath(int from, int with,int to, int disknum)
{
   	
    CMy201008202106Doc *doc = (CMy201008202106Doc *)GetDocument();
	CString str;
	if(disknum==1)
	{
		if(doc->pos[disknum]==from)
		{
			doc->pos[disknum]=to;
	        
			++TotalStep;
			HandleDisk[TotalStep]=disknum;
			From[TotalStep]=from;
	        To[TotalStep]=to;
		}
		else if(doc->pos[disknum]==with)
		{   
			doc->pos[disknum]=to;
		    
			++TotalStep;
			HandleDisk[TotalStep]=disknum;
			From[TotalStep]=with;
	        To[TotalStep]=to;
		}
		
		return;
	}
	if(doc->pos[disknum]==to)
	{   
		MovePath(from,with,to,disknum-1);
	}
	else if(doc->pos[disknum]==from)
	{
		MovePath(from,to,with,disknum-1);
		doc->pos[disknum]=to;
	    
		++TotalStep;
		HandleDisk[TotalStep]=disknum;
		From[TotalStep]=from;
	    To[TotalStep]=to;

		MovePath(with,from,to,disknum-1);
		return;
	}
	else 
	{
		MovePath(with,to,from,disknum-1);
		doc->pos[disknum]=to;
		CString str;

		++TotalStep;
		HandleDisk[TotalStep]=disknum;
		From[TotalStep]=with;
	    To[TotalStep]=to;

		MovePath(from,with,to,disknum-1);
		return;
  }
}

void CMy201008202106View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CMy201008202106Doc *pDoc=(CMy201008202106Doc*)GetDocument();
	CClientDC dc(this);
	int i=0,min,j,width;
	int posX=0;  //��¼���ӵ�λ��
    float length=(float)((100.0-20.0)/pDoc->diskNum);
	if(m<=TotalStep)
	{   
		SelectDisc=HandleDisk[m];
        dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&rectbg2);
		
		if(pDoc->bg==1)
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush1);
		if(pDoc->bg==2)
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush2);
		if(pDoc->bg==3)
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&BackgroundBrush3);
		CMy201008202106View::Drawhanoi();
		
		i=1;
		j=-1;
		min=64;
		int Havehanoi=0;
		
		while(i<=pDoc->diskNum)
		{
			if(pDoc->hanoi[i].Holder==To[m])
			{   
				Havehanoi=1;//������
				if(pDoc->hanoi[i].order<min)
				{
					min=pDoc->hanoi[i].order;//����������£��ҳ���Ӧ����PosLine�ϵ���С����
					j=i;
				}	   
			}
			i++;
		}
		
		if(To[m]==1)
			posX = PositionA;
		if(To[m]==2)
			posX = PositionB;
		if(To[m]==3)
			posX = PositionC;
		if(j>0)
		{
			pDoc->hanoi[SelectDisc].rect.bottom=pDoc->hanoi[j].rect.top-2;
			pDoc->hanoi[SelectDisc].rect.top=pDoc->hanoi[j].rect.top-20;
			width=pDoc->hanoi[SelectDisc].rect.right-pDoc->hanoi[SelectDisc].rect.left;			 
			pDoc->hanoi[SelectDisc].rect.left=posX-width/2; 
			pDoc->hanoi[SelectDisc].rect.right=posX+width/2;
			pDoc->hanoi[SelectDisc].Holder=To[m];
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&rectbg1);//�����ж�֮��ͱ������
		}
		
		else
		{            
			pDoc->hanoi[SelectDisc].rect.bottom=ColHeight;
			pDoc->hanoi[SelectDisc].rect.top=ColHeight-20+2;
			width=pDoc->hanoi[SelectDisc].rect.right-pDoc->hanoi[SelectDisc].rect.left;
			pDoc->hanoi[SelectDisc].rect.left=posX-width/2;
			pDoc->hanoi[SelectDisc].rect.right=posX+width/2;
			pDoc->hanoi[SelectDisc].Holder=To[m];
			dc.FillRect(&pDoc->hanoi[SelectDisc].rect,&rectbg1);//�����ж�֮��ͱ������
		}
		CChoose *pChoose = (CChoose *)GetDocument();
		pDoc->Step++;
		pDoc->from=From[m];//��¼�������ƶ�������
		pDoc->to=To[m];    //Ȼ��������ͼ����ʾ
		pDoc->handle=HandleDisk[m];
		pDoc->UpdateAllViews(this);
		m++;
	}
	else
	{   
		KillTimer(0);
		pDoc->IsCpmputer=FALSE;
		//PlaySound(NULL,NULL,SND_FILENAME);//����ֹͣ
		MessageBox("�����ƶ����!");
        pDoc->Step=0;
		CMy201008202106View::OnInitialUpdate();
		pDoc->UpdateAllViews(this);
		TotalStep=0;	
	}
	
	CView::OnTimer(nIDEvent);
}