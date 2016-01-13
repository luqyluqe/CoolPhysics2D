#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "GameWorld.h"

using namespace CoolPhysics2D;

@interface CP2DGameWorldRenderer : NSObject

-(id)initWithGameWorld:(GameWorld*)gameWorld;

-(void)renderInContext:(CGContextRef)ctx;

@end