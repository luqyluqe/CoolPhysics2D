#include "ObstacleField.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

ObstacleField::ObstacleField(const Rectangle& range):Field(range){}

ObstacleField::~ObstacleField(){}

void ObstacleField::actOn(Particle &particle)const
{
    double x=particle.position().x();
    double y=particle.position().y();
    double vx=particle.velocity().x();
    double vy=particle.velocity().y();
    double r=particle.radius();
    if (x+r>_range.x()&&x-r<_range.x()+_range.width()&&y+r>_range.y()&&y-r<_range.y()+_range.height())
    {
        if ((x+r>_range.x()&&vx>0)||(x-r<_range.x()+_range.width()&&vx<0)) {
            particle.reflectAbout(Vector(0, 1));
        }else if((y+r>_range.y()&&vy>0)||(y-r<_range.y()+_range.height()&&vy<0)){
            particle.reflectAbout(Vector(1, 0));
        }
    }
}

END_NAMESPACE_COOLPHYSICS2D