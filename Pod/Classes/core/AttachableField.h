//
//  AttachableField.hpp
//  Pods
//
//  Created by luqyluqe on 11/01/2018.
//

#ifndef AttachableField_hpp
#define AttachableField_hpp

#include "Field.h"
#include "Particle.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class AttachableField:public Field
{
public:
    AttachableField(const Rectangle& range);
    AttachableField(const Rectangle& range,const Particle* charge);
    virtual void attachTo(const Particle& charge);
    virtual void detach();
protected:
    const Particle* _charge;
};

END_NAMESPACE_COOLPHYSICS2D

#endif /* AttachableField_hpp */
