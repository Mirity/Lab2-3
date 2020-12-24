#include "Factory.h"


Figure* Factory::createFigure(Point* cords, int count) 
{
    switch (count)
    {
    case 4:
        return new Rectangle(cords);
        break;
    case 5:
        return new Pentagon(cords);
        break;
    default:
        throw logic_error("WRONG_FIGURE");
    }
    
}
