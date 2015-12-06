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

- (void)viewDidLoad {
    _gameView=[[BouncingBallView alloc] initWithFrame:self.view.frame];
    _updateInterval=0.01;
    [super viewDidLoad];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
