#ifndef COOLPHYSICS2D_BUOYANCYFIELD_H
#define COOLPHYSICS2D_BUOYANCYFIELD_H

#include "config.h"
#include "Field.h"
#include "GravityField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class BuoyancyField:public Field
{
public:
    BuoyancyField(Rectangle range,const GravityField& gravityField,double density);
    virtual void actOn(Particle& particle)const;
private:
    Vector _gravity;
    double _density;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
