// MFCprojectDlg.cpp 
#include "pch.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"
#include "Shape.h"
#include "TriangleC.h" 
#include "RectangleC.h"
#include "EllipseC.h"
#include "LineC.h"
#include "TrapezeC.h"
#include "HexagonalC.h"
#include "PentagonC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//constructor
CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent), PenType(0), PenSize(1), futureShapeKind(1), curColor(RGB(0, 0, 0)) 
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//photos
void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, PehTypeBotton);
	DDX_Control(pDX, IDC_BUTTON12, brush1);
	DDX_Control(pDX, IDC_BUTTON8, brush2);
	DDX_Control(pDX, IDC_BUTTON10, brush3);
	DDX_Control(pDX, IDC_BUTTON9, brush4);
	DDX_Control(pDX, IDC_BUTTON11, brush5);
	DDX_Control(pDX, IDC_BUTTON5, colorchoose);
	DDX_Control(pDX, IDCANCEL, Thick);
	DDX_Control(pDX, IDC_BUTTON4, undo);
	DDX_Control(pDX, IDC_BUTTON3, redo);
	DDX_Control(pDX, IDC_BUTTON6, newB);
	DDX_Control(pDX, IDC_BUTTON2, load);
	DDX_Control(pDX, IDC_BUTTON1, save);
}

//buttons declarations
BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCprojectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCprojectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCprojectDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCprojectDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCprojectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCprojectDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCprojectDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCprojectDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCprojectDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCprojectDlg::OnBnClickedButton12)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCprojectDlg::OnCbnSelchangeCombo1)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDCANCEL, &CMFCprojectDlg::OnBnClickedCancel)
	
	
END_MESSAGE_MAP()

static int Memory = 0;

BOOL CMFCprojectDlg::OnInitDialog()
{
	if (Memory == 0)
	{
		Memory++;
		this->OnCancel();
		OpenningScreen b;
		b.DoModal();
	}

	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);


	// Our amazing photos!
	colorchoose.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));
	undo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP30)));
	redo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP33)));
	newB.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP42)));
	load.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP38)));
	save.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP12)));
	brush1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP13)));
	brush2.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP17)));
	brush3.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP10)));
	brush4.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP20)));
	brush5.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP24)));
	Thick.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP9)));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//paint
void CMFCprojectDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CPen pen(PS_SOLID, 1, RGB(255, 255,255));
	CPen* oldP = dc.SelectObject(&pen);
	CBrush brush(RGB(255, 255, 255));
	CBrush* old = dc.SelectObject(&brush);
	dc.Rectangle(82, 500, 102, 520); // show the color in real time

	if (IsIconic())
	{

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < arrShapes.GetSize(); i++) {
			arrShapes[i]->Draw(&dc);
		}
	}

	for (int i = 0; i < arrShapes.GetSize(); i++)
	{
		CBrush myBrush;
		myBrush.CreateSolidBrush((*arrShapes[i]).getBgColor());
		dc.SelectObject(&myBrush);
		(dc).SetDCPenColor((*arrShapes[i]).bgColor);
		(*arrShapes[i]).Draw(&dc);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


///////////////////// action buttons /////////////////////

// when we press left mouse click
void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	start = point;
	isPressed = true;
	switch (futureShapeKind) // create the shape the user pressed
	{
	case 1:
		CurrenShape = new RectangleC;
		break;
	case 2:
		CurrenShape = new EllipseC;
		break;
	case 3:
		CurrenShape = new TriangleC;
		break;
	case 4:
		CurrenShape = new LineC;
		break;
	case 5:
		CurrenShape = new TrapezeC;
		break;
	case 6:
		CurrenShape = new HexagonalC;
		break;
	case 7:
		CurrenShape = new PentagonC;
		break;
	}
	CurrenShape->setShapePenSize(PenSize);
	CurrenShape->setShapePenType(PenType);
	CurrenShape->setBg(curColor);
	CurrenShape->setP(curColor);
	CurrenShape->SetID(futureShapeKind);
	arrShapes.Add(this->CurrenShape);
	//Invalidate();
	CDialogEx::OnLButtonDown(nFlags, point);
}

