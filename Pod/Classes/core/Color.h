#ifndef COOLPHYSICS2D_COLOR_H
#define COOLPHYSICS2D_COLOR_H

#include "config.h"


BEGIN_NAMESPACE_COOLPHYSICS2D

class Color
{
public:
    Color(float r,float g,float b,float a):RED(r),GREEN(g),BLUE(b),ALPHA(a){}
    
    static Color redColor;
    static Color greenColor;
    static Color blueColor;
    static Color whiteColor;
    static Color blackColor;
    
    float RED;
    float GREEN;
    float BLUE;
    float ALPHA;
};



END_NAMESPACE_COOLPHYSICS2D

#endif