//
//  AttachableField.cpp
//  Pods
//
//  Created by luqyluqe on 11/01/2018.
//

#include "AttachableField.hpp"

BEGIN_NAMESPACE_COOLPHYSICS2D

AttachableField::AttachableField(const Rectangle& range):Field(range){}

AttachableField::AttachableField(const Rectangle& range,const Particle& particle):Field(range), _particle(&particle){}

void AttachableField::attachTo(const Particle& particle)
{
    _particle=&particle;
}

void AttachableField::detach()
{
    _particle=nullptr;
}

END_NAMESPACE_COOLPHYSICS2D
