// OpenningScreen.cpp
#include "pch.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "OpenningScreen.h"
#include "afxdialogex.h"

// OpenningScreen dialog

IMPLEMENT_DYNAMIC(OpenningScreen, CDialogEx)

OpenningScreen::OpenningScreen(CWnd* pParent /*=nullptr*/)
	: CDialogEx(OpenningScreen:: IDD, pParent)
{
	bgBmp.LoadBitmapW(IDB_BITMAP8);
}



OpenningScreen::~OpenningScreen()
{
}

void OpenningScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); DDX_Control(pDX, IDC_BUTTON1, StartBotton);
}


BEGIN_MESSAGE_MAP(OpenningScreen, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &OpenningScreen::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// OpenningScreen message handlers


void OpenningScreen::OnBnClickedButton1()
{
	this->OnCancel();
	CMFCprojectDlg a;
	a.DoModal();
}

void OpenningScreen::OnPaint()
{
	CPaintDC dc(this);
	CDC memDc; 
	memDc.CreateCompatibleDC(&dc);
	memDc.SelectObject(&bgBmp);
	dc.BitBlt(0, 0, 2750, 600, &memDc, 0, 0, SRCCOPY);
	CDialogEx::OnPaint();
}

BOOL OpenningScreen::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	StartBotton.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP18))); // set the start icon
	return TRUE;
}

