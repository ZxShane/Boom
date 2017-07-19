
// BoomShowView.cpp : CBoomShowView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CBoomShowView ����/����

CBoomShowView::CBoomShowView()
{
	// TODO: �ڴ˴���ӹ������

}

CBoomShowView::~CBoomShowView()
{
}

BOOL CBoomShowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CBoomShowView ����

void CBoomShowView::OnDraw(CDC* pDC)
{

	CFont font;
	font.CreatePointFont(250, _T("�����п�"));//��һ����ʾ���δ�С
	CFont *pFont = pDC->SelectObject(&font);

	COLORREF color = RGB(255, 0, 0);//������ɫ
	pDC->SetTextColor(color);
	if (flag3 = 1)
	{
		pDC->TextOut(m_pt.x,m_pt.y-50,_T("�Ұ���"), 3);
	}
	//�������Ͻ�λ�ã�д�����֣����ֵ���Ŀ
	//ע�⣺һ��������������Ŀ
		pDC->SelectObject(pFont);
	font.DeleteObject();

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CBoomShowView ��ӡ


void CBoomShowView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBoomShowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CBoomShowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CBoomShowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CBoomShowView ���

#ifdef _DEBUG
void CBoomShowView::AssertValid() const
{
	CView::AssertValid();
}

void CBoomShowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBoomShowDoc* CBoomShowView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBoomShowDoc)));
	return (CBoomShowDoc*)m_pDocument;
}
#endif //_DEBUG


// CBoomShowView ��Ϣ�������


void CBoomShowView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap   bmp1;
	bmp1.LoadBitmap(IDB_BITMAP1); 
	//IDB_BITMAP�����Լ���ͼ��Ӧ��ID            
	BITMAP   bitmap1;
	bmp1.GetBitmap(&bitmap1);
	
	CBitmap   *pbmpOld1 = dcMem.SelectObject(&bmp1);
	
dc.BitBlt(0, 0, bitmap1.bmWidth * 3, bitmap1.bmHeight * 2, &dcMem, 0, 0, SRCCOPY);
dcMem.SelectObject(pbmpOld1);

CBitmap   bmp5;
bmp5.LoadBitmap(IDB_BITMAP11);
//IDB_BITMAP�����Լ���ͼ��Ӧ��ID            
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	CPen pen(PS_SOLID, 5, RGB(250,0,0));    //���廭��
	CClientDC dc(this);   //����
	CPen *pOldPen = dc.SelectObject(&pen);
	dc.MoveTo(oldpoint);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);
	
	double delte_x = newpoint.x - oldpoint.x;
	double delte_y = newpoint.y - oldpoint.y;
	double vx = 0.5*delte_x;
	double vy = 0.5*delte_y;

	double timer = 0;
	double delaytime = 2000 / sqrt(vx*vx + vy*vy);			//�˴������趨���ٶ�
	POINT  point1; point1.y = 0;
	for (int i = 0;point1.y < oldpoint.y + 150;i++) {
		flag2 = 1;
		point1 = route(oldpoint, vx, vy, timer);
		pt = point1;
		dc.Ellipse(point1.x - 2, point1.y - 2, point1.x + 2, point1.y + 2);
		Sleep(delaytime);//��ʾ���ٶȸ����ٶȵĴ�С�趨
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
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
