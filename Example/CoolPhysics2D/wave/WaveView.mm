#import "WaveView.h"
#include "Wave.hpp"
#import "CP2DWaveRenderer.h"

@implementation WaveView

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self pulse:touches];
}

-(void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self pulse:touches];
}

-(void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self pulse:touches];
}

-(void)pulse:(NSSet<UITouch *> *)touches
{
    UITouch* touch=touches.anyObject;
    CGPoint location=[touch locationInView:self];
    Wave* wave=new Wave(Vector(location.x,location.y),1);
    self.gameWorld->addWave(wave);
}

-(UIColor*)getClearColor
{
    return [UIColor whiteColor];
}

@end
