#include "pch.h"
#include "LineC.h"

IMPLEMENT_SERIAL(LineC, Shape, 1)

//Line constructor that inherits from shape 
LineC :: LineC(CPoint p1, CPoint p2, COLORREF curColor) : Shape(p1, p2, bgColor) {
}

//LineC::LineC(void) {}

//Line draw function 
void LineC::Draw(CDC* dc) const
{
	CPen p, *oldP;
	p.CreatePen(ShapePenType, ShapePenSize, bgColor);
	oldP = dc->SelectObject(&p);
	dc->MoveTo(P1.x, P1.y);
	dc->LineTo(P2.x, P2.y);
	dc->SelectObject(oldP);
}

bool LineC::inShape(CPoint p)
{
	int x = P1.x - P2.x;
	int y = P1.y - P2.y;
	int minX = P1.x < P2.x ? P1.x : P2.x;
	int maxX = P1.x > P2.x ? P1.x : P2.x;
	int minY = P1.y < P2.y ? P1.y : P2.y;
	int maxY = P1.y > P2.y ? P1.y : P2.y;

	double m = (double)y / (double)x;
	if ((p.y - P1.y - m * (p.x - P1.x)) - 7 && (p.y - P1.y - m * (p.x - P1.x) < 7) && (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY)))
		return true;
	return false;
}