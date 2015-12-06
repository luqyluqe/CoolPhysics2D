//
//  ViewController.m
//  CoolPhysics2DDemo
//
//  Created by luqyluqe on 11/28/14.
//  Copyright (c) 2014 luqyluqe. All rights reserved.
//

#import "CP2DViewController.h"
#import "BouncingBallViewController.h"
#import "FireViewController.h"

@interface CP2DViewController ()

@end

@implementation CP2DViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 2;
}

-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *MyIdentifier = @"MyIdentifier";
    UITableViewCell* cell=[tableView dequeueReusableCellWithIdentifier:MyIdentifier];
    if (!cell) {
        cell=[[UITableViewCell alloc] init];
    }
    switch (indexPath.row) {
        case 0:
            cell.textLabel.text=@"Bouncing Balls";
            break;
        case 1:
            cell.textLabel.text=@"Fire";
            break;
            
        default:
            break;
    }
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    switch (indexPath.row) {
        case 0:
        {
            BouncingBallViewController* viewController=[[BouncingBallViewController alloc] init];
            [self.navigationController pushViewController:viewController animated:YES];
            break;
        }
        case 1:
        {
            FireViewController* viewController=[[FireViewController alloc] init];
            [self.navigationController pushViewController:viewController animated:YES];
        }
            
        default:
        {
            break;
        }
    }
}

@end
