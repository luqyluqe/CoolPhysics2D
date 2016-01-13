#include "BuoyancyField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

BuoyancyField::BuoyancyField(Rectangle range,const GravityField& gravitiField,double density):Field(range),_gravity(gravitiField.gravity()),_density(density){}

void BuoyancyField::actOn(Particle &particle)const
{
    if (!_range.overlap(particle.range())) {
        return;
    }
    double area=_range.overlapArea(particle.range());
    Vector buoyancy=_gravity*(-1)*_density*area/particle.mass();
    particle.acceleration()+=buoyancy;
}

END_NAMESPACE_COOLPHYSICS2D