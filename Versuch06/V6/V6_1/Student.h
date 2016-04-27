/*
 * Praktikum Informatik 1
 * Versuch 6.1: Templates und Überladen von Operatoren
 *
 * Datei:  Student.h
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

/**
 * @brief Student class
 *
 * Implements representation of a single student; overloads comparison and output operators for comparison by martr. number
 */
class Student
{
  public:
	Student();
	Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string birthdate);
	bool operator == (const Student& stud);
	bool operator <= (const Student& stud);
	bool operator >= (const Student& stud);
	friend std::ostream& operator << (std::ostream& in,Student& stud);
	
  private:
	int matNr;
	std::string name;
	std::string firstname;
	std::string birthdate;
};

#endif // STUDENT_H

