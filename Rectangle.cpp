#pragma once
#include "Rectangle.h"
#include <stdexcept>
using std::logic_error;

Rectangle::Rectangle(Point* cords)
{
	_countSides = 4;

	_cords = new Point[_countSides];
	memcpy(_cords, cords, _countSides * sizeof(Point));

	if (RightRec() == false)
	{
		throw logic_error("WRONG_RECTANGLE");
	}


}

bool Rectangle::RightRec() const
{
	double side1 = GetLength(_cords[0], _cords[1]);
	double side2 = GetLength(_cords[3], _cords[2]);
	double side3 = GetLength(_cords[0], _cords[3]);
	double side4 = GetLength(_cords[1], _cords[2]);

	if (side1 == side2 && side3 == side4 && side1 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double Rectangle::Area() const
{
	return GetLength(_cords[0], _cords[1]) * GetLength(_cords[1], _cords[2]);
}

Point Rectangle::CenterGravity() const
{
	Point centerGravity;

	centerGravity.x = _cords[0].x + (_cords[1].x - _cords[0].x) / 2;
	centerGravity.y = _cords[0].y + (_cords[3].y - _cords[0].y) / 2;

	return centerGravity;
}


