#include "CentripetalGravityField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

CentripetalGravityField::CentripetalGravityField(const Rectangle& range,const Particle* charge,double gravity):AttachableField(range,charge),_gravity(gravity){}

CentripetalGravityField::~CentripetalGravityField(){}

void CentripetalGravityField::actOn(Particle &particle)const
{
    if (_charge==&particle) {
        return;
    }
    Vector v=_charge->position()-particle.position();
    particle.acceleration()+=(v.unitVector()/(v.modulus()*v.modulus()))*_gravity*_charge->mass();
}

END_NAMESPACE_COOLPHYSICS2D
