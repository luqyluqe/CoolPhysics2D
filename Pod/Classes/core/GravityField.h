#ifndef COOLPHYSICS2D_GRAVITYFIELD_H
#define COOLPHYSICS2D_GRAVITYFIELD_H

#include "config.h"
#include "Field.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class GravityField:public Field
{
public:
    GravityField(const Rectangle& range,const Vector& gravity);
    ~GravityField();
    virtual void actOn(Particle& particle)const;
    
    //Accessor
    const Vector& gravity()const;
private:
    Vector _gravity;
};

END_NAMESPACE_COOLPHYSICS2D

#endif