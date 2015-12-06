#ifndef COOLPHYSICS2D_DAMPINGYFIELD_H
#define COOLPHYSICS2D_DAMPINGYFIELD_H

#include "Field.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class DampingField:public Field
{
public:
    DampingField(const Rectangle& range,double damping);
    virtual ~DampingField();
    virtual void actOn(Particle& particle)const;
private:
    double _damping;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
