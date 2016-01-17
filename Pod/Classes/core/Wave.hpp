#ifndef COOLPHYSICS2D_WAVE_HPP
#define COOLPHYSICS2D_WAVE_HPP

#include "config.h"
#include "Vector.h"
#include "Color.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class Wave
{
public:
    Wave(Vector position,float velocity,float attenuation,Color color);
    
    void update(float timeInterval);
    Color color()const;
    Vector const& position()const;
    float radius()const;
private:
    const Vector _position;
    const float _velocity;
    const float _attenuation;
    const Color _color;
    
    float _lifetime;
    float _radius;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
