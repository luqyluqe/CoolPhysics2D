#ifndef COOLPHYSICS2D_OBSTACLEFIELD_H
#define COOLPHYSICS2D_OBSTACLEFIELD_H

#include "config.h"
#include "Field.h"
#include "Rectangle.h"
#include "Particle.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class ObstacleField:public Field
{
public:
    ObstacleField(const Rectangle& range);
    virtual ~ObstacleField();
    
    virtual void actOn(Particle& particle)const;
};

END_NAMESPACE_COOLPHYSICS2D

#endif