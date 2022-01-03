#include "pch.h"
#include "EllipseC.h"


IMPLEMENT_SERIAL(EllipseC, CObject, 1)

//Ellipse constructor that inherits from shape 
EllipseC::EllipseC(CPoint p1, CPoint p2, COLORREF curColor) :Shape(p1, p2, bgColor) {
}

//Ellipse draw function 
void EllipseC::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}

