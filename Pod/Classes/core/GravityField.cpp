#include "GravityField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

GravityField::GravityField(const Rectangle& range,const Vector& gravity):Field(range),_gravity(gravity){}

GravityField::~GravityField(){}

void GravityField::actOn(Particle& particle)const
{
    if (_range.overlap(particle.range())) {
        particle.acceleration()+=_gravity;
    }
}

const Vector& GravityField::gravity()const
{
    return _gravity;
}

END_NAMESPACE_COOLPHYSICS2D
