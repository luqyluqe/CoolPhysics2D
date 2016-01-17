#include "Wave.hpp"
#include <cmath>

BEGIN_NAMESPACE_COOLPHYSICS2D

Wave::Wave(Vector position,float velocity,float attenuation,Color color):_position(position),_velocity(velocity),_attenuation(attenuation),_color(color){}

void Wave::update(float timeInterval)
{
    _radius+=_velocity;
}

Color Wave::color()const
{
    return _color*log(1+_radius);
}

END_NAMESPACE_COOLPHYSICS2D
