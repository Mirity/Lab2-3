#pragma once
#include "Figure.h"
#include <stdexcept>
#include <cmath>   


int Figure::GetLength(const Point& point1, const Point& point2) const
{
	int length = sqrt(abs(point1.x - point2.x) * abs(point1.x - point2.x) + abs(point1.y - point2.y) * abs(point1.y - point2.y));
	return length;
}
