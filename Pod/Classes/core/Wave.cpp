#include "Wave.h"
#include <cmath>

BEGIN_NAMESPACE_COOLPHYSICS2D

Wave* Wave::pulse(Vector position, float power)
{
    return new Wave(position,power);
}

Wave::Wave(Vector position,float power,float velocity,float attenuation,Color color,float lifetime):_position(position),_power(power),_velocity(velocity),_attenuation(attenuation),_color(color),_lifetime(lifetime),_radius(0){}

void Wave::update(float timeInterval)
{
    _radius+=_velocity;
    _lifetime-=timeInterval;
}

Color Wave::color()const
{
    Color color=_color*log(2+_radius/200);
    return color;
}

Vector const& Wave::position()const
{
    return _position;
}

float Wave::radius()const
{
    return _radius;
}

float Wave::lifetime()const
{
    return _lifetime;
}

END_NAMESPACE_COOLPHYSICS2D
