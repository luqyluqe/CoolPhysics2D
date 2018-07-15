#import <Foundation/Foundation.h>
#import "CP2DRenderer.h"

#include "GameWorld.h"

using namespace CoolPhysics2D;

@interface CP2DGameWorldRenderer : NSObject<CP2DRenderer>

-(id)initWithGameWorld:(GameWorld*)gameWorld;

@end
