//
//  AttachableField.cpp
//  Pods
//
//  Created by luqyluqe on 11/01/2018.
//

#include "AttachableField.hpp"

BEGIN_NAMESPACE_COOLPHYSICS2D

AttachableField::AttachableField(const Rectangle& range):Field(range){}

AttachableField::AttachableField(const Rectangle& range,const Particle& charge):Field(range), _charge(&charge){}

void AttachableField::attachTo(const Particle& charge)
{
    _charge=&charge;
}

void AttachableField::detach()
{
    _charge=nullptr;
}

END_NAMESPACE_COOLPHYSICS2D
