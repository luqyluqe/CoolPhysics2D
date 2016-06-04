#import <UIKit/UIKit.h>
#import "CP2DGameView.h"

@interface CP2DGameViewController : UIViewController

@property (nonatomic,strong) CP2DGameView* gameView;

-(CP2DGameView*)getGameView;
-(float)getUpdateInterval;

@end
