#include "Particle.hpp"

BEGIN_NAMESPACE_COOLPHYSICS2D

Particle::Particle(bool overlappable,double radius,double mass,double elasticity,Vector position,Vector velocity,Vector acceleration,double lifeTime,Color color)
{
    _particle=new OpaqueParticle(overlappable,radius,mass,elasticity,position,velocity,
                                 acceleration,lifeTime,color);
}

Particle::~Particle()
{
    if (retainCount.only()) {
        delete _particle;
    }
}

std::string Particle::description()const
{
    return _particle->description();
}

void Particle::update(double timeInterval)
{
    _particle->update(timeInterval);
}

void Particle::reflectAbout(const Vector& axis)
{
    _particle->reflectAbout(axis);
}

double Particle::distanceTo(const Particle& p)const
{
    return _particle->distanceTo(*p._particle);
}

bool Particle::collide(const Particle& p1,const Particle& p2)
{
    return OpaqueParticle::collide(*p1._particle, *p2._particle);
}

void Particle::handleCollision(Particle& e1,Particle& e2)
{
    OpaqueParticle::handleCollision(*e1._particle, *e2._particle);
}

double Particle::lifeTime()const
{
    return _particle->lifeTime();
}

double Particle::radius()const
{
    return _particle->radius();
}

const Vector& Particle::position()const
{
    return _particle->position();
}
void Particle::setPosition(const Vector& position)
{
    _particle->setPosition(position);
}
const Vector& Particle::velocity()const
{
    return _particle->velocity();
}
void Particle::setVelocity(const Vector& velocity)
{
    _particle->setVelocity(velocity);
}
Vector& Particle::acceleration()const
{
    return _particle->acceleration();
}
const Color& Particle::color()const
{
    return _particle->color();
}
Circle Particle::range()const
{
    return _particle->range();
}
double Particle::mass()const
{
    return _particle->mass();
}
bool Particle::overlappable()const
{
    return _particle->overlappable();
}

END_NAMESPACE_COOLPHYSICS2D
