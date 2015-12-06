#ifndef COOLPHYSICS2D_VECTOR_H
#define COOLPHYSICS2D_VECTOR_H

#include "config.h"
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

BEGIN_NAMESPACE_COOLPHYSICS2D

class Vector
{
public:
    //Debugging
    string description()const;
    
	//Constructor
	Vector();
	Vector(double x,double y);
	Vector(const Vector& v);
    
    //Copy constructor
	const Vector& operator =(const Vector& v);
	Vector(const Vector& v1,const Vector& v2);
    
    //Static function
    static Vector zeroVector();
    static Vector vectorMake(double modulus,double radian);
    
    //Accessor
    double x()const;
    double y()const;

    //Properties
	Vector unitVector()const;
	double modulus()const;
	double radian()const;

	//Arithmetic
	Vector operator+(const Vector& v)const;
    Vector operator-(const Vector& v)const;
	Vector operator*(double number)const;
	Vector operator/(double number)const;
	void operator+=(const Vector& v);
	double dotProductWith(const Vector& v)const;
	double crossProductWith(const Vector& v)const;
    double radianWith(const Vector& v)const;
    Vector rotate(double radian)const;

    //Transformation
    void symmetrizeAbout(const Vector& axis);
    void rotateBy(double radian);
    
    //Relation
    double componentAlongAxis(const Vector& dir)const;
    

private:
	double _x;
	double _y;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