// when we relase the click on the left mouse
void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		end = point;
		isPressed = false;
		arrShapes[arrShapes.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	Invalidate();
	CDialogEx::OnLButtonUp(nFlags, point);
}

// two options:
// 1). draw the shape (and dont let go until you see the size you want darling) 
// 2). move the shape (click on the right click mouse and dont let go)
void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if (isPressed)
	{
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);
		arrShapes[arrShapes.GetSize() - 1]->Draw(&dc);
		end = point;
		arrShapes[arrShapes.GetSize() - 1]->Redefine(start, end);
		arrShapes[arrShapes.GetSize() - 1]->Draw(&dc);

		CBrush myBrush, * oldBrush;
		myBrush.CreateSolidBrush(RGB(255, 255, 255));
		oldBrush = dc.SelectObject(&myBrush);
		CPen myPen1(PS_SOLID, 1, RGB(0, 0, 0));
		CPen* oldPen;
		oldPen = dc.SelectObject(&myPen1);
		dc.SetROP2(R2_NOTXORPEN);

		dc.SelectObject(oldPen);
		dc.SetROP2(R2_COPYPEN);
		dc.SelectObject(oldBrush);
	}
	else if (isRPressed)
	{
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);
		end = point;
		end.x = point.x - RightClickP.x;
		end.y = point.y - RightClickP.y;
		CPoint TempEnd(CurrenShape->getP2().x + end.x, CurrenShape->getP2().y + end.y);
		CPoint TempStart(CurrenShape->getP1().x + end.x, CurrenShape->getP1().y + end.y);
		CurrenShape->setEnd(TempEnd);
		CurrenShape->setStart(TempStart);
		CurrenShape->Draw(&dc);
		CurrenShape->Redefine(TempStart, TempEnd);
		CurrenShape->Draw(&dc);
		RightClickP = point;
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

//turns flag isRpressed to "true" and set the current shape
void CMFCprojectDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	for (int i = (arrShapes.GetSize() - 1); i >= 0; i--)
	{
		if (arrShapes[i]->inShape(point))
		{
			RightClickP = point;
			CurrenShape = arrShapes[i];
			isRPressed = true;
			break;
		}
	}
	CDialogEx::OnRButtonDown(nFlags, point);
}

//release the flag that set "true" to ispressed
void CMFCprojectDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	if (isRPressed)
	{
		end = point;
		isRPressed = false;
		Invalidate(); 
	}
	CDialogEx::OnRButtonUp(nFlags, point);
}


///////////////////// simple buttons /////////////////////

//copy
void CMFCprojectDlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	for (int i = (arrShapes.GetSize() - 1); i >= 0; i--)//scaning all the shapes
	{
		if (arrShapes[i]->inShape(point))//if the mouse clicked in the area of some shape from list
		{
			switch (arrShapes[i]->GetID()) // create the shape the user pressed
			{
			case 1:
				CurrenShape = new RectangleC;
				break;
			case 2:
				CurrenShape = new EllipseC;
				break;
			case 3:
				CurrenShape = new TriangleC;
				break;
			case 4:
				CurrenShape = new LineC;
				break;
			case 5:
				CurrenShape = new TrapezeC;
				break;
			case 6:
				CurrenShape = new HexagonalC;
				break;
			case 7:
				CurrenShape = new PentagonC;
				break;

			}
			//COPYING THE CURRENT SHAPE
			CPoint TempEnd = arrShapes[i]->getP2();
			CPoint TempStart = arrShapes[i]->getP1();
			COLORREF tempPen = arrShapes[i]->getBgColor();

			//SHIFTING IN 10 AWAY - TO NOTICE THAT IT CREATED
			TempEnd.x = TempEnd.x + 10;
			TempEnd.y = TempEnd.y + 10;
			TempStart.x = TempStart.x + 10;
			TempStart.y = TempStart.y + 10;

			CurrenShape->setEnd(TempEnd);
			CurrenShape->setStart(TempStart);
			CurrenShape->setBgColor(tempPen);
			CurrenShape->SetID(arrShapes[i]->GetID());
			arrShapes.Add(CurrenShape);
			Invalidate();
			break;
		}

	}
	CDialogEx::OnRButtonDblClk(nFlags, point);
}

