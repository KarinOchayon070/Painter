#pragma once

#include "MFCprojectDlg.h"
#include "resource.h"
#include "afxwin.h"
#include "afxdialogex.h"

// OpenningScreen dialog

class OpenningScreen : public CDialogEx
{
	DECLARE_DYNAMIC(OpenningScreen)

public:
	OpenningScreen(CWnd* pParent = NULL);   // standard constructor
	virtual ~OpenningScreen();

// Dialog Data AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CButton StartBotton;
	CBitmap bgBmp;
};
