#include "Color.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

Color Color::operator*(float number)const
{
    return Color(RED*number, GREEN*number, BLUE*number, ALPHA*number);
}

void Color::operator*=(float number)
{
    RED*=number;
    GREEN*=number;
    BLUE*=number;
    ALPHA*=number;
}

Color Color::redColor(1,0,0,1);
Color Color::greenColor(0,1,0,1);
Color Color::blueColor(0,0,1,1);
Color Color::whiteColor(1,1,1,1);
Color Color::blackColor(0,0,0,1);
Color Color::yellowColor(1,1,0,1);

END_NAMESPACE_COOLPHYSICS2D
