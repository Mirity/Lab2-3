#pragma once
#include "Figure.h"
#include "Factory.h"


class Interface
{
public:
	Interface();
	~Interface();

	void Init() const;
private:
	void CreateFigure() const;
	void DeleteFigure(const std::string name) const;
	void DelFigure() const;
	void Help() const;
	int GetIndex(const std::string name) const;
	void PrintFigure() const;
	void Area() const;
	void Move() const;
	void PrintAllFigure() const;
	void GetCenter() const;
	void GetPerimeter() const;

	std::string* _names = nullptr;
	Figure** _cases = nullptr;
};