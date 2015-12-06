#ifndef COOLPHYSICS2D_FIELD_H
#define COOLPHYSICS2D_FIELD_H

#include "config.h"
#include "Particle.h"
#include "Rectangle.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class Field
{
public:
    Field(const Rectangle& range);
    virtual ~Field();
    virtual void actOn(Particle& particle)const=0;
    void enable();
    void disable();
    bool enabled()const;
protected:
    Rectangle _range;
    bool _enabled;
};

END_NAMESPACE_COOLPHYSICS2D

#endif