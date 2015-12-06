//
//  CP2DRenderer.m
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/28/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

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
    for (int i=0; i<ps.size(); i++) {
        CP2DParticleRenderer* particleRenderer=[[CP2DParticleRenderer alloc] initWithParticle:ps[i]];
        [particleRenderer renderInContext:ctx];
    }
}

@end