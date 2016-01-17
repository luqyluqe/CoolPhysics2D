//
//  FireViewController.m
//  CoolPhysics2DDemo
//
//  Created by luqyluqe on 12/1/14.
//  Copyright (c) 2014 luqyluqe. All rights reserved.
//

#import "HaloViewController.h"
#import "HaloView.h"

@implementation HaloViewController

-(CP2DGameView*)getGameView
{
    return [[HaloView alloc] initWithFrame:self.view.frame];
}

-(float)getUpdateInterval
{
    return 0.01f;
}

-(void)viewWillAppear:(BOOL)animated
{
    UITapGestureRecognizer* recognizer=[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapAction:)];
    [_gameView addGestureRecognizer:recognizer];
}

-(void)tapAction:(UITapGestureRecognizer*)recognizer;
{
    [(HaloView*)_gameView fire:recognizer];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
