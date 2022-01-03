#include "pch.h" 
#include "RectangleC.h"


IMPLEMENT_SERIAL(RectangleC, CObject, 1)

//Rectangle constructor that inherits from shape 
RectangleC :: RectangleC(CPoint p1, CPoint p2, COLORREF curColor) : Shape(p1,p2, bgColor)
{
}

void RectangleC::Draw(CDC* dc) const{

	dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
}

