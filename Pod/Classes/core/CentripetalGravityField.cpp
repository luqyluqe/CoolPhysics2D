#include "CentripetalGravityField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

CentripetalGravityField::CentripetalGravityField(const Rectangle& range,const Vector& position,double gravity):Field(range),_position(position),_gravity(gravity){}

CentripetalGravityField::~CentripetalGravityField(){}

void CentripetalGravityField::actOn(Particle &particle)const
{
    Vector v=_position-particle.position();
    particle.acceleration()+=(v.unitVector()/v.modulus())*_gravity*particle.mass();
}

END_NAMESPACE_COOLPHYSICS2D