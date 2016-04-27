//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 04: Einführung in die Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include "Vector.h"
#include <cmath>
#include <ctime>
#include <iomanip> 

#define PI 3.14159265358979323846

static double horizonDistance(double height, double precision);
static double horizonDistanceSlow(double height);
static double horizonDistanceRec(double height, double precision, double stepDegrees, double lastDist, Vector radius);
static double horizonDistCheck(double height);

int main()
{ 
	double height = 0;
	double precision = 1;

	std::cout << "Distanz bis zum Horinzont bei einer höhe von [m]: ";
	std::cin >> height;

	std::cout << "Präzision der Berechnung [BSP: 0.1]: ";
	std::cin >> precision;

    //Calc postCommaPrecision
    double postCommaPrecision = 0;
    double tempPrecision = precision;
    while(tempPrecision < 1)
    {
        postCommaPrecision++;
        tempPrecision *= 10;
    }

    std::cout << std::endl;


    //Iterative
    time_t start;
    time_t stop;
    time(&start);
    double horizonDist = horizonDistance(height, precision);
    time(&stop);
    
    float timeIt = (float)(stop - start);

    //Recursive
    time(&start);
    double horizonDistRec = horizonDistanceRec(height, precision, PI/3, 0, Vector(6371000, 0, 0));
    time(&stop);
    
    float timeRec = (float)(stop - start);

    //Calc preCommaDigitsCount
    double preCommaDigitsCount = 0;
    double tempDist = horizonDist;
    while(tempDist > 1)
    {
        preCommaDigitsCount++;
        tempDist = tempDist / 10;
    }

    double coutPrecision = preCommaDigitsCount + postCommaPrecision + 1; //+1 Punkt scheint als precision-"char" mit zu zählen

    std::cout << std::setprecision(coutPrecision) << "ist(iterativ):  \t" << horizonDist << "m" << " ### Berechnet in: " << timeIt << std::endl;
	std::cout << std::setprecision(coutPrecision) << "ist(rekursiv):  \t" << horizonDistRec << "m" << " ### Berechnet in: " << timeRec << std::endl;
	std::cout << std::setprecision(coutPrecision) << "sollte: \t" << horizonDistCheck(height) << "m" << std::endl;

    system("pause");

	return 0;
}

static double horizonDistance(double height, double precision)
{
	Vector radius = Vector(6371000, 0, 0);
	Vector viewer = Vector(0, 6371000 + height, 0);

	Vector rayCast = viewer;
	rayCast.subtract(radius);

	double currentPrecision = precision + 1;
	double stepDegrees = PI / 3;

	double lastDist = 0;
	double currentDist = 0;

	while(true)
	{
		//DEBUG----
		//std::cout << "Skalarprod: " << Vector::scalarProd(rayCast,radius) << std::endl;
		//std::cout << "Dist: " << rayCast.abs() << std::endl;
		//std::cout << "Angle: " << angle << std::endl;

		//angle = angle + stepDegrees;
		//----------

		lastDist = currentDist;

		rayCast = viewer;
		rayCast.subtract(radius);

		if(Vector::scalarProd(radius,rayCast) < 0)
		{
			radius = Vector::rotate(radius, stepDegrees);
		}
		else if(Vector::scalarProd(radius,rayCast) > 0)
		{
			radius = Vector::rotate(radius, -stepDegrees);
		}

		rayCast = viewer;
		rayCast.subtract(radius);

		currentDist = rayCast.abs();
		currentPrecision = sqrt(pow((lastDist - currentDist), 2));

		if(currentPrecision < precision)
		{
			break;
		}

		stepDegrees = stepDegrees / 2;
	}


	return currentDist;
}

static double horizonDistanceRec(double height, double precision, double stepDegrees, double lastDist, Vector radius)
{
	Vector viewer = Vector(0, 6371000 + height, 0);

	Vector rayCast = viewer;
	rayCast.subtract(radius);

	double currentDist = rayCast.abs();
	double currentPrecision = sqrt(pow((lastDist - currentDist), 2)); //pow + sqrt = betrag

	if(currentPrecision < precision)
	{
		return currentDist;
	}
	if(Vector::scalarProd(radius,rayCast) < 0)
	{
        Vector newradius = Vector::rotate(radius, stepDegrees);
		return horizonDistanceRec(height,precision,stepDegrees/2,currentDist,newradius);
	}
	else if(Vector::scalarProd(radius,rayCast) > 0)
	{
        Vector newradius = Vector::rotate(radius, -stepDegrees);
		return horizonDistanceRec(height,precision,stepDegrees/2,currentDist,newradius);
	}
}

static double horizonDistanceSlow(double height)
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

static double horizonDistCheck(double height)
{
	return sqrt(pow(6371000 + height, 2) - pow(6371000, 2));
}