//choose shapes (circle, pentagon atc...)
void CMFCprojectDlg::OnBnClickedRadio1()
{
	futureShapeKind = 1;
}

void CMFCprojectDlg::OnBnClickedRadio2()
{
	futureShapeKind = 2;
}

void CMFCprojectDlg::OnBnClickedRadio3()
{
	futureShapeKind = 3;
}

void CMFCprojectDlg::OnBnClickedRadio4()
{
	futureShapeKind = 4;
}

void CMFCprojectDlg::OnBnClickedRadio5()
{
	futureShapeKind = 5;
}

void CMFCprojectDlg::OnBnClickedRadio6()
{
	futureShapeKind = 6;
}

void CMFCprojectDlg::OnBnClickedRadio7()
{
	futureShapeKind = 7;
}
//end choose shape

//save button
void CMFCprojectDlg::OnBnClickedButton1()
{	            
	CFileDialog dlg(FALSE, _T(".arrShapes"), NULL, 0, _T("Shapes (*.arrShapes)|*.arrShapes|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		arrShapes.Serialize(ar);
		ar.Close();
		file.Close();
	}
}

// load button
void CMFCprojectDlg::OnBnClickedButton2()
{
	// TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".arrShapes"), NULL, 0, _T("Shapes (*.arrShapes)|*.arrShapes|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		arrShapes.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}

//redo button
void CMFCprojectDlg::OnBnClickedButton3()
{
	if (!oldshapeArr.IsEmpty())
	{
		arrShapes.Add(oldshapeArr[oldshapeArr.GetSize() - 1]);
		oldshapeArr.RemoveAt(oldshapeArr.GetSize() - 1);
		Invalidate();
	}
}

//undo button
void CMFCprojectDlg::OnBnClickedButton4()
{
	if (!arrShapes.IsEmpty())
	{
		oldshapeArr.Add(arrShapes[arrShapes.GetSize() - 1]);
		arrShapes.RemoveAt(arrShapes.GetSize() - 1);
		Invalidate();
	}
}

//choose color button
void CMFCprojectDlg::OnBnClickedButton5()
{
	CMFCColorDialog CMFC;
	CMFC.DoModal();
	curColor = CMFC.GetColor();
}

//"new" button
void CMFCprojectDlg::OnBnClickedButton6()
{
	arrShapes.RemoveAll();
	Invalidate();
	isPressed = false;
	UpdateData(true);
}

//Pen types
void CMFCprojectDlg::OnBnClickedButton8(){
	PenType = PS_SOLID;
	Invalidate();
}

void CMFCprojectDlg::OnBnClickedButton9()
{
	PenType = PS_DASH;
	Invalidate();
}

void CMFCprojectDlg::OnBnClickedButton10()
{
	PenType = PS_DOT;
	Invalidate();
}

void CMFCprojectDlg::OnBnClickedButton11()
{
	PenType = PS_DASHDOT;
	Invalidate();
}

void CMFCprojectDlg::OnBnClickedButton12()
{
	PenType = PS_DASHDOTDOT;
	Invalidate();
}
//end pen types

//choose pentype (cases)
void CMFCprojectDlg::OnCbnSelchangeCombo1()
{
	int index = PehTypeBotton.GetCurSel();
	//PenSize = 1;

	switch (index)
	{
	case 1:
	{
		PenSize = 1;
		break;
	}
	case 2:
	{
		PenSize = 4;
		break;
	}
	case 3:
	{
		PenSize = 7;
		break;
	}
	case 4:
	{
		PenSize = 9;
		break;
	}
	case 5:
	{
		PenSize = 12;
		break;
	}
	//default: PenSize=1;
	}
}

//color something
HBRUSH CMFCprojectDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	return (HBRUSH)GetStockObject(WHITE_BRUSH);
}

//cancel button
void CMFCprojectDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}