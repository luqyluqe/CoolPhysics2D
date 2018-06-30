#ifndef COOLPHYSICS2D_CENTRIPETALGRAVITYFIELD_H
#define COOLPHYSICS2D_CENTRIPETALGRAVITYFIELD_H

#include "AttachableField.hpp"

BEGIN_NAMESPACE_COOLPHYSICS2D

class CentripetalGravityField:public AttachableField
{
public:
    CentripetalGravityField(const Rectangle& range,const Vector& center,double gravity);
    virtual ~CentripetalGravityField();
    virtual void actOn(Particle& particle)const;
    virtual void attachTo(const Particle* particle);
private:
    double _gravity;
    Vector _center;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
