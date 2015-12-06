#include "Vector.h"
#include <math.h>

BEGIN_NAMESPACE_COOLPHYSICS2D

Vector::Vector():_x(0),_y(0){}

Vector::Vector(double px,double py):_x(px),_y(py){}

Vector::Vector(const Vector& v):_x(v._x),_y(v._y){}

const Vector& Vector::operator =(const Vector& v)
{
	_x=v._x;
	_y=v._y;
	return *this;
}

Vector::Vector(const Vector& v1,const Vector& v2)
{
	Vector();
	_x=v2._x-v1._x;
	_y=v2._y-v1._y;
}

Vector Vector::zeroVector()
{
    return Vector(0,0);
}
Vector Vector::vectorMake(double modulus, double radian)
{
    return Vector(modulus*cos(radian),modulus*sin(radian));
}

double Vector::x()const
{
    return _x;
}
double Vector::y()const
{
    return _y;
}

double Vector::modulus()const
{
    return sqrt(_x*_x+_y*_y);
}

Vector Vector::unitVector()const
{
	double mod=modulus();
	return Vector(_x/mod,_y/mod);
}

double Vector::radian()const
{
	double mod=modulus();
    if(_y>=0)
    {
        return acos(_x/mod);
    }
    else
    {
        return -acos(_x/mod);
    }
}

double Vector::dotProductWith(const Vector& v)const
{
	return _x*v._x+_y*v._y;
}

double Vector::crossProductWith(const Vector& v)const
{
	return _x*v._y-_y*v._x;
}



double Vector::radianWith(const Vector &v)const
{
    double result=acos(dotProductWith(v)/modulus()*v.modulus());
    if (this->crossProductWith(v)<0)
    {
    	result=-result;
    }
    return result;
}

Vector Vector::rotate(double radian)const
{
    Vector v=*this;
    v.rotateBy(radian);
    return v;
}

Vector Vector::operator+(const Vector& v)const
{
	return Vector(_x+v._x,_y+v._y);
}
Vector Vector::operator-(const Vector& v)const
{
    return Vector(_x-v._x,_y-v._y);
}
Vector Vector::operator*(double number)const
{
	return Vector(_x*number,_y*number);
}
Vector Vector::operator/(double number)const
{
	return Vector(_x/number,_y/number);
}
void Vector::operator+=(const Vector& v)
{
	_x+=v._x;
	_y+=v._y;
}

void Vector::symmetrizeAbout(const Vector& axis)
{
	double radian=this->radianWith(axis);
	rotateBy(radian*2);
}

void Vector::rotateBy(double rad)
{
	double r=radian();
	r+=rad;
    double mod=modulus();
	_x=mod*cos(r);
	_y=mod*sin(r);
}

double Vector::componentAlongAxis(const Vector &dir)const
{
    Vector u=dir.unitVector();
    return u.dotProductWith(*this);
}

string Vector::description()const
{
	stringstream ss;
	ss<<"("<<_x<<" "<<_y<<")";
	return ss.str();
}

END_NAMESPACE_COOLPHYSICS2D
