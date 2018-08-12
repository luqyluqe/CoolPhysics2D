#ifndef COOLPHYSICS2D_PARTICLE_H
#define COOLPHYSICS2D_PARTICLE_H

#include "config.h"
#include "raw_config.h"
#include "Vector.h"
#include "Circle.h"
#include "Color.h"

#include <string>
#include <sstream>

using namespace Math;

BEGIN_NAMESPACE_COOLPHYSICS2D
BEGIN_NAMESPACE_RAW

#define MAX_LIFETIME 10000

class GameWorld;

class Particle
{
    //Friend class
    friend class DampingField;
    friend class GravityField;
    friend class BuoyancyField;
    friend class CentripetalGravityField;
    
public:
    Particle(bool overlappable,double radius,double mass,double elasticity,Vector position,Vector velocity,Vector acceleration,double lifeTime=MAX_LIFETIME,Color color=Color::whiteColor);

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
    Vector& acceleration();
    const Color& color()const;
    Circle range()const;
    double mass()const;
    bool overlappable()const;
    
protected:
    

private:
    bool _overlappable;
    double _lifeTime;
    
    double _radius;
	double _mass;
    double _elasticity;
    double _friction;
    
	Vector _position;
	Vector _velocity;
	Vector _acceleration;
    
    Vector _lastPosition;
    Vector _lastVelocity;
    Vector _lastAcceleration;
    
    Color _color;
};

END_NAMESPACE_RAW
END_NAMESPACE_COOLPHYSICS2D

#endif
