#include "pch.h"
#include "TriangleC.h"

IMPLEMENT_SERIAL(TriangleC, Shape, 1)

TriangleC :: TriangleC(CPoint p1, CPoint p2, COLORREF curColor) : Shape(p1, p2, bgColor) {

}

//TriangleC::TriangleC(void) {
//}
//

void TriangleC::Draw(CDC* dc) const
{
    CPoint TPoints[3];
    TPoints[0].SetPoint(P1.x, P2.y);
    TPoints[1].SetPoint(P2.x, P2.y);
    TPoints[2].SetPoint((P1.x + P2.x) / 2, P1.y);
    dc->Polygon(TPoints, 3);
}

bool TriangleC::inShape(CPoint p)
{
    int minX = P1.x < P2.x ? P1.x : P2.x;
    int maxX = P1.x > P2.x ? P1.x : P2.x;
    int minY = P1.y < P2.y ? P1.y : P2.y;
    int maxY = P1.y > P2.y ? P1.y : P2.y;

    if (!(p.x < minX  || p.x > maxX ||  p.y < minY || p.y > maxY))
        return true;
    return false;
}