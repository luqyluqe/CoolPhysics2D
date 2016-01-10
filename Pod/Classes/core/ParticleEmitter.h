#ifndef COOLPHYSICS2D_PARTICLEEMITTER_H
#define COOLPHYSICS2D_PARTICLEEMITTER_H

#include "config.h"
#include "Vector.h"
#include "Color.h"
#include "Particle.h"

#include <vector>

BEGIN_NAMESPACE_COOLPHYSICS2D

class GameWorld;

class ParticleEmitter
{
    friend class GameWorld;
public:
    //Constructor
    ParticleEmitter(GameWorld& gameWorld,const Vector& position,double frequency,double minLifeTime,double maxLifeTime,const Color& minColor,const Color& maxColor,double minRadius,double maxRadius,double minDensity,double maxDensity,double minElasticity,double maxElasticity,double minSpeed,double maxSpeed,double minRadian,double maxRadian);
    
    //Destructor
    ~ParticleEmitter();
    
    void enable();
    void disable();
    bool enabled()const;
protected:
    bool phantom()const;
    void overlappable(bool overlappable);
    void update(double timeInterval);
    void emit(double interval);
    std::vector<Particle*> const& particles()const;
private:
    void update(Particle* particle,double timeInterval);
    void remove(Particle* particle);
    
    bool _enabled;
    bool _overlappable;
    
    GameWorld& _gameWorld;
    std::vector<Particle*> _particles;
    Vector _position;
    double _frequency;
    
    //Particle property
    double _minLifeTime;
    double _maxLifeTime;
    double _minRed;
    double _maxRed;
    Color _minColor;
    Color _maxColor;
    double _minRadius;
    double _maxRadius;
    double _minDensity;
    double _maxDensity;
    double _minElasticity;
    double _maxElasticity;
    double _minSpeed;
    double _maxSpeed;
    double _minRadian;
    double _maxRadian;
    
    double _time;
    double _particleCount;
};

END_NAMESPACE_COOLPHYSICS2D

#endif