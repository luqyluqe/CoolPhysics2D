#import <UIKit/UIKit.h>
#import "CP2DGameWorldRenderer.h"

using namespace CoolPhysics2D;

@interface CP2DGameView : UIView
{
    CP2DGameWorldRenderer* _gameWorldRenderer;
    dispatch_queue_t _serial_queue;
}

@property GameWorld* gameWorld;
@property dispatch_queue_t serial_queue;

-(UIColor*)getClearColor;

@end