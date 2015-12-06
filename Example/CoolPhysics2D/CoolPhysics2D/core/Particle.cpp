#include "Particle.h"
#include "GameWorld.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

Particle::Particle(bool overlappable,double radius,double mass,double elasticity,Vector position,Vector velocity,Vector acceleration,double lifeTime,Color color):_overlappable(overlappable),_radius(radius),_mass(mass),_position(position),_velocity(velocity),_acceleration(acceleration),_elasticity(elasticity),_lifeTime(lifeTime),_color(color){}

void Particle::update(double timeInterval)
{
    _lifeTime-=timeInterval;
    
    _lastAcceleration=_acceleration;
    _lastVelocity=_velocity;
    
    _position+=_lastVelocity*timeInterval;
	_velocity+=_lastAcceleration*timeInterval;
	
    _acceleration=Vector::zeroVector();
}

void Particle::reflectAbout(const Vector& axis)
{
    if (!_overlappable) {
        _velocity.symmetrizeAbout(axis);
        Vector n=axis.rotate(M_PI/2);
        double nComp=_velocity.componentAlongAxis(n);
        _velocity+=n*nComp*(_elasticity*_elasticity-1);
    }
}

double Particle::distanceTo(const Particle &e)const
{
    const Vector& p0=this->position();
    const Vector& p1=e.position();
    Vector v=p1-p0;
    return v.modulus();
}

bool Particle::collide(const Particle& p1,const Particle& p2)
{
    if (p1._overlappable||p2._overlappable) {
        return false;
    }
    double distance=p1.distanceTo(p2);
    if (distance<p1._radius+p2._radius) {
        Vector collisionAxis=p2.position()-p1.position();
        double v1=p1.velocity().componentAlongAxis(collisionAxis);
        double v2=p2.velocity().componentAlongAxis(collisionAxis);
        if ((v1-v2)>0) {
            return true;
        }
    }
    return false;
}

void Particle::handleCollision(Particle& Particle1,Particle& Particle2)
{
    double m1=Particle1._mass;
    double m2=Particle2._mass;
    Vector collisionAxis=(Particle2.position()-Particle1.position()).unitVector();
    double v1=Particle1.velocity().componentAlongAxis(collisionAxis);
    double v2=Particle2.velocity().componentAlongAxis(collisionAxis);
    double V1=Particle1._elasticity*((m1-m2)*v1+2*m2*v2)/(m1+m2);
    double V2=Particle2._elasticity*((m2-m1)*v2+2*m1*v1)/(m2+m1);
    double e=Particle1._elasticity*Particle2._elasticity;
    double v=v1-v2>=0?v1-v2:v2-v1;
    double dv=v*(1-e);
    double dv1=dv*m2/(m1+m2);
    double dv2=dv*m1/(m1+m2);
    V1+=dv1;
    V2+=dv2;
    Particle1._velocity+=collisionAxis*(V1-v1);
    Particle2._velocity+=collisionAxis*(V2-v2);
}

std::string Particle::description()const
{
	std::stringstream ss;
	ss<<"position: "<<_position.description()<<"\n";
	ss<<"velocity: "<<_velocity.description()<<"\n";
	ss<<"acceleration: "<<_acceleration.description()<<"\n";
	ss<<"\n";
	return ss.str();
}

double Particle::lifeTime()const
{
    return _lifeTime;
}
double Particle::radius()const
{
    return _radius;
}
const Vector& Particle::position()const
{
	return _position;
}
void Particle::setPosition(const Vector &position)
{
    _position=position;
}
const Vector& Particle::velocity()const
{
	return _velocity;
}
void Particle::setVelocity(const Vector &velocity)
{
    _velocity=velocity;
}
const Vector& Particle::acceleration()const
{
	return _acceleration;
}
const Color& Particle::color()const
{
    return _color;
}

Circle Particle::range()const
{
    return Circle(_position,_radius);
}

END_NAMESPACE_COOLPHYSICS2D
