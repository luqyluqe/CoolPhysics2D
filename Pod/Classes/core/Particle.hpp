#ifndef COOLPHYSICS2D_PARTICLE_HPP
#define COOLPHYSICS2D_PARTICLE_HPP

#include "config.h"
#include "Vector.h"
#include "Circle.h"
#include "Color.h"
#include "OpaqueParticle.h"
#include "RetainCount.hpp"

#include <string>
#include <sstream>
#include <mutex>

using CoolPhysics2D::opaque::OpaqueParticle;
using CoolPhysics2D::retaincount::RetainCount;
using namespace Math;

BEGIN_NAMESPACE_COOLPHYSICS2D

class Particle
{
public:
    std::mutex _destructorMutex;
    
    Particle(bool overlappable,double radius,double mass,double elasticity,Vector position,Vector velocity,Vector acceleration,double lifeTime,Color color=Color::whiteColor);
    Particle(Particle const& particle);
    ~Particle();
    
    std::string description()const;
    
    void update(double timeInterval);
    
    void reflectAbout(const Vector& axis); //behavior when collides with the edge of the game world
    
    //Relation
    double distanceTo(const Particle& p)const;
    static bool collide(const Particle&,const Particle&);
    
    //Action
    static void handleCollision(Particle& e1,Particle& e2);
    
    //Accessor
    double lifeTime()const;
    double radius()const;
    const Vector& position()const;
    void setPosition(const Vector&);
    const Vector& velocity()const;
    void setVelocity(const Vector&);
    Vector& acceleration()const;
    const Color& color()const;
    Circle range()const;
    double mass()const;
    bool overlappable()const;
private:
    OpaqueParticle* _particle;
    RetainCount _retainCount;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
