#include "Pentagon.h"
#include "Rectangle.h"

class Factory
{
public:
    virtual Figure* createFigure(Point* cords) = 0;
    virtual ~Factory() {}
};

class RectangleFactory : public Factory
{
public:
    Figure* createFigure(Point* cords) override;
};

class PentagonFactory : public Factory
{
public:
    Figure* createFigure(Point* cords) override;
};