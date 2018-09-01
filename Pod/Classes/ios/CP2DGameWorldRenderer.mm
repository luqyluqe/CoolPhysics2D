#import "CP2DGameWorldRenderer.h"
#import "CP2DWaveRenderer.h"
#import "CP2DParticleRenderer.h"

@implementation CP2DGameWorldRenderer
{
    GameWorld* _gameWorld;
}

-(id)initWithGameWorld:(GameWorld*)gameWorld
{
    if (self=[super init]) {
        _gameWorld=gameWorld;
    }
    return self;
}

-(void)renderInContext:(CGContextRef)ctx
{
    _gameWorld->lock();
    std::vector<Particle*> ps=_gameWorld->particles();
    for (size_t i=0; i<ps.size(); i++) {
        CP2DParticleRenderer* particleRenderer=[[CP2DParticleRenderer alloc] initWithParticle:ps[i]];
        [particleRenderer renderInContext:ctx];
    }
    
    std::vector<Wave*> const& waves=_gameWorld->waves();
    for (size_t i=0; i<waves.size(); i++) {
        CP2DWaveRenderer* waveRenderer=[[CP2DWaveRenderer alloc] initWithWave:waves[i]];
        [waveRenderer renderInContext:ctx];
    }
    _gameWorld->unlock();
}

@end
