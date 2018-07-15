#include "Particle.h"
#import "CP2DRenderer.h"
#import <Foundation/Foundation.h>

using namespace CoolPhysics2D;

@interface CP2DParticleRenderer : NSObject<CP2DRenderer>

-(id)initWithParticle:(Particle*)particle;

@end
