#import "CP2DGameViewController.h"

@implementation CP2DGameViewController

-(void)viewDidLoad
{
    [super viewDidLoad];
    _gameView=[self getGameView];
    _updateInterval=[self getUpdateInterval];
    [self.view addSubview:_gameView];
    [NSTimer scheduledTimerWithTimeInterval:_updateInterval target:self selector:@selector(timerCallback) userInfo:nil repeats:YES];
}

-(CP2DGameView*)getGameView
{
    return nil;
}

-(float)getUpdateInterval
{
    return 100;
}

-(void)timerCallback
{
    _gameView.gameWorld->update(_updateInterval);
    [_gameView setNeedsDisplay];
}

@end
