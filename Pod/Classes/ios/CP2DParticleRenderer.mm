//
//  CP2DParticleRenderer.m
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/28/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import "CP2DParticleRenderer.h"

@implementation CP2DParticleRenderer

{
    Particle* _particle;
}

-(id)initWithParticle:(Particle *)particle
{
    if (self=[super init]) {
        _particle=particle;
    }
    return self;
}

-(void)renderInContext:(CGContextRef)context
{
    if (_particle) {
        CGPoint thePoint = CGPointMake(_particle->position().x(), _particle->position().y());
        
        CGContextMoveToPoint(context, thePoint.x, thePoint.y);
        Color color=_particle->color();
        CGContextSetFillColor(context, CGColorGetComponents([UIColor colorWithRed:color.RED green:color.GREEN blue:color.BLUE alpha:color.ALPHA].CGColor));
        CGContextAddArc(context, thePoint.x, thePoint.y, _particle->radius(),  0, 2*M_PI, 0);
        CGContextFillPath(context);
    }
}

@end
