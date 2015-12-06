#include "DampingField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

DampingField::DampingField(const Rectangle& range,double damping):Field(range),_damping(damping){}

DampingField::~DampingField(){}

void DampingField::actOn(Particle& particle)const
{
    if (_range.overlap(particle.range())){
        particle._acceleration+=particle._velocity*_damping/particle._mass;
    }
}

END_NAMESPACE_COOLPHYSICS2D
