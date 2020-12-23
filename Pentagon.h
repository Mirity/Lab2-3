#pragma once
#include "Figure.h"

const int COUNT_OF_SIDES_PENT = 5;

class Pentagon : public Figure
{
public:

	virtual int Area() const override;
	virtual void Move(const char route, const int scale) override;
	virtual int Perimeter() const override;
	virtual Point CenterGravity() const override;
	virtual string ToString() const override;

private:
	Point _cords[COUNT_OF_SIDES_PENT];
	Point CenterOfTriangle(Point a, Point b, Point c) const;
	double AreaOfTriangle(Point a, Point b, Point c) const;
};