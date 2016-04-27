//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 04: Einführung in die Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vector.h"
#include <iostream>
#include <cmath>

Vector::Vector(double inX, double inY, double inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

Vector::~Vector()
{
}

double Vector::getX()
{
	return this->x;
}

double Vector::getY()
{
	return this->y;
}

double Vector::getZ()
{
	return this->z;
}

double Vector::abs()
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

void Vector::subtract(Vector v)
{
	this->x -= v.getX();
	this->y -= v.getY();
	this->z -= v.getZ();
}
void Vector::printVals()
{
	std::cout << "X: " << this->x << std::endl << "Y: " << this->y << std::endl << "Z: " << this->z << std::endl;
}

Vector Vector::rotate(Vector v, double radiants)
{
	double newX,newY,newZ;

	newX=cos(radiants)*v.getX()-sin(radiants)*v.getY();
	newY=sin(radiants)*v.getX()+cos(radiants)*v.getY();
	newZ=v.getZ();

	return Vector(newX, newY, newZ);
}

Vector Vector::add(Vector v1, Vector v2)
{
	return Vector(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}

double Vector::scalarProd(Vector v1, Vector v2)
{
	return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

bool Vector::isOrthogonal(Vector v1, Vector v2)
{
	//Einzeiler
	//return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) == 0 ? true : false;
	if(scalarProd(v1,v2) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}



