#pragma once
#include "Rectangle.h"
#include <stdexcept>
using std::logic_error;

Rectangle::Rectangle(Point* cords)
{
	memcpy(_cords, cords, COUNT_OF_SIDES_REC * sizeof(Point));

	if (RightRec()==false)
	{
		throw logic_error("WRONG_RECTANGLE");
	}
}

bool Rectangle::RightRec() const
{
	int side1 = GetLength(_cords[0], _cords[1]);
	int side2 = GetLength(_cords[3], _cords[2]);
	int side3 = GetLength(_cords[0], _cords[3]);
	int side4 = GetLength(_cords[1], _cords[2]);

	if (side1 == side2 && side3 == side4 && side1 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Rectangle::Area() const
{
	return GetLength(_cords[0], _cords[1]) * GetLength(_cords[1], _cords[2]);
}

void Rectangle::Move(const char route, const int scale)
{
	switch (route)
	{
	case 'r':
		for (int i = 0; i < COUNT_OF_SIDES_REC; i++)
		{
			_cords[i].x += scale;
		}
		break;
	case 'l':
		for (int i = 0; i < COUNT_OF_SIDES_REC; i++)
		{
			_cords[i].x -= scale;
		}
		break;
	case 'd':
		for (int i = 0; i < COUNT_OF_SIDES_REC; i++)
		{
			_cords[i].y -= scale;
		}
		break;
	case'u':
		for (int i = 0; i < COUNT_OF_SIDES_REC; i++)
		{
			_cords[i].y += scale;
		}
		break;
	}
}


string Rectangle::ToString() const
{
	std::string result = "";
	for (int i = 0; i < COUNT_OF_SIDES_REC; i++)
	{
		result += std::to_string(i) + " - " + "( ";
		result += std::to_string(_cords[i].x);
		result += ", ";
		result += std::to_string(_cords[i].y);
		result += " )\n";
	}
	return result;
}

Point Rectangle::CenterGravity() const
{
	Point centerGravity;

	centerGravity.x = _cords[0].x + (_cords[1].x - _cords[0].x) / 2;
	centerGravity.y = _cords[0].y + (_cords[0].y - _cords[3].y) / 2;

	return centerGravity;
}

int Rectangle::Perimeter() const
{
	return(GetLength(_cords[0], _cords[1]) + GetLength(_cords[1], _cords[2]))*2;
}
