//
//  CP2DRenderer.h
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/28/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "GameWorld.h"

using namespace CoolPhysics2D;

@interface CP2DGameWorldRenderer : NSObject

-(id)initWithGameWorld:(GameWorld*)gameWorld;

-(void)renderInContext:(CGContextRef)ctx;

@end