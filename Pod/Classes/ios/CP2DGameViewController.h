#import <UIKit/UIKit.h>
#import "CP2DGameView.h"

@interface CP2DGameViewController : UIViewController
{
    CP2DGameView* _gameView;
    float _updateInterval;
}

-(CP2DGameView*)getGameView;
-(float)getUpdateInterval;

@end
