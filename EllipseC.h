#pragma once
#include "Shape.h"

//Ellipse that inherits a Shape

class EllipseC : public Shape {
	//DECLARE_SERIAL generates the C++ header code necessary for a CObject-derived class
	//that can be serialized. Serialization is the process of writing or reading the contents
	//of an object to and from a file.
	DECLARE_SERIAL(EllipseC)

public:
	//constructors
	EllipseC() {}
	EllipseC(CPoint p1, CPoint p2, COLORREF curColor);

	//dis
	EllipseC::~EllipseC(void) {}

	//function
	void Draw(CDC* dc) const;
};

