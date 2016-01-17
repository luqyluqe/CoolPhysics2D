//
//  BouncingBallViewController.m
//  CoolPhysics2DDemo
//
//  Created by luqyluqe on 12/1/14.
//  Copyright (c) 2014 luqyluqe. All rights reserved.
//

#import "BouncingBallViewController.h"
#import "BouncingBallView.h"

@implementation BouncingBallViewController

-(CP2DGameView*)getGameView
{
    return [[BouncingBallView alloc] initWithFrame:self.view.frame];
}

-(float)getUpdateInterval
{
    return 0.01f;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
