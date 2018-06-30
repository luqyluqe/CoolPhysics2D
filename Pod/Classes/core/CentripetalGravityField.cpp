#include "CentripetalGravityField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

CentripetalGravityField::CentripetalGravityField(const Rectangle& range,const Vector& center,double gravity):AttachableField(range),_center(center),_gravity(gravity){}

CentripetalGravityField::~CentripetalGravityField(){}

void CentripetalGravityField::actOn(Particle &particle)const
{
    Vector v=_center-particle.position();
    particle.acceleration()+=(v.unitVector()/v.modulus())*_gravity*particle.mass();
}

void CentripetalGravityField::attachTo(const Particle* particle){
    _center=particle->position();
}

END_NAMESPACE_COOLPHYSICS2D
