//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 04: Einführung in die Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include "Vector.h"
#include <cmath>

#define PI 3.14159265358979323846

static double horizonDistance(double height);

int main()
{ 
	double height = 0;

	std::cout << "Distanz bis zum Horinzont bei einer höhe von: " << std::endl;
	std::cin >> height;

	std::cout << std::endl << "ist: " << horizonDistance(height) << std::endl;

	return 0;
}

double horizonDistance(double height)
{
	double dist = 0;

	Vector radius = Vector(6371000, 0, 0);	Vector viewer = Vector(0, 6371000 + height, 0);

	Vector rayCast = viewer;
	rayCast.subtract(radius);

	double precision = 10000000; //higher is better
	double stepDegrees = PI / (2 * precision);
	double threshold = 0.01l;
	double angle = 0;

	while(Vector::scalarProd(rayCast,radius) < 0)
	{
		//std::cout << "Skalarprod: " << Vector::scalarProd(rayCast,radius) << std::endl;
		//std::cout << "Dist: " << rayCast.abs() << std::endl;
		//std::cout << "Angle: " << angle << std::endl;

		angle = angle + stepDegrees;

		radius = Vector::rotate(radius, stepDegrees);

		rayCast = viewer;
		rayCast.subtract(radius);
	}

	dist = rayCast.abs();

	return dist;
}
*/
