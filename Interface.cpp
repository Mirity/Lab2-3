#define COUNT_OF_CASES 10
#include <iostream>
#include "Interface.h"
using std::cin;
using std::cout;

Interface::~Interface()
{
	delete[] _names;
	delete[] _cases;
}

Interface::Interface()
{
	_names = new string[COUNT_OF_CASES];
	_cases = new Figure* [COUNT_OF_CASES];
} 

int Interface::GetIndex(const std::string name) const
{
	for (int i = 0; i < COUNT_OF_CASES; i++)
	{
		if (name == _names[i])
		{
			return i;
		}
	}
	return -1;
}


void Interface::PrintFigure() const
{
	std::string name;
	std::cout << "Enter name of figure to print\n>> ";
	std::cin >> name;
	int index = GetIndex(name);
	if (index != -1)
	{
		std::cout << _cases[index]->ToString();
	}
	else
	{
		std::cout << "Wrong name\n";
	}
}

void Interface::PrintAllFigure() const
{
	for (int i = 0; i < COUNT_OF_CASES; i++)
	{
		if (_names[i].empty())
		{
			std::cout << i + 1 << ":\n" << "Empty\n\n";
		}
		else
		{
			std::cout << i + 1 << ":\n";
			std::cout << "Name:" << _names[i] << '\n';
			std::cout << _cases[i]->ToString();
			std::cout << "\n\n";
		}

	}
}

void Interface::Area() const
{
	std::string name;
	std::cout << "Enter name of figure to get area\n>> ";
	std::cin >> name;
	if (GetIndex(name) != -1)
	{
		std::cout << _cases[GetIndex(name)]->Area() << "\n";
	}
	else
	{
		std::cout << "Wrong name\n";
	}

}

void Interface::Move() const
{
	std::string name;
	char route;
	int scale = 0;
	bool correct1 = true;
	bool correct = true;
	std::cout << "Enter name of figure to move\n>> ";
	std::cin >> name;
	if (GetIndex(name) != -1)
	{
		std::cout << "Enter route\n r=right\n l=left\n u=up\n d=down\n";
		std::cin >> route;

		while (correct)
		{
			if (route == 'r' || route == 'l' || route == 'u' || route == 'd')
			{
				correct = false;
			}
			else
			{
				std::cout << "Enter correct route\n";
				std::cin >> route;
			}
		}

		std::cout << "Enter scale\n";
		std::cin >> scale;

		while (correct1)
		{
			if (scale >= 0)
			{
				correct1 = false;
				_cases[GetIndex(name)]->Move(route, scale);
			}
			else
			{
				std::cout << "Enter positive scale\n";
				std::cin >> scale;
			}
		}

	}
	else
	{
		std::cout << "Wrong name\n";
	}
}
void Interface::DelFigure() const
{
	std::string choice;
	std::string name;
	std::cout << "Enter name of figure to delete\n>> ";
	std::cin >> name;
	std::cout << "Are you sure?Y|N\n";
	if (choice == "Y" || choice == "y")
	{
		DeleteFigure(name);
		std::cout << "Complete\n";
	}
	if (choice == "N" || choice == "n")
	{
		std::cout << "Okay\n";
	}
	else
	{
		std::cout << choice << " is not a 'y' or 'n'\n";
	}
}

void Interface::DeleteFigure(const std::string name) const
{
	int index = GetIndex(name);

	if (index == -1)
	{
		std::cout << "Can't find figure with this name\n";
	}
	else
	{
		_names[index] = "";
		delete _cases[index];
		_cases[index] = nullptr;
	}
}

void Interface::CreateFigure() const
{
	Factory figureFactory;

	cout << "Enter name of figure:\n>> ";
	string name;
	cin >> name;

	int count;
	cout << "How many points are in your figure?\n>> ";
	cin >> count;
	
	

	bool isEnoughtSpace = false;
	int index;
	for (int i = 0; i < COUNT_OF_CASES && !isEnoughtSpace; i++)
	{
		if (_names[i].empty())
		{
			isEnoughtSpace = true;
			index = i;
		}
	}
	
	if (isEnoughtSpace)
	{
		try
		{
				Figure* newElement = nullptr;
				Point* points = new Point[count];
				cout << "Enter points:\n";
				for (int i = 0; i < count; i++)
				{
					cout << "\n" << i + 1 << ") x, y: \n>> ";
					cin >> points[i].x;
					cin >> points[i].y;
				}
				newElement = figureFactory.createFigure(points,count);
				delete[] points;
			
			_names[index] = name;
			_cases[index] = newElement;
			cout << "Complete!\n";
		}
		catch (const std::logic_error& src)
		{
			cout << src.what() << "\n";
			return;
		}
		
	}
	else
	{
		cout << "You don't have enought space, delete something\n";
	}
	
}

void Interface::GetCenter() const
{
	string name;
	cout << "Enter name of figure\n>> ";
	cin >> name;
	if (GetIndex(name) != -1)
	{
		Point center = _cases[GetIndex(name)]->CenterGravity();
		cout << "Center of this figure: x = " << center.x << " y = " << center.y << "\n";
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void Interface::GetPerimeter() const
{
	std::string name;
	std::cout << "Enter name of figure to get perimeter\n>> ";
	std::cin >> name;
	if (GetIndex(name) != -1)
	{
		std::cout << _cases[GetIndex(name)]->Perimeter() << "\n";
	}
	else
	{
		std::cout << "Wrong name\n";
	}
}
void Interface::Init() const
{
	bool flag = true;
	cout << "You can create 10 figures\n";
	while (flag)
	{
		int code;
		cout << "Enter \"3\" - Help\n";
		cout << ">> ";
		cin >> code;

		switch (code)
		{
		case 1:
			CreateFigure();
			break;
		case 2:
			DelFigure();
			break;
		case 3:
			Help();
			break;
		case 4:
			PrintAllFigure();
			break;
		case 5:
			PrintFigure();
			break;
		case 6:
			Area();
			break;
		case 7:
			Move();
			break;
		case 8:
			GetCenter();
			break;
		case 9:
			GetPerimeter();
			break;
		case 10:
			flag = false;
			break;
		}
	}
}
void Interface::Help() const
{
	cout << "\"1\" - Create new figure\n\"2\" - Delete figure\n\"3\" - Help\n\"4\" - Print all figures \n\"5\" - Print figure\n\
\"6\" - Area\n\"7\" - Move\n\"8\" - Get center\n\"9\" - Get perimeter\n\"10\" - Exit\n";
}