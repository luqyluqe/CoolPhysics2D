#import <Foundation/Foundation.h>
#include "Wave.h"
#import "CP2DRenderer.h"

using namespace CoolPhysics2D;

@interface CP2DWaveRenderer:NSObject<CP2DRenderer>

-(instancetype)initWithWave:(Wave*)wave;

@end
