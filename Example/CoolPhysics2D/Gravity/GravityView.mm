//
//  GravityView.m
//  CoolPhysics2D_Example
//
//  Created by gouchen on 2018/7/1.
//  Copyright © 2018 luqyluqe. All rights reserved.
//

#import "GravityView.h"
#include "CentripetalGravityField.h"

@implementation GravityView

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]) {
        Rectangle range(-10000,-10000,20000,20000);
        self.gameWorld=new GameWorld(range);
        CGSize size=self.bounds.size;
        Vector center(size.width/2.,size.height/2);
        double gravity=1000;

        Particle* p0=new Particle(false,20,100,0.4,center,Vector(0,0),Vector(0,0),10000,Color::yellowColor);
        self.gameWorld->addParticle(p0);
        Field* gravityField0=new CentripetalGravityField(range,p0,gravity);
        self.gameWorld->addField(gravityField0);

        Particle* p1=new Particle(false,5,10,0.8,center+Vector(0,200),Vector(20,0),Vector(0,0),10000,Color::blueColor);
        self.gameWorld->addParticle(p1);
        Field* gravityField1=new CentripetalGravityField(range,p1,gravity);
        self.gameWorld->addField(gravityField1);

        Particle* p2=new Particle(false,2,1,0.9,center+Vector(0,220),Vector(40,0),Vector(0,0),10000,Color::whiteColor);
        self.gameWorld->addParticle(p2);
        Field* gravityField2=new CentripetalGravityField(range,p2,gravity);
        self.gameWorld->addField(gravityField2);
        
//        CGSize size=self.bounds.size;
//        Rectangle range(0,0,size.width,size.height);
//        self.gameWorld=new GameWorld(range);
//        Vector center(size.width/2.,size.height/2);
//        double gravity=1000000;
//
//        Particle* p0=new Particle(false,40,1,1,center,Vector(0,0),Vector(0,0),10000,Color::yellowColor);
//        self.gameWorld->addParticle(p0);
//        Field* gravityField0=new CentripetalGravityField(range,p0,gravity);
//        self.gameWorld->addField(gravityField0);
//
//        Particle* p1=new Particle(false,40,1,1,center+Vector(0,200),Vector(20,0),Vector(0,0),10000,Color::blueColor);
//        self.gameWorld->addParticle(p1);
//        Field* gravityField1=new CentripetalGravityField(range,p1,gravity);
//        self.gameWorld->addField(gravityField1);
//
//        Particle* p2=new Particle(false,40,1,1,center+Vector(0,-200),Vector(40,0),Vector(0,0),10000,Color::whiteColor);
//        self.gameWorld->addParticle(p2);
//        Field* gravityField2=new CentripetalGravityField(range,p2,gravity);
//        self.gameWorld->addField(gravityField2);
    }
    return self;
}

@end
