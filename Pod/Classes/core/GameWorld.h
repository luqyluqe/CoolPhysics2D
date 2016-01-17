#ifndef COOLPHYSICS2D_GAMEWORLD_H
#define COOLPHYSICS2D_GAMEWORLD_H

#include "config.h"
#include "Vector.h"
#include "Field.h"
#include "Rectangle.h"
#include "ThreadPool.h"
#include "Wave.hpp"

#include <vector>

BEGIN_NAMESPACE_COOLPHYSICS2D

//class Particle;
class ParticleEmitter;

class GameWorld
{
    friend class ParticleEmitter;
public:
	//Constructor
	GameWorld(Rectangle range);
    //Destructor
    ~GameWorld();

	//Accessor
	const Rectangle& range()const;
    std::vector<Particle*> const& particles()const;
    std::vector<Wave*> const& waves()const;
//    std::vector<Particle*> const& retainParticles();
//    void releaseParticles();

	void addParticle(Particle* particle);
    void addParticles(std::vector<Particle*> const& particles,bool phantom);
    void addMaterialParticle(Particle* particle);
    void addPhantomParticle(Particle* particle);
    void removeParticle(Particle* particle);
    void addField(Field* field);
    void removeField(Field* field);
    void addParticleEmitter(ParticleEmitter* emitter);
    void removeParticleEmitter(ParticleEmitter* emitter);
    void addWave(Wave* wave);
    void removeWave(Wave* wave);

    void update(float timeInterval);
protected:
    ThreadPool& threadPool();
    std::vector<Field*> fields()const;
private:
    ThreadPool _threadPool;
    void update(Particle* particle,double timeInterval);
	void bounce(Particle* Particle)const;
	Rectangle _range;
	std::vector<Particle*> _particles;
    std::vector<Particle*> _overlappableParticles;
    std::vector<Particle*> _unoverlappableParticles;
    std::vector<ParticleEmitter*> _particleEmitters;
    std::vector<Field*> _fields;
    std::vector<Wave*> _waves;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
