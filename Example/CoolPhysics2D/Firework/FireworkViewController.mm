#import "FireworkViewController.h"
#import "FireworkView.h"

@implementation FireworkViewController

-(CP2DGameView*)getGameView
{
    return [[FireworkView alloc] initWithFrame:self.view.frame];
}

-(float)getUpdateInterval
{
    return 0.01f;
}

-(void)viewWillAppear:(BOOL)animated
{
    UITapGestureRecognizer* recognizer=[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapAction:)];
    [self.gameView addGestureRecognizer:recognizer];
}

-(void)tapAction:(UITapGestureRecognizer*)recognizer;
{
    [(FireworkView*)self.gameView fire:recognizer];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end