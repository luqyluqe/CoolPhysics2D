#import "CP2DGameView.h"
#include "Vector.h"
#import "CP2DParticleRenderer.h"
#include "Field.h"
#include "DampingField.h"
#include "GravityField.h"
#include "BuoyancyField.h"
#include "ParticleEmitter.h"

@implementation CP2DGameView

-(id)initWithFrame:(CGRect)frame
{
    if(self=[super initWithFrame:frame])
    {
        Rectangle gameWorldRange(0,0,self.frame.size.width,self.frame.size.height);
        self.gameWorld=new GameWorld(gameWorldRange);
    }
    return self;
}

-(void)drawRect:(CGRect)rect
{
    CGContextRef ctx=UIGraphicsGetCurrentContext();
    CGContextClearRect(ctx, rect);
    UIColor* clearColor=[self getClearColor];
    if (clearColor) {
        CGContextSetFillColorWithColor(ctx, clearColor.CGColor);
        CGContextFillRect(ctx, rect);
    }
    _gameWorldRenderer=[[CP2DGameWorldRenderer alloc] initWithGameWorld:self.gameWorld];
    [_gameWorldRenderer renderInContext:ctx];
}

-(UIColor*)getClearColor
{
    return nil;
}

-(void)dealloc
{
    delete self.gameWorld;
}

@end
