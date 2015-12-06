//
//  GameView.m
//  BouncingCP2DParticleRenderer
//
//  Created by luqyluqe on 11/21/14.
//  Copyright (c) 2014 luqyluqe. All rights reserved.
//

#import "BouncingBallView.h"

#include "Vector.h"
#import "CP2DParticleRenderer.h"
#include "Field.h"
#include "DampingField.h"
#include "GravityField.h"
#include "BuoyancyField.h"
#include "CP2DGameWorldRenderer.h"
#include "Color.h"

@implementation BouncingBallView

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]) {
        Rectangle water(0,400,self.frame.size.width,self.frame.size.height-400);
        Field* dampingField=new DampingField(water,-1.5);
        self.gameWorld->addField(dampingField);
        GravityField* gravityField=new GravityField(Rectangle(0,0,self.frame.size.width,self.frame.size.height),Vector(0, 1000));
        self.gameWorld->addField(gravityField);
        Field* buoyancyField=new BuoyancyField(water,*gravityField,0.0002);
        self.gameWorld->addField(buoyancyField);
        
        Particle* _particle0=new Particle(false,50,1,0.95,Vector(0,0),Vector(500,0),Vector(0,0),10000,Color::blueColor);
        Particle* _particle1=new Particle(false,30,0.5,0.99,Vector(300,100),Vector(-400,0),Vector(0,0),10000,Color::redColor);
        Particle* _particle2=new Particle(false,40,0.8,0.98,Vector(200,300),Vector(500,0),Vector(0,0),10000,Color::greenColor);
        
        self.gameWorld->addParticle(_particle0);
        self.gameWorld->addParticle(_particle1);
        self.gameWorld->addParticle(_particle2);
        
        
    }
    return self;
}

-(void)drawRect:(CGRect)rect
{
    CGContextRef ctx=UIGraphicsGetCurrentContext();
    CGContextClearRect(ctx, self.frame);
    UIBezierPath *square = [UIBezierPath bezierPathWithRect:CGRectMake(0, 400, self.frame.size.width, self.frame.size.height-400)];
    CGContextSetRGBFillColor(ctx, 0, 0, 1, 0.4);
    [square fill];
    [square stroke];
    
    _gameWorldRenderer=[[CP2DGameWorldRenderer alloc] initWithGameWorld:self.gameWorld];
    [_gameWorldRenderer renderInContext:ctx];
}

@end
