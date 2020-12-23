#include "Figure.h"


class Rectangle : public Figure
{
public:
	Rectangle(Point* cords);
	double Area() const override;
	Point CenterGravity() const override;

private:
	bool RightRec() const;
};