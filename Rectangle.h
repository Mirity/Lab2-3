#pragma once
#include "Figure.h"

const int COUNT_OF_SIDES_REC = 4;

class Rectangle : public Figure
{
public:
	Rectangle(Point* cords);
	virtual void Move(const char route, const int scale) override;
	virtual int Area() const override;
	virtual int Perimeter() const override;
	virtual Point CenterGravity() const override;
	virtual string ToString() const override;

private:
	Point _cords[COUNT_OF_SIDES_REC];
	bool RightRec() const;
};