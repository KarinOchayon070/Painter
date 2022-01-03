// MFCprojectDlg.h : header file


#pragma once
#include <stack>
#include <vector>
#include "AddShape.h"
#include "command.h"
#include "Shape.h"
#include "TriangleC.h" 
#include "RectangleC.h"
#include "EllipseC.h"
#include "LineC.h"
#include "TrapezeC.h"
#include "HexagonalC.h"
#include "PentagonC.h"
#include "OpenningScreen.h"


class CMFCprojectDlg : public CDialogEx
{
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	COLORREF curColor = RGB(255,255,255);
	CPoint start, end;
	bool isPressed = false;
	bool isRPressed = false;
	Shape* CurrenShape;
	CPoint RightClickP;
	CTypedPtrArray< CObArray, Shape*> arrShapes;
	CTypedPtrArray<CObArray, Shape*> oldshapeArr;
	int futureShapeKind = 1;
	int Id = 0;
	int PenType = 1;
	int PenSize = 1;
	CComboBox PehTypeBotton;
	CButton brush1;
	CButton brush2;
	CButton brush3;
	CButton brush4;
	CButton brush5;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	
	CButton colorchoose;
	CButton Thick;
	CButton undo;
	CButton redo;
	CButton newB;
	CButton load;
	CButton save;

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedCancel();
	

};
