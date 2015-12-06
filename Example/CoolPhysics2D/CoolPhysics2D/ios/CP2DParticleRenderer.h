//
//  CP2DParticleRenderer.h
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/28/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#include "Particle.h"

#import <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

using namespace CoolPhysics2D;

@interface CP2DParticleRenderer : NSObject

-(id)initWithParticle:(Particle*)particle;

-(void)renderInContext:(CGContextRef)context;

@end
