#include "Figure.h"


class Pentagon : public Figure
{
public:
	Pentagon(Point* cords);
	double Area() const override;
	Point CenterGravity() const override;

private:
	Point CenterOfTriangle(Point a, Point b, Point c) const;
	double AreaOfTriangle(Point a, Point b, Point c) const;
};