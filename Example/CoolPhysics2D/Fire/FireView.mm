//
//  FireView.m
//  CoolPhysics2DDemo
//
//  Created by luqyluqe on 12/1/14.
//  Copyright (c) 2014 luqyluqe. All rights reserved.
//

#import "FireView.h"
#import "CP2DGameWorldRenderer.h"
#include "ParticleEmitter.h"
#include "GravityField.h"
#include "BuoyancyField.h"

using namespace CoolPhysics2D;

@implementation FireView

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]) {
        ParticleEmitter* particleEmitter=new ParticleEmitter
        (
            *self.gameWorld,
            Vector(200,400),   //position
            2000,               //frequency
            0,1,               //min & max life time
            Color(0.7, 0.7, 0, 0),Color(1,1,0.8,0.4), //min & max color
            0,5,               //min & max radius
            0,0.15,               //min & max density
            0,0,             //min & max elasticity
            50,100,           //min & max speed
            0,2*M_PI                //min & max radian
        );
        particleEmitter->enable();
        self.gameWorld->addParticleEmitter(particleEmitter);
        Rectangle range(0,0,self.frame.size.width,self.frame.size.height);
        GravityField* gravityField=new GravityField(range,Vector(0,100));
        self.gameWorld->addField(gravityField);
        BuoyancyField* buoyancyField=new BuoyancyField(range,*gravityField,1);
        self.gameWorld->addField(buoyancyField);
    }
    return self;
}

@end