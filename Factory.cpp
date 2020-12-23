#include "Factory.h"

Figure* RectangleFactory::createFigure(Point* cords) 
{
    return new Rectangle(cords);
}

Figure* PentagonFactory::createFigure(Point* cords)
{
    return new Pentagon(cords);
}