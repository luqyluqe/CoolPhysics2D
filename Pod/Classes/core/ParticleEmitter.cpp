#include "ParticleEmitter.h"
#include "Particle.h"
#include "GameWorld.h"

#include <math.h>

#define RAND(min,max)   min+(max-min)*((double)rand()/RAND_MAX);

BEGIN_NAMESPACE_COOLPHYSICS2D

ParticleEmitter::ParticleEmitter(GameWorld& gameWorld,const Vector& position,double frequency,double minLifeTime,double maxLifeTime,const Color& minColor,const Color& maxColor,double minRadius,double maxRadius,double minDensity,double maxDensity,double minElasticity,double maxElasticity,double minSpeed,double maxSpeed,double minRadian,double maxRadian):_gameWorld(gameWorld),_position(position),_frequency(frequency),_minColor(minColor),_maxColor(maxColor),_minLifeTime(minLifeTime),_maxLifeTime(maxLifeTime),_minRadius(minRadius),_maxRadius(maxRadius),_minDensity(minDensity),_maxDensity(maxDensity),_minElasticity(minElasticity),_maxElasticity(maxElasticity),_minSpeed(minSpeed),_maxSpeed(maxSpeed),_minRadian(minSpeed),_maxRadian(maxSpeed),_time(0),_particleCount(0)
{
    disable();
}

ParticleEmitter::~ParticleEmitter(){}

void ParticleEmitter::enable()
{
    _enabled=true;
}
void ParticleEmitter::disable()
{
    _enabled=false;
}
bool ParticleEmitter::enabled()const
{
    return _enabled;
}

void ParticleEmitter::emit(double interval)
{
    _time+=interval;
    double stock=_particleCount;
    _particleCount=_time*_frequency;
    double inc=_particleCount-stock;
    for (int i=0; i<inc; i++) {
        double radius=RAND(_minRadius, _maxRadius);
        double density=RAND(_minDensity, _maxDensity);
        double mass=density*M_PI*radius*radius;
        double elasticity=RAND(_minElasticity, _maxElasticity);
        double speed=RAND(_minSpeed, _maxSpeed);
        double radian=RAND(_minRadian, _maxRadian);
        double lifeTime=RAND(_minLifeTime, _maxLifeTime);
 
        double red=RAND(_minColor.RED, _maxColor.RED);
        double green=RAND(_minColor.GREEN, _maxColor.GREEN);
        double blue=RAND(_minColor.BLUE, _maxColor.BLUE);
        double alpha=RAND(_minColor.ALPHA, _maxColor.ALPHA);
        Color color(red,green,blue,alpha);
        
        Particle* particle=new Particle(true,radius,mass,elasticity,_position,Vector::vectorMake(speed, radian),Vector::zeroVector(),lifeTime,color);
        _gameWorld.addParticle(particle);
    }
}

END_NAMESPACE_COOLPHYSICS2D