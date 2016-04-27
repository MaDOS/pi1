/*
 * Praktikum Informatik 1
 * Versuch 6.2: STL
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
	Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string date);
	int getMatNr() const;
	bool operator == (const Student& stud) const;
	bool operator < (const Student& stud) const;
	bool operator > (const Student& stud) const;
	friend std::ostream& operator << (std::ostream& out, const Student& stud);

  private:
	int matNr;
	std::string name;
	std::string firstname;
	std::string dateofbirth;
};

// Ausgabeoperator muss außerhalb der Klasse definiert sein, weil er als linken Operand
// keine Instanz der Klasse besitzt, sondern meist "cout"


#endif // STUDENT_H

