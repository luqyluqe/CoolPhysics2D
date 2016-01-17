#import <QuartzCore/QuartzCore.h>

@protocol CP2DRenderer

@required
-(void)renderInContext:(CGContextRef)context;

@end
