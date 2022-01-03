#include "pch.h"
#include "AddShape.h"

AddShape::AddShape(CTypedPtrArray<CObArray, Shape*>& Shapes, Shape* s) :
	Shapes(Shapes), s(s) {}

AddShape::~AddShape(void) {}

void AddShape::perform()
{
	Shapes.Add(s);
}

void AddShape::rollback()
{
	for (int i = 0; i < Shapes.GetSize(); ++i)
	{
		if (Shapes[i] == s)
		{
			Shapes.RemoveAt(i);
			return;
		}
	}
}