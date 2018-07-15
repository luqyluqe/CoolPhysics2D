//
//  FireView.m
//  CoolPhysics2DDemo
//
//  Created by luqyluqe on 12/1/14.
//  Copyright (c) 2014 luqyluqe. All rights reserved.
//

#import "HaloView.h"
#import <CoolPhysics2D/CP2DGameWorldRenderer.h>
#include <CoolPhysics2D/ParticleEmitter.h>
#include <CoolPhysics2D/GravityField.h>
#include <CoolPhysics2D/DampingField.h>

using namespace CoolPhysics2D;

@implementation HaloView

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]) {
        Rectangle range(0,0,self.frame.size.width,self.frame.size.height);
        GravityField* gravityField=new GravityField(range,Vector(0,500));
        self.gameWorld->addField(gravityField);
        DampingField* dampingField=new DampingField(range,100);
        self.gameWorld->addField(dampingField);
    }
    return self;
}

-(void)fire:(UITapGestureRecognizer*)recognizer
{
    CGPoint location=[recognizer locationInView:nil];
    ParticleEmitter* particleEmitter=new ParticleEmitter
    (
     *self.gameWorld,
     Vector(location.x,location.y),   //position
     1,               //frequency
     0,1,               //min & max life time
     Color(0.7f, 0.7f, 0, 0),Color(1,1,0.8f,0.4f), //min & max color
     0,100,               //min & max radius
     1,10,               //min & max density
     0,0,             //min & max elasticity
     0,200,           //min & max speed
     0,2*M_PI                //min & max radian
     );
    particleEmitter->enable();
    self.gameWorld->addParticleEmitter(particleEmitter);
    SEL selector=@selector(removeEmitter:);
    NSMethodSignature* signature=[HaloView instanceMethodSignatureForSelector:selector];
    NSInvocation* invocation=[NSInvocation invocationWithMethodSignature:signature];
    [invocation setSelector:selector];
    [invocation setTarget:self];
    [invocation setArgument:&particleEmitter atIndex:2];
    [NSTimer scheduledTimerWithTimeInterval:0.1 invocation:invocation repeats:NO];
}

-(void)removeEmitter:(ParticleEmitter*)emitter
{
    dispatch_async(self.serial_queue, ^{
        self.gameWorld->removeParticleEmitter(emitter);
    });
}

@end
