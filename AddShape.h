#pragma once
#include "command.h"
#include "Shape.h"

class AddShape : public command
{
public:
	AddShape(CTypedPtrArray<CObArray, Shape*>& Shapes, Shape* s);
	~AddShape(void);
	void perform();
	void rollback();
private:
	CTypedPtrArray<CObArray, Shape*>& Shapes;
	Shape* s;
};

