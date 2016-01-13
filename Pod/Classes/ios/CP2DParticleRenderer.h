#include "Particle.hpp"

#import <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

using namespace CoolPhysics2D;

@interface CP2DParticleRenderer : NSObject

-(id)initWithParticle:(Particle*)particle;

-(void)renderInContext:(CGContextRef)context;

@end
