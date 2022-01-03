#pragma once
#include "Shape.h"

//Hexagonal that inherits from Shape
class HexagonalC : public Shape{

public:
	//DECLARE_SERIAL generates the C++ header code necessary for a CObject-derived class
	//that can be serialized. Serialization is the process of writing or reading the contents
	//of an object to and from a file.
	DECLARE_SERIAL(HexagonalC)

	//constructors
	HexagonalC();
	HexagonalC(CPoint p1, CPoint p2, COLORREF curColor);

	//dis
	HexagonalC::~HexagonalC(void) {}

	//functions
	void Draw(CDC* dc) const;
	bool inShape(CPoint p);
};