#include "GameWorld.h"
#include "Particle.h"
#include "ParticleEmitter.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

GameWorld::GameWorld(Rectangle range):_range(range){}
GameWorld::~GameWorld()
{
    for (int i=0; i<_particles.size(); i++) {
        delete _particles[i];
    }
    for (int i=0; i<_fields.size(); i++) {
        delete _fields[i];
    }
}

const Rectangle& GameWorld::range()const
{
	return _range;
}

const std::vector<Particle*> GameWorld::particles()const
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
void GameWorld::removeParticle(Particle *particle)
{
    std::vector<Particle*>::iterator it=std::find(_particles.begin(), _particles.end(), particle);
    if (it!=_particles.end()) {
        _particles.erase(it);
        if (particle->overlappable()) {
            it=std::find(_overlappableParticles.begin(), _overlappableParticles.end(), particle);
            _overlappableParticles.erase(it);
        }else{
            it=std::find(_unoverlappableParticles.begin(), _unoverlappableParticles.end(), particle);
            _unoverlappableParticles.erase(it);
        }
        delete particle;
    }
}
void GameWorld::addField(Field *field)
{
    _fields.push_back(field);
}
void GameWorld::removeField(CoolPhysics2D::Field *field)
{
    for (std::vector<Field*>::iterator it=_fields.begin(); it!=_fields.end(); it++) {
        if (*it==field) {
            _fields.erase(it);
            break;
        }
    }
}
void GameWorld::removeParticleEmitter(CoolPhysics2D::ParticleEmitter *emitter)
{
    for (std::vector<ParticleEmitter*>::iterator it=_particleEmitters.begin(); it!=_particleEmitters.end(); it++) {
        if (*it==emitter) {
            _particleEmitters.erase(it);
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
    for (int i=0; i<_particleEmitters.size(); i++) {
        ParticleEmitter* pe=_particleEmitters[i];
        if (pe->enabled()) {
            pe->emit(timeInterval);
        }
    }
    for (int i=0; i<_particles.size(); i++) {
        Particle* pi=_particles[i];
        if (pi->lifeTime()<0) {
            removeParticle(pi);
        }
        pi->update(timeInterval);
        
        for (int j=0; j<_fields.size(); j++) {
            Field* f=_fields[j];
            if (f->enabled()) {
                f->actOn(*_particles[i]);
            }
        }
    }
    
    for (int i=0; i<_unoverlappableParticles.size(); i++) {
        Particle* pi=_unoverlappableParticles[i];
        bounce(pi);
        for (int j=i+1; j<_unoverlappableParticles.size(); j++) {
            Particle* pj=_unoverlappableParticles[j];
            if (Particle::collide(*pi,*pj)) {
                Particle::handleCollision(*pi,*pj);
            }
        }
    }
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
