#import "CP2DParticleRenderer.h"
#import <UIKit/UIKit.h>

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
    if (!_particle) {
        return;
    }
    if (isnan(_particle->position().x())||isnan(_particle->position().y())) {
        return;
    }
    CGPoint thePoint = CGPointMake(_particle->position().x(), _particle->position().y());
    
    CGContextMoveToPoint(context, thePoint.x, thePoint.y);
    Color color=_particle->color();
    CGColorRef cgColor=[UIColor colorWithRed:color.RED green:color.GREEN blue:color.BLUE alpha:color.ALPHA].CGColor;
    const CGFloat* colorComponents=CGColorGetComponents(cgColor);
    CGContextSetFillColor(context, colorComponents);
    CGContextAddArc(context, thePoint.x, thePoint.y, _particle->radius(),  0, 2*M_PI, 0);
    CGContextFillPath(context);
}

@end
