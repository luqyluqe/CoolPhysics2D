#import "CP2DGameViewController.h"

@implementation CP2DGameViewController

-(void)viewDidLoad
{
    [super viewDidLoad];
    [self.view addSubview:_gameView];
    
    [NSTimer scheduledTimerWithTimeInterval:_updateInterval target:self selector:@selector(timerCallback) userInfo:nil repeats:YES];
}

-(void)timerCallback
{
    _gameView.gameWorld->update(_updateInterval);
    [_gameView setNeedsDisplay];
}

@end
