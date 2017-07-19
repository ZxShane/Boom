
// BoomShowView.cpp : CBoomShowView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "BoomShow.h"
#endif

#include "BoomShowDoc.h"
#include "BoomShowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBoomShowView
CPoint oldpoint;
int flag1 = 0;
CPoint newpoint;
int flag2 = 0;
CPoint pt;
CPoint m_pt;
int timer_id = 0;
int m_BmpID;
int flag3 = 0;
int y = -80;
int x = -160;
IMPLEMENT_DYNCREATE(CBoomShowView, CView)

BEGIN_MESSAGE_MAP(CBoomShowView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBoomShowView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CBoomShowView 构造/析构

CBoomShowView::CBoomShowView()
{
	// TODO: 在此处添加构造代码

}

CBoomShowView::~CBoomShowView()
{
}

BOOL CBoomShowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBoomShowView 绘制

void CBoomShowView::OnDraw(CDC* pDC)
{

	CFont font;
	font.CreatePointFont(250, _T("华文行楷"));//第一个表示字形大小
	CFont *pFont = pDC->SelectObject(&font);

	COLORREF color = RGB(255, 0, 0);//文字颜色
	pDC->SetTextColor(color);
	if (flag3 = 1)
	{
		pDC->TextOut(m_pt.x,m_pt.y-50,_T("我爱你"), 3);
	}
	//文字左上角位置，写的文字，文字的数目
	//注意：一个汉字算两个数目
		pDC->SelectObject(pFont);
	font.DeleteObject();

	// TODO: 在此处为本机数据添加绘制代码
}


// CBoomShowView 打印


void CBoomShowView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBoomShowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBoomShowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBoomShowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CBoomShowView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBoomShowView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBoomShowView 诊断

#ifdef _DEBUG
void CBoomShowView::AssertValid() const
{
	CView::AssertValid();
}

void CBoomShowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBoomShowDoc* CBoomShowView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBoomShowDoc)));
	return (CBoomShowDoc*)m_pDocument;
}
#endif //_DEBUG


// CBoomShowView 消息处理程序


void CBoomShowView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap   bmp1;
	bmp1.LoadBitmap(IDB_BITMAP1); 
	//IDB_BITMAP是你自己的图对应的ID            
	BITMAP   bitmap1;
	bmp1.GetBitmap(&bitmap1);
	
	CBitmap   *pbmpOld1 = dcMem.SelectObject(&bmp1);
	
dc.BitBlt(0, 0, bitmap1.bmWidth * 3, bitmap1.bmHeight * 2, &dcMem, 0, 0, SRCCOPY);
dcMem.SelectObject(pbmpOld1);

CBitmap   bmp5;
bmp5.LoadBitmap(IDB_BITMAP11);
//IDB_BITMAP是你自己的图对应的ID            
BITMAP   bitmap5;
bmp5.GetBitmap(&bitmap5);

CBitmap   *pbmpOld5 = dcMem.SelectObject(&bmp5);

dc.BitBlt(500, 0, bitmap5.bmWidth * 3, bitmap5.bmHeight * 2, &dcMem, 0, 0, SRCCOPY);
dcMem.SelectObject(pbmpOld5);

if (flag1 == 1) {
	CBitmap   bmp2;
	bmp2.LoadBitmap(IDB_BITMAP4);
	BITMAP bitmap2;
	bmp2.GetBitmap(&bitmap2);
	CBitmap   *pbmpOld2 = dcMem.SelectObject(&bmp2);
	dc.BitBlt(oldpoint.x-160, oldpoint.y-60, bitmap2.bmWidth * 2, bitmap2.bmHeight * 2, &dcMem, 0, 0, SRCCOPY);
	dcMem.SelectObject(pbmpOld2);

}
if (flag2 == 1) {
	CBitmap   bmp3;
	bmp3.LoadBitmap(IDB_BITMAP5);
	BITMAP bitmap3;
	bmp3.GetBitmap(&bitmap3);
	CBitmap   *pbmpOld3 = dcMem.SelectObject(&bmp3);
	dc.BitBlt(oldpoint.x - 160, oldpoint.y, bitmap3.bmWidth, bitmap3.bmHeight, &dcMem, 0, 0, SRCCOPY);
	dcMem.SelectObject(pbmpOld3);

}

if (flag3 == 1) {

	CBitmap   bmp4;
	bmp4.LoadBitmap(IDB_BITMAP6);
	BITMAP bitmap4;
	bmp4.GetBitmap(&bitmap4);
	CBitmap   *pbmpOld4 = dcMem.SelectObject(&bmp4);
	dc.BitBlt(m_pt.x+x, m_pt.y+y , bitmap4.bmWidth, bitmap4.bmHeight, &dcMem, 0, 0, SRCCOPY);
	dcMem.SelectObject(pbmpOld4);
	OnDraw(&dc);

}

	CView::OnPaint();
}


void CBoomShowView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	oldpoint = point;
	flag1 = 1;
	flag2 = 0;
	flag3 = 0;
	timer_id++;
	m_BmpID = 0;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

POINT route(POINT start_point, double vx, double vy, int timer)
{
	double x = start_point.x + vx*timer / (100);
	double y = start_point.y + vy*timer / 100 + 0.5*9.8*timer*timer / (10000);
	POINT current_point;
	current_point.x = x;
	current_point.y = y;
	return current_point;
}
void CBoomShowView::OnLButtonUp(UINT nFlags, CPoint point)
{
	newpoint = point;
	CPen pen(PS_SOLID, 5, RGB(250,0,0));    //定义画笔
	CClientDC dc(this);   //画板
	CPen *pOldPen = dc.SelectObject(&pen);
	dc.MoveTo(oldpoint);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);
	
	double delte_x = newpoint.x - oldpoint.x;
	double delte_y = newpoint.y - oldpoint.y;
	double vx = 0.5*delte_x;
	double vy = 0.5*delte_y;

	double timer = 0;
	double delaytime = 2000 / sqrt(vx*vx + vy*vy);			//此处用于设定初速度
	POINT  point1; point1.y = 0;
	for (int i = 0;point1.y < oldpoint.y + 150;i++) {
		flag2 = 1;
		point1 = route(oldpoint, vx, vy, timer);
		pt = point1;
		dc.Ellipse(point1.x - 2, point1.y - 2, point1.x + 2, point1.y + 2);
		Sleep(delaytime);//显示的速度根据速度的大小设定
		timer += delaytime;
		if (point1.y > oldpoint.y + 100)
		{
			m_pt = point1;
			flag3 = 1;
			flag2 = 0;
			SetTimer(timer_id, 150, NULL);
			Invalidate();
		}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CBoomShowView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	m_BmpID++;
	if (m_BmpID >= 4)
	{
		flag1 = 0;
		flag2 = 0;
		flag3 = 0;
		Invalidate();
		KillTimer(nIDEvent);
	}
	
	CView::OnTimer(nIDEvent);
}
