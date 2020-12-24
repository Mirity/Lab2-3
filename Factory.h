#include "Pentagon.h"
#include "Rectangle.h"
#include <stdexcept>
using std::logic_error;

class Factory
{
public:
    Figure* createFigure(Point* cords, int count);
    virtual ~Factory() {}
};

