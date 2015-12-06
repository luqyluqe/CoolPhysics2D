#ifndef COOLPHYSICS2D_CENTRIPETALGRAVITYFIELD_H
#define COOLPHYSICS2D_CENTRIPETALGRAVITYFIELD_H

#include "config.h"
#include "Field.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class CentripetalGravityField:public Field
{
public:
    CentripetalGravityField(const Rectangle& range,const Vector& position,double gravity);
    virtual ~CentripetalGravityField();
    virtual void actOn(Particle& particle)const;
private:
    double _gravity;
    Vector _position;
};

END_NAMESPACE_COOLPHYSICS2D

#endif