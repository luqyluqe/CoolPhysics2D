#include "Rectangle.h"
#include <math.h>

BEGIN_NAMESPACE_COOLPHYSICS2D

Rectangle::Rectangle(double x,double y,double width,double height):_x(x),_y(y),_width(width),_height(height){}

double Rectangle::x()const
{
    return _x;
}
double Rectangle::width()const
{
    return _width;
}
double Rectangle::y()const
{
    return _y;
}
double Rectangle::height()const
{
    return _height;
}

bool Rectangle::contain(const Vector& point)const
{
    double x=point.x();
    double y=point.y();
    if (x>_x&&x<_width&&y>_y&&y<_height) {
        return true;
    }
    return false;
}

bool Rectangle::overlap(const Circle &circle)const
{
    double x=circle.center().x();
    double y=circle.center().y();
    double r=circle.radius();
    if (x+r<_x||x-r>_x+_width||y+r<_y||y-r>_y+_height) {
        return false;
    }
    return true;
}

double Rectangle::overlapArea(const Circle &circle)const
{
    if (!overlap(circle)) {
        return 0;
    }
    double r=circle.radius();
    double x=circle.center().x();
    double y=circle.center().y();
    double d;
    if (x-r<_x) {
        d=_x-x;
    }else if (x+r>_x+_width) {
        d=x-(_x+_width);
    }else if (y-r<_y) {
        d=_y-y;
    }else if (y+r>_y+_height) {
        d=(_y+_height)-y;
    }else{
        return circle.area();
    }
    double rad=acos(d/r);
    double section=circle.area()*rad/M_PI;
    double triangle=r*d*sin(rad);
    if (contain(circle.center())) {
        return section+triangle;
    }else{
        return section-triangle;
    }
}

END_NAMESPACE_COOLPHYSICS2D