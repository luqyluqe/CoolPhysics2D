#import "CP2DGameViewController.h"
#import "timer.h"

@interface CP2DGameViewController ()

@property (nonatomic,strong) NSTimer* renderTimer;

@property (nonatomic,assign) float updateInterval;

@end

@implementation CP2DGameViewController
{
    dispatch_source_t _updateTimer;
    dispatch_queue_t _serial_queue;
}


-(void)viewDidLoad
{
    [super viewDidLoad];
    self.gameView=[self getGameView];
    self.updateInterval=[self getUpdateInterval];
    [self.view addSubview:self.gameView];
    uint64_t intervalinNSec=(uint64_t)(_updateInterval*NSEC_PER_SEC);
    _serial_queue=dispatch_queue_create("", DISPATCH_QUEUE_SERIAL);
    self.gameView.serial_queue=_serial_queue;
    __weak typeof(self) wself=self;
    _updateTimer=CreateDispatchTimer(intervalinNSec, 0, _serial_queue, ^{
        wself.gameView.gameWorld->update(wself.updateInterval);
    });
    dispatch_resume(_updateTimer);
    self.renderTimer=[NSTimer scheduledTimerWithTimeInterval:self.updateInterval target:self selector:@selector(timerCallback) userInfo:nil repeats:YES];
}

-(void)viewDidDisappear:(BOOL)animated
{
    [self.renderTimer invalidate];
    [super viewDidDisappear:animated];
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
    [_gameView setNeedsDisplay];
}

-(void)dealloc
{
    
}

@end
