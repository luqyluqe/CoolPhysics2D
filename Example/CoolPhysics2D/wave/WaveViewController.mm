#import "WaveViewController.h"
#import "WaveView.h"

@implementation WaveViewController

-(CP2DGameView*)getGameView
{
    CP2DGameView* gameView=[[WaveView alloc] initWithFrame:self.view.frame];
    return gameView;
}

-(float)getUpdateInterval
{
    return 0.01f;
}

@end
