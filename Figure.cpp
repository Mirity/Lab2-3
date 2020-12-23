#pragma once
#include "Figure.h"
#include <stdexcept>
#include <cmath>   


double Figure::GetLength(const Point& point1, const Point& point2) const
{
	double length = sqrt(abs(point1.x - point2.x) * abs(point1.x - point2.x) + abs(point1.y - point2.y) * abs(point1.y - point2.y));
	return length;
}
void Figure::Move(const char route, const int scale)
{
	switch (route)
	{
	case 'r':
		for (int i = 0; i < _countSides; i++)
		{
			_cords[i].x += scale;
		}
		break;
	case 'l':
		for (int i = 0; i < _countSides; i++)
		{
			_cords[i].x -= scale;
		}
		break;
	case 'd':
		for (int i = 0; i < _countSides; i++)
		{
			_cords[i].y -= scale;
		}
		break;
	case'u':
		for (int i = 0; i < _countSides; i++)
		{
			_cords[i].y += scale;
		}
		break;
	}
}

string Figure::ToString() const
{
	std::string result = "";
	for (int i = 0; i < _countSides; i++)
	{
		result += std::to_string(i) + " - " + "( ";
		result += std::to_string(_cords[i].x);
		result += ", ";
		result += std::to_string(_cords[i].y);
		result += " )\n";
	}
	return result;
}

double Figure::Perimeter() const
{
	double per = 0;
	for (int i = 1; i < _countSides; i++)
	{
		per += GetLength(_cords[i], _cords[i - 1]);
	}
	per += GetLength(_cords[_countSides - 1], _cords[0]);
	return per;
}
