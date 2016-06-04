#import "CP2DGameViewController.h"
#import "timer.h"

@implementation CP2DGameViewController
{
    dispatch_source_t timer;
}

-(void)viewDidLoad
{
    [super viewDidLoad];
    _gameView=[self getGameView];
    _updateInterval=[self getUpdateInterval];
    [self.view addSubview:_gameView];
    [NSTimer scheduledTimerWithTimeInterval:_updateInterval target:self selector:@selector(timerCallback) userInfo:nil repeats:YES];
    uint64_t intervalinNSec=(uint64_t)(_updateInterval*NSEC_PER_SEC);
    timer=CreateDispatchTimer(intervalinNSec, 0, dispatch_queue_create("", DISPATCH_QUEUE_SERIAL), ^{
        _gameView.gameWorld->update(_updateInterval);
    });
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
//    _gameView.gameWorld->update(_updateInterval);
    [_gameView setNeedsDisplay];
}

-(void)dealloc
{
    
}

@end
