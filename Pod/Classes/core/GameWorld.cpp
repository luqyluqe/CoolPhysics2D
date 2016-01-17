#include "GameWorld.h"
#include "Particle.hpp"
#include "ParticleEmitter.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

GameWorld::GameWorld(Rectangle range):_range(range),_threadPool(4){}
GameWorld::~GameWorld()
{
    for (size_t i=0; i<_particles.size(); i++) {
        delete _particles[i];
    }
    for (size_t i=0; i<_fields.size(); i++) {
        delete _fields[i];
    }
    for (size_t i=0; i<_particleEmitters.size(); i++) {
        delete _particleEmitters[i];
    }
}

ThreadPool& GameWorld::threadPool()
{
    return _threadPool;
}

const Rectangle& GameWorld::range()const
{
	return _range;
}

std::vector<Particle*> const& GameWorld::particles()const
{
    return _particles;
}

void GameWorld::addParticle(Particle* particle)
{
	_particles.push_back(particle);
    if (particle->overlappable()) {
        _overlappableParticles.push_back(particle);
    }else{
        _unoverlappableParticles.push_back(particle);
    }
}
void GameWorld::addMaterialParticle(Particle* particle)
{
    _particles.push_back(particle);
    _unoverlappableParticles.push_back(particle);
}
void GameWorld::addPhantomParticle(Particle* particle)
{
    _particles.push_back(particle);
    _overlappableParticles.push_back(particle);
}
void GameWorld::addParticles(std::vector<Particle*> const& particles,bool phantom)
{
    _particles.insert(_particles.end(), particles.begin(),particles.end());
    if(phantom){
        _overlappableParticles.insert(_overlappableParticles.end(), particles.begin(),particles.end());
    }else{
        _unoverlappableParticles.insert(_unoverlappableParticles.end(), _unoverlappableParticles.begin(),_unoverlappableParticles.end());
    }
}
void GameWorld::removeParticle(Particle *particle)
{
    if (particle==NULL) {
        return;
    }
    std::vector<Particle*>::iterator it;
    for(it=_particles.begin();it!=_particles.end();it++)
    {
        if (*it==particle) {
            _particles.erase(it);
            break;
        }
    }
    if (it!=_particles.end()) {
        for (it=_overlappableParticles.begin(); it!=_overlappableParticles.end(); it++) {
            if (*it==particle) {
                _overlappableParticles.erase(it);
                delete particle;
                break;
            }
        }
        if (it==_overlappableParticles.end()) {
            for (it=_unoverlappableParticles.begin(); it!=_unoverlappableParticles.end(); it++) {
                if (*it==particle) {
                    _unoverlappableParticles.erase(it);
                    delete particle;
                    break;
                }
            }
        }
    }
}
void GameWorld::addField(Field *field)
{
    _fields.push_back(field);
}
void GameWorld::removeField(CoolPhysics2D::Field *field)
{
    std::vector<Field*>::iterator it=std::find(_fields.begin(), _fields.end(), field);
    if (it!=_fields.end()) {
        _fields.erase(it);
    }
}
void GameWorld::removeParticleEmitter(CoolPhysics2D::ParticleEmitter *emitter)
{
    for (std::vector<ParticleEmitter*>::iterator it=_particleEmitters.begin(); it!=_particleEmitters.end(); it++) {
        if (*it==emitter) {
            _particleEmitters.erase(it);
            delete emitter;
            break;
        }
    }
}
void GameWorld::addParticleEmitter(CoolPhysics2D::ParticleEmitter *emitter)
{
    _particleEmitters.push_back(emitter);
}


void GameWorld::update(double timeInterval)
{
    for (size_t i=0; i<_particleEmitters.size(); i++) {
        ParticleEmitter* pe=_particleEmitters[i];
        if (pe->enabled()) {
            pe->emit(timeInterval);
        }
    }
    size_t size=_particles.size();
    if (size<100000000) {
        for (size_t i=0; i<size; i++) {
            Particle* pi=_particles[i];
            update(pi, timeInterval);
        }
    }else{
        size_t section=size/4;
        for (size_t i=0; i<3; i++) {
            _threadPool.enqueue([section,i,this,timeInterval]{
                for (size_t j=0; j<section; j++) {
                    Particle* p=_particles[i*section+j];
                    update(p, timeInterval);
                }
            });
        }
        for (size_t k=3*section; k<size; k++) {
            Particle* p=_particles[k];
            update(p, timeInterval);
        }
    }

    for (size_t i=0; i<_unoverlappableParticles.size(); i++) {
        Particle* pi=_unoverlappableParticles[i];
        bounce(pi);
        for (size_t j=i+1; j<_unoverlappableParticles.size(); j++) {
            Particle* pj=_unoverlappableParticles[j];
            if (Particle::collide(*pi,*pj)) {
                Particle::handleCollision(*pi,*pj);
            }
        }
    }
}

void GameWorld::update(Particle* particle,double timeInterval)
{
    if (particle->lifeTime()<0) {
        removeParticle(particle);
        return;
    }
    particle->update(timeInterval);
    for (size_t j=0; j<_fields.size(); j++) {
        Field* f=_fields[j];
        if (f->enabled()) {
            f->actOn(*particle);
        }
    }
}

std::vector<Field*> GameWorld::fields()const
{
    return _fields;
}

void GameWorld::bounce(Particle* particle)const
{
	double x=particle->position().x();
	double y=particle->position().y();
    double vx=particle->velocity().x();
    double vy=particle->velocity().y();
    double r=particle->radius();
	if ((x+r>_range.x()+_range.width()&&vx>0)||(x-r<_range.x()&&vx<0)){
		particle->reflectAbout(Vector(0,1));
	}else if((y-r<_range.y()&&vy<0)||(y+r>_range.y()+_range.height()&&vy>0)){
		particle->reflectAbout(Vector(1,0));
	}
}

END_NAMESPACE_COOLPHYSICS2D
