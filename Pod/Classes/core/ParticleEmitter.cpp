#include "ParticleEmitter.h"
#include "GameWorld.h"

#include <math.h>

#define RAND(min,max)   min+(max-min)*((double)rand()/RAND_MAX);

BEGIN_NAMESPACE_COOLPHYSICS2D

ParticleEmitter::ParticleEmitter(GameWorld& gameWorld,const Vector& position,double frequency,double minLifeTime,double maxLifeTime,const Color& minColor,const Color& maxColor,double minRadius,double maxRadius,double minDensity,double maxDensity,double minElasticity,double maxElasticity,double minSpeed,double maxSpeed,double minRadian,double maxRadian):_gameWorld(gameWorld),_position(position),_frequency(frequency),_minColor(minColor),_maxColor(maxColor),_minLifeTime(minLifeTime),_maxLifeTime(maxLifeTime),_minRadius(minRadius),_maxRadius(maxRadius),_minDensity(minDensity),_maxDensity(maxDensity),_minElasticity(minElasticity),_maxElasticity(maxElasticity),_minSpeed(minSpeed),_maxSpeed(maxSpeed),_minRadian(minRadian),_maxRadian(maxRadian),_time(0),_particleCount(0),_overlappable(true)
{
    disable();
}

ParticleEmitter::~ParticleEmitter(){}

//std::vector<Particle*> const& ParticleEmitter::particles()const
//{
//    return _particles;
//}

bool ParticleEmitter::phantom()const
{
    return _overlappable;
}

void ParticleEmitter::overlappable(bool overlappable)
{
    _overlappable=overlappable;
}

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

//void ParticleEmitter::update(double timeInterval)
//{
//    _gameWorld.threadPool().enqueue([this,timeInterval]{
//        retain();
//        for (int i=0; i<_particles.size(); i++) {
//            update(_particles[i], timeInterval);
//        }
//        release();
//    });
//}
//
//void ParticleEmitter::update(Particle* particle,double timeInterval)
//{
//    if (particle->lifeTime()<0) {
//        remove(particle);
//    }
//    particle->update(timeInterval);
//    for (int j=0; j<_gameWorld.fields().size(); j++) {
//        Field* f=_gameWorld.fields()[j];
//        if (f->enabled()) {
//            f->actOn(*particle);
//        }
//    }
//}

//void ParticleEmitter::remove(Particle* particle)
//{
//    std::vector<Particle*>::iterator it=std::find(_particles.begin(), _particles.end(), particle);
//    if (it!=_particles.end()) {
//        _particles.erase(it);
//        delete particle;
//    }
//}

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
        Color color((float)red,(float)green,(float)blue,(float)alpha);
        
        Particle* particle=new Particle(_overlappable,radius,mass,elasticity,_position,Vector::vectorMake(speed, radian),Vector::zeroVector(),lifeTime,color);
//        if (_overlappable) {
//            _particles.push_back(particle);
//        }else{
//            _gameWorld.addMaterialParticle(particle);
//        }
        _gameWorld.addParticle(particle);
    }
}

END_NAMESPACE_COOLPHYSICS2D