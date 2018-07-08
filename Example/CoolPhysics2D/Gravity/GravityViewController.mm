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

- (void)viewDidLoad
{
    [super viewDidLoad];
    UIGestureRecognizer *panRecog=[[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(pan:)];
    [self.gameView addGestureRecognizer:panRecog];
}
    
-(void)pan:(UIPanGestureRecognizer *)recognizer
{
    CGPoint translation=[recognizer translationInView:recognizer.view];
    CGRect frame = recognizer.view.frame;
    CGPoint origin=frame.origin;
    origin.x+=translation.x;
    origin.y+=translation.y;
    frame.origin=origin;
    recognizer.view.frame=frame;
    [recognizer setTranslation:CGPointZero inView:recognizer.view];
}

-(CP2DGameView*)getGameView
{
    CP2DGameView* gameView=[[GravityView alloc] initWithFrame:CGRectMake(0, 0, 2000, 2000)];
    CGSize size=self.view.bounds.size;
    gameView.center=CGPointMake(size.width/2, size.height/2);
    return gameView;
}

-(float)getUpdateInterval
{
    return 0.01f;
}

@end
