#ifndef COOLPHYSICS2D_RECTANGLE_H
#define COOLPHYSICS2D_RECTANGLE_H

#include "config.h"
#include "Vector.h"
#include "Circle.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class Rectangle
{
public:
    //Constructor
    Rectangle(double x,double y,double width,double height);
    //Accessor
    double x()const;
    double y()const;
    double width()const;
    double height()const;
    
    //Judgement
    bool contain(const Vector& point)const;
    bool overlap(const Circle& circle)const;
    
    //Arithmetic
    double overlapArea(const Circle& cirle)const;
    
private:
    double _x;
    double _y;
    double _width;
    double _height;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
