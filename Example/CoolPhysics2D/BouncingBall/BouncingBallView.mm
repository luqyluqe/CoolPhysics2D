//
//  GameView.m
//  BouncingCP2DParticleRenderer
//
//  Created by luqyluqe on 11/21/14.
//  Copyright (c) 2014 luqyluqe. All rights reserved.
//

#import "BouncingBallView.h"

#include <CoolPhysics2D/Vector.h>
#import <CoolPhysics2D/CP2DParticleRenderer.h>
#include <CoolPhysics2D/Field.h>
#include <CoolPhysics2D/DampingField.h>
#include <CoolPhysics2D/GravityField.h>
#include <CoolPhysics2D/BuoyancyField.h>
#include <CoolPhysics2D/CP2DGameWorldRenderer.h>
#include <CoolPhysics2D/Color.h>

@implementation BouncingBallView

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]) {
        Rectangle water(0,400,self.frame.size.width,self.frame.size.height-400);
        Field* dampingField=new DampingField(water,-1.5);
        self.gameWorld->addField(dampingField);
        GravityField* gravityField=new GravityField(Rectangle(0,0,self.frame.size.width,self.frame.size.height),Vector(0, 500));
        self.gameWorld->addField(gravityField);
        Field* buoyancyField=new BuoyancyField(water,*gravityField,0.0002);
        self.gameWorld->addField(buoyancyField);
        
        Particle* particle0=[self buildParticle0];
        Particle* particle1=[self buildParticle1];
        Particle* particle2=[self buildParticle2];
        
        self.gameWorld->addParticle(particle0);
        self.gameWorld->addParticle(particle1);
        self.gameWorld->addParticle(particle2);
    }
    return self;
}

-(Particle*)buildParticle0
{
    ParticleBuilder builder;
    return builder
        .overlappable(false)
        .radius(50)
        .mass(1)
        .elasticity(0.95)
        .position(Vector(0,0))
        .velocity(Vector(500,0))
        .acceleration(Vector(0,0))
        .lifetime(10000)
        .color(Color::blueColor)
        .build();
}

-(Particle*)buildParticle1
{
    ParticleBuilder builder;
    return builder
        .overlappable(false)
        .radius(30)
        .mass(0.5)
        .elasticity(0.99)
        .position(Vector(300,100))
        .velocity(Vector(-400,0))
        .acceleration(Vector(0,0))
        .lifetime(10000)
        .color(Color::redColor)
        .build();
}

-(Particle*)buildParticle2
{
    ParticleBuilder builder;
    return builder
        .overlappable(false)
        .radius(40)
        .mass(0.8)
        .elasticity(0.98)
        .position(Vector(200,300))
        .velocity(Vector(500,0))
        .acceleration(Vector(0,0))
        .lifetime(10000)
        .color(Color::greenColor)
        .build();
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
