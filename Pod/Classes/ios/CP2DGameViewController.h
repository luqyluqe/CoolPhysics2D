//
//  CP2DGameViewController.h
//  CoolPhysics2DDemo
//
//  Created by JIRENTIANXIANG on 12/1/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CP2DGameView.h"

@interface CP2DGameViewController : UIViewController
{
    CP2DGameView* _gameView;
    double _updateInterval;
}

@end
