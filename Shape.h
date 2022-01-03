#pragma once
#include "pch.h"

// Main shape!	All the others figs is inherit from this Shape. 
class Shape: public CObject {

public:
	DECLARE_SERIAL(Shape)
	COLORREF bgColor;

	//constrictors
	Shape() {}
	Shape(CPoint p1, CPoint p2, COLORREF bgColor);
	
	//dis
	Shape::~Shape(void) {}

	//functions
	void Serialize(CArchive& ar);
	virtual void Draw(CDC* dc) const{
		CPen pen(ShapePenType, ShapePenSize, bgColor);
		CBrush brush(bgColor);
		CBrush* oldBrush = dc->SelectObject(&brush);
		CPen* oldPen = dc->SelectObject(&pen);
		Draw(dc);
		dc->SelectObject(oldPen);
		dc->SelectObject(oldBrush);
	}
	CPoint getP1() const { 
		return P1;
	}
	CPoint getP2() const{
		return P2;
	}
	void setStart(CPoint point) {
		P1 = point;
	}
	void setEnd(CPoint point) {
		P2 = point;
	}
	int getShapePenType() const { return ShapePenType; }
	void setShapePenType(int c) { ShapePenType = c; }
	int getShapePenSize() const { return ShapePenSize; }
	void setShapePenSize(int c) { ShapePenSize = c; }
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool inShape(CPoint &P);
	virtual void Shift(int dx, int dy);
	void setBg(COLORREF c) { bgColor = c; }
	void setP(COLORREF c) { bgColor = c; }
	void SetID(int ID);
	int GetID() const;
	COLORREF getP() const { return bgColor; }
	COLORREF getBgColor();
	void setBgColor(COLORREF bgColor1);
	Shape& operator=(const Shape& s1);


protected:
	CPoint P1, P2;
	int typeID;
	int ShapePenType, ShapePenSize;
};
