#include "pch.h"
#include "HexagonalC.h"

IMPLEMENT_SERIAL(HexagonalC, Shape, 1)

//Hexagonal constructor that inherits from shape 
HexagonalC :: HexagonalC(CPoint p1, CPoint p2, COLORREF curColor) : Shape(p1, p2, bgColor) {
}

HexagonalC :: HexagonalC() {}


//Hexagonal draw function 

void HexagonalC::Draw(CDC* dc) const
{
	CPoint hexagonalPoints[6];

	hexagonalPoints[0].SetPoint(P1.x, P2.y);
	hexagonalPoints[1].SetPoint(P2.x, P2.y);
	hexagonalPoints[2].SetPoint(P2.x + (P2.x - P1.x), (P2.y + P1.y) * (0.5));
	hexagonalPoints[3].SetPoint(P2.x, P1.y);
	hexagonalPoints[4].SetPoint(P1.x, P1.y);
	hexagonalPoints[5].SetPoint(P1.x - (P2.x - P1.x), (P2.y + P1.y) * (0.5));

	dc->Polygon(hexagonalPoints, 6);
}

bool HexagonalC::inShape(CPoint p)
{
	int minX = P1.x < (P1.x - (P2.x - P1.x)) ? P1.x : (P1.x - (P2.x - P1.x));
	int maxX = P2.x + (P2.x - P1.x) > P2.x ? P2.x + (P2.x - P1.x) : P2.x;
	int minY = P1.y < P2.y ? P1.y : P2.y;
	int maxY = P1.y > P2.y ? P1.y : P2.y;

	if (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY)) {
		return true;
	}
	return false;
}