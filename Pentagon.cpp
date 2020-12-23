#pragma once
#include "Pentagon.h"
#include <stdexcept>


int Pentagon::Area() const
{
	int area = 0;
	for (int i = 0; i < COUNT_OF_SIDES_PENT-1; i++)
	{
		area += (_cords[i + 1].y + _cords[i].y) * (_cords[i + 1].x - _cords[i].x);
	}
	return abs(area);
}

void Pentagon::Move(const char route, const int scale)
{
	switch (route)
	{
	case 'r':
		for (int i = 0; i < COUNT_OF_SIDES_PENT; i++)
		{
			_cords[i].x += scale;
		}
		break;
	case 'l':
		for (int i = 0; i < COUNT_OF_SIDES_PENT; i++)
		{
			_cords[i].x -= scale;
		}
		break;
	case 'd':
		for (int i = 0; i < COUNT_OF_SIDES_PENT; i++)
		{
			_cords[i].y -= scale;
		}
		break;
	case'u':
		for (int i = 0; i < COUNT_OF_SIDES_PENT; i++)
		{
			_cords[i].y += scale;
		}
		break;
	}
}



int Pentagon::Perimeter() const
{
	int per = 0;
	for (int i = 0; i < COUNT_OF_SIDES_PENT-1; i++)
	{
		per+= GetLength(_cords[i], _cords[i+1]);
	}
	return per;
}
string Pentagon::ToString() const
{
	std::string result = "";
	for (int i = 0; i < COUNT_OF_SIDES_PENT; i++)
	{
		result += std::to_string(i) + " - " + "( ";
		result += std::to_string(_cords[i].x);
		result += ", ";
		result += std::to_string(_cords[i].y);
		result += " )\n";
	}
	return result;
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

	centerGravity.x = (centerOfTriangle1.x * areaOfTriangle1 + centerOfTriangle2.x * areaOfTriangle2 + centerOfTriangle3.x * areaOfTriangle3)/(areaOfTriangle1 + areaOfTriangle2 + areaOfTriangle3);
	centerGravity.y = (centerOfTriangle1.y * areaOfTriangle1 + centerOfTriangle2.y * areaOfTriangle2 + centerOfTriangle3.y * areaOfTriangle3) / (areaOfTriangle1 + areaOfTriangle2 + areaOfTriangle3);
	
	return centerGravity;
}