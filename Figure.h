#pragma once
#include <iostream>
#include "Point.h"
#include<string>
using std::string;

class Figure
{
public:
	Figure() = default;
	~Figure() = default;
	string ToString() const;
	void Move(const char route, const int scale);
	double Perimeter() const;
	virtual double Area() const = 0;
	virtual Point CenterGravity() const = 0;

protected:
	double GetLength(const Point& point1, const Point& point2) const;
	Point* _cords;
	int _countSides = 0;
};
