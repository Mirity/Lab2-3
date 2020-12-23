#pragma once
#include <iostream>
#include "Point.h"
#include<string>
using std::string;

class Figure
{
public:
	virtual ~Figure() = default;

	virtual string ToString() const = 0;
	virtual void Move(const char route, const int scale);
	virtual int Area() const = 0;
	virtual int Perimeter() const = 0;
	virtual Point CenterGravity() const = 0;

protected:
	int GetLength(const Point& point1, const Point& point2) const;
	Point* _cords;
};