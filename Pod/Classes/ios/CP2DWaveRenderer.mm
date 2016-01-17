#import "CP2DWaveRenderer.h"

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
    
}

@end
