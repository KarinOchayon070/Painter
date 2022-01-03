#include "pch.h"
#include "TrapezeC.h"

IMPLEMENT_SERIAL(TrapezeC, Shape, 1)


TrapezeC :: TrapezeC(CPoint p1, CPoint p2, COLORREF curColor) : Shape(p1, p2, bgColor){}
TrapezeC::TrapezeC(void) {}

void TrapezeC::Draw(CDC* dc) const
{
	CPoint TrapezePoints[4];
	TrapezePoints[0].SetPoint(P1.x, P2.y);
	TrapezePoints[1].SetPoint(P2.x, P2.y);
	TrapezePoints[2].SetPoint((((P2.x - P1.x) * 3) / 4) + P1.x, P1.y);
	TrapezePoints[3].SetPoint((((P2.x - P1.x) * 1) / 4) + P1.x, P1.y);

	dc->Polygon(TrapezePoints, 4);
}

bool TrapezeC::inShape(CPoint p)
{
	int minX = P1.x < ((P2.x - P1.x) * 1 / 4) ? P1.x : ((P2.x - P1.x) * 1 / 4);
	int maxX = ((P2.x - P1.x) * 3 / 4) > P2.x ? ((P2.x - P1.x) * 3 / 4) : P2.x;
	int minY = P1.y < P2.y ? P1.y : P2.y;
	int maxY = P1.y > P2.y ? P1.y : P2.y;

	if (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY)) {
		return true;
	}
	return false;
}