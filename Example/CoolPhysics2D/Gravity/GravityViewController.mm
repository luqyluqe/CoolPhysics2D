//
//  GravityViewController.m
//  CoolPhysics2D_Example
//
//  Created by gouchen on 2018/7/1.
//  Copyright © 2018 luqyluqe. All rights reserved.
//

#import "GravityViewController.h"
#import "GravityView.h"

@interface GravityViewController ()

@end

@implementation GravityViewController

-(CP2DGameView*)getGameView
{
    CP2DGameView* gameView=[[GravityView alloc] initWithFrame:self.view.frame];
    return gameView;
}

-(float)getUpdateInterval
{
    return 0.01f;
}

@end
