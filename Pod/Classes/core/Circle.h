#ifndef COOLPHYSICS2D_CIRCLE_H
#define COOLPHYSICS2D_CIRCLE_H

#include "config.h"
#include "Vector.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class Circle
{
public:
    //Constructor
    Circle(const Vector& center,double radius);
    
    //Accessor
    const Vector& center()const;
    double radius()const;
    
    //Property
    double area()const;
private:
    Vector _center;
    double _radius;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
