#import "CP2DGameWorldRenderer.h"

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
    const std::vector<Particle*>& ps=_gameWorld->particles();
    if (ps.size()==0) {
        return;
    }
    for (size_t i=0; i<ps.size(); i++) {
        CP2DParticleRenderer* particleRenderer=[[CP2DParticleRenderer alloc] initWithParticle:ps[i]];
        [particleRenderer renderInContext:ctx];
    }
}

@end