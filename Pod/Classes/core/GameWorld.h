#ifndef COOLPHYSICS2D_GAMEWORLD_H
#define COOLPHYSICS2D_GAMEWORLD_H

#include "config.h"
#include "Vector.h"
#include "Particle.h"
#include "Field.h"
#include "Rectangle.h"
#include "ThreadPool.h"

#include <vector>

BEGIN_NAMESPACE_COOLPHYSICS2D

class Particle;
class ParticleEmitter;

class GameWorld
{
public:
	//Constructor
	GameWorld(Rectangle range);
    //Destructor
    ~GameWorld();

	//Accessor
	const Rectangle& range()const;
    const std::vector<Particle*> particles()const;

    //Behavior
	void addParticle(Particle* particle);
    void removeParticle(Particle* particle);
    void addField(Field* field);
    void removeField(Field* field);
    void addParticleEmitter(ParticleEmitter* emitter);
    void removeParticleEmitter(ParticleEmitter* emitter);

    void update(double timeInterval);

private:
    ThreadPool threadPool;
    void update(Particle* particle,double timeInterval);
	void bounce(Particle* Particle)const;
	Rectangle _range;
	std::vector<Particle*> _particles;
    std::vector<Particle*> _overlappableParticles;
    std::vector<Particle*> _unoverlappableParticles;
    std::vector<ParticleEmitter*> _particleEmitters;
    std::vector<Field*> _fields;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
