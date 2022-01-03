#pragma once
#include "Shape.h"

//Line that inherits a Shape
class LineC : public Shape{

public:
	//DECLARE_SERIAL generates the C++ header code necessary for a CObject-derived class
	//that can be serialized. Serialization is the process of writing or reading the contents
	//of an object to and from a file.
	DECLARE_SERIAL(LineC)

	//constructors
	LineC(CPoint p1, CPoint p2, COLORREF curColor);
	LineC(){}

	//dis
	LineC::~LineC(void) {}

	//functions
	void Draw(CDC* dc) const;
	bool inShape(CPoint p);
};