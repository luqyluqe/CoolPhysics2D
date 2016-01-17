#include "Wave.hpp"
#include <cmath>

BEGIN_NAMESPACE_COOLPHYSICS2D

Wave Wave::pulse(Vector position, float power)
{
    return Wave(position,power);
}

Wave::Wave(Vector position,float power,float velocity,float attenuation,Color color):_position(position),_power(power),_velocity(velocity),_attenuation(attenuation),_color(color){}

void Wave::update(float timeInterval)
{
    _radius+=_velocity;
}

Color Wave::color()const
{
    return _color*log(1+_radius);
}

Vector const& Wave::position()const
{
    return _position;
}

float Wave::radius()const
{
    return _radius;
}

END_NAMESPACE_COOLPHYSICS2D
