#include "CentripetalGravityField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

CentripetalGravityField::CentripetalGravityField(const Rectangle& range,const Particle& charge,double gravity):AttachableField(range,charge),_gravity(gravity){}

CentripetalGravityField::~CentripetalGravityField(){}

void CentripetalGravityField::actOn(Particle &particle)const
{
    Vector v=_charge->position()-particle.position();
    particle.acceleration()+=(v.unitVector()/v.modulus())*_gravity*particle.mass();
}

END_NAMESPACE_COOLPHYSICS2D
