#include "pch.h"  //Must be FIRST!
#include "Shape.h"

IMPLEMENT_SERIAL(Shape, CObject, 1)

Shape::Shape(CPoint p1, CPoint p2, COLORREF bgColor) : P1(p1), P2(p2), bgColor(bgColor) {
}

void Shape::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << bgColor;
		ar << ShapePenSize;
		ar << ShapePenType;
	}
	else // Loading, not storing
	{
		ar >> P1;
		ar >> P2;
		ar >> bgColor;
		ar >> ShapePenSize;
		ar >> ShapePenType;
	}
}

Shape& Shape::operator=(const Shape& s1){
	(*this).P1 = s1.P1;
	(*this).P2 = s1.P2;
	(*this).bgColor = s1.bgColor;
	return *this;
}

bool Shape::inShape(CPoint &P){
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}

void Shape::Shift(int dx, int dy)
{
	P1 = P1 + CPoint(dx, dy);
	P2 = P2 + CPoint(dx, dy);
}

COLORREF Shape::getBgColor(){
	return bgColor;
}

void Shape::setBgColor(COLORREF bgColor1){
	bgColor = bgColor1;
}

void  Shape::SetID(int ID)
{
	this->typeID = ID;
}

int Shape::GetID() const
{
	return this->typeID;
}