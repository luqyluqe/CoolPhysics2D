#include "Circle.h"
#include <math.h>

BEGIN_NAMESPACE_COOLPHYSICS2D

Circle::Circle(const Vector& center,double radius):_center(center),_radius(radius){}

const Vector& Circle::center()const
{
    return _center;
}
double Circle::radius()const
{
    return _radius;
}

double Circle::area()const
{
    return M_PI*_radius*_radius;
}

END_NAMESPACE_COOLPHYSICS2D