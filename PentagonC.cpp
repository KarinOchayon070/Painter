#include "pch.h"
#include "PentagonC.h"

IMPLEMENT_SERIAL(PentagonC, Shape, 1)

//Pentagon constructor that inherits from shape 
PentagonC::PentagonC(CPoint p1, CPoint p2, COLORREF curColor) : Shape(p1, p2, bgColor) {
}
PentagonC::PentagonC() {
}

void PentagonC::Draw(CDC* dc) const
{
	CPoint pentagonPoints[5];

	pentagonPoints[0].SetPoint(P1.x, P2.y);
	pentagonPoints[2].SetPoint(P2.x + (P2.x - P1.x), (P2.y + P1.y) * 0.5);
	pentagonPoints[1].SetPoint(P2.x, P2.y);
	pentagonPoints[3].SetPoint(P2.x, P1.y);
	pentagonPoints[4].SetPoint(P1.x, P1.y);

	dc->Polygon(pentagonPoints, 5);
}

bool PentagonC::inShape(CPoint p)
{
	int minX = P1.x < P2.x ? P1.x : P2.x;
	int maxX = P1.x > (P2.x + (P2.x - P1.x)) ? P1.x : (P2.x + (P2.x - P1.x));
	int minY = P1.y < P2.y ? P1.y : P2.y;
	int maxY = P1.y > P2.y ? P1.y : P2.y;

	if (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY))
		return true;
	return false;
}