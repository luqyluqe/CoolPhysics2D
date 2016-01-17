#import "CP2DWaveRenderer.h"
#import <UIKit/UIKit.h>
#import <cmath>

@implementation CP2DWaveRenderer
{
    Wave* _wave;
}

-(instancetype)initWithWave:(Wave*)wave
{
    if (self=[super init]) {
        _wave=wave;
    }
    return self;
}

-(void)renderInContext:(CGContextRef)context
{
    if(!_wave) return;
    if (isnan(_wave->position().x())||isnan(_wave->position().y())) {
        return;
    }
    CGPoint center = CGPointMake(_wave->position().x(), _wave->position().y());
    
    CGContextMoveToPoint(context, center.x, center.y);
    Color color=_wave->color();
    CGColorRef cgColor=[UIColor colorWithRed:color.RED green:color.GREEN blue:color.BLUE alpha:color.ALPHA].CGColor;
    const CGFloat* colorComponents=CGColorGetComponents(cgColor);
    CGContextSetFillColor(context, colorComponents);
    CGContextAddArc(context, center.x, center.y, _wave->radius(),  0, 2*M_PI, 0);
    CGContextFillPath(context);
}

@end
