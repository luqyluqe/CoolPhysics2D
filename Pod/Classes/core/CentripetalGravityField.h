#ifndef COOLPHYSICS2D_CENTRIPETALGRAVITYFIELD_H
#define COOLPHYSICS2D_CENTRIPETALGRAVITYFIELD_H

#include "AttachableField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class CentripetalGravityField:public AttachableField
{
public:
    CentripetalGravityField(const Rectangle& range,const Particle* charge,double gravity);
    virtual ~CentripetalGravityField();
    virtual void actOn(Particle& particle)const;
private:
    double _gravity;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
