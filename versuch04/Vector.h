//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 04: Einführung in die Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#ifndef Vector_H
#define Vector_H

class Vector
{
   public: //konstruktor/destruktor
      Vector(double x, double y, double z);
      ~Vector();

   private: //member
      double x;
      double y;
      double z;

   public:
      double getX();
      double getY();
      double getZ();
      double abs();
      void subtract(Vector v);
      void printVals();

      static Vector rotate (Vector v, double radiants);
      static Vector add (Vector v1, Vector v2);
      static double scalarProd (Vector v1, Vector v2);
      static bool isOrthogonal (Vector v1, Vector v2);


};

#endif
