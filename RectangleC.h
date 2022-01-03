#pragma once
#include "Shape.h"

//Rectangle that inherits a Shape
class RectangleC : public Shape {
	   
public:
	//DECLARE_SERIAL generates the C++ header code necessary for a CObject-derived class
	//that can be serialized. Serialization is the process of writing or reading the contents
	//of an object to and from a file.
	DECLARE_SERIAL(RectangleC)

	//constructors
	RectangleC() {}
	RectangleC(CPoint p1, CPoint end, COLORREF curColor);

	//dis
	RectangleC::~RectangleC(void) {}

	//function
	void Draw(CDC* dc) const;
};
