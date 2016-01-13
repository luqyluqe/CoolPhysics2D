//
//  FireViewController.m
//  CoolPhysics2DDemo
//
//  Created by luqyluqe on 12/1/14.
//  Copyright (c) 2014 luqyluqe. All rights reserved.
//

#import "HaloViewController.h"
#import "HaloView.h"

@implementation FireViewController

- (void)viewDidLoad {
    _gameView=[[HaloView alloc] initWithFrame:self.view.frame];
    _updateInterval=0.01;
    [super viewDidLoad];
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
