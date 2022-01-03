#pragma once
#include "Shape.h"

//Trapeze that inherits from Shape
class TrapezeC : public Shape{

public:
	//DECLARE_SERIAL generates the C++ header code necessary for a CObject-derived class
	//that can be serialized. Serialization is the process of writing or reading the contents
	//of an object to and from a file.
	DECLARE_SERIAL(TrapezeC)

	//constuctors
	TrapezeC(void);
	TrapezeC(CPoint p1, CPoint p2, COLORREF curColor);

	//dis
	TrapezeC::~TrapezeC(void) {}

	//functions
	void Draw(CDC* dc) const;
	bool inShape(CPoint p);
};

