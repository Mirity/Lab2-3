#pragma once
#include "Pentagon.h"
#include <stdexcept>

Pentagon::Pentagon(Point* cords)
{
	_countSides = 5;
	_cords = new Point[_countSides];
	memcpy(_cords, cords, _countSides * sizeof(Point));
}

double Pentagon::Area() const
{
	double area;
	double areaOfTriangle1 = AreaOfTriangle(_cords[0], _cords[1], _cords[2]);
	double areaOfTriangle2 = AreaOfTriangle(_cords[2], _cords[3], _cords[4]);
	double areaOfTriangle3 = AreaOfTriangle(_cords[0], _cords[4], _cords[2]);
	return area = areaOfTriangle1 + areaOfTriangle2 + areaOfTriangle3;;
}

Point Pentagon::CenterOfTriangle(Point  a, Point  b, Point  c) const
{
	Point result;
	result.x = (a.x + b.x + c.x) / 3;
	result.y = (a.y + b.y + c.y) / 3;
	return result;
}

double Pentagon::AreaOfTriangle(Point a, Point b, Point c) const
{
	return abs(0.5 * ((a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x)));
}


Point Pentagon::CenterGravity() const
{
	Point centerGravity;

	Point centerOfTriangle1 = CenterOfTriangle(_cords[0], _cords[1], _cords[2]);
	Point centerOfTriangle2 = CenterOfTriangle(_cords[2], _cords[3], _cords[4]);
	Point centerOfTriangle3 = CenterOfTriangle(_cords[0], _cords[4], _cords[2]);

	double areaOfTriangle1 = AreaOfTriangle(_cords[0], _cords[1], _cords[2]);
	double areaOfTriangle2 = AreaOfTriangle(_cords[2], _cords[3], _cords[4]);
	double areaOfTriangle3 = AreaOfTriangle(_cords[0], _cords[4], _cords[2]);

	centerGravity.x = (centerOfTriangle1.x * areaOfTriangle1 + centerOfTriangle2.x * areaOfTriangle2 + centerOfTriangle3.x * areaOfTriangle3) / (areaOfTriangle1 + areaOfTriangle2 + areaOfTriangle3);
	centerGravity.y = (centerOfTriangle1.y * areaOfTriangle1 + centerOfTriangle2.y * areaOfTriangle2 + centerOfTriangle3.y * areaOfTriangle3) / (areaOfTriangle1 + areaOfTriangle2 + areaOfTriangle3);

	return centerGravity;
}