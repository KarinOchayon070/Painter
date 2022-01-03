#pragma once
#include "Shape.h"

//Pentagon that inherits a Shape
class PentagonC : public Shape{

public:
	//DECLARE_SERIAL generates the C++ header code necessary for a CObject-derived class
	//that can be serialized. Serialization is the process of writing or reading the contents
	//of an object to and from a file.
	DECLARE_SERIAL(PentagonC)

	//constructors
	PentagonC(CPoint p1, CPoint p2, COLORREF curColor);
	PentagonC();

	//dis
	PentagonC::~PentagonC(void) {}

	//functions
	void Draw(CDC* dc) const;
	bool inShape(CPoint p);
};