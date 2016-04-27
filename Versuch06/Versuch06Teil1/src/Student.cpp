/*
 * Praktikum Informatik 1
 * Versuch 6.1: Templates und Überladen von Operatoren
 *
 * Datei:  Student.cpp
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 */

#include "Student.h"

/**
 * @brief Standard constructor
 */
Student::Student()
{
	matNr = 0;
}

/**
 * @brief Constructor
 * @param matriculationnumber The matriculation number of the student.
 * @param name The name of the Student.
 * @param firstname The first name of the Student.
 */
Student::Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string birthdate):
	matNr(matriculationnumber), name(name), firstname(firstname), birthdate(birthdate)
{
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return If two Students are the same true. Else false.
 */
bool Student::operator == (const Student& stud)
{
	if (matNr == stud.matNr)
		return true;
	else 
		return false;
}

// Insert your implementation here
bool Student::operator >= (const Student& stud)
{
	if (matNr >= stud.matNr)
		return true;
	else
		return false;
}
bool Student::operator <= (const Student& stud)
{
	if (matNr <= stud.matNr)
		return true;
	else
		return false;
}
std::ostream& operator << (std::ostream& in ,Student& stud)
{
	in << "Matrikelnummer:" << stud.matNr << " ,Name:"<< stud.name << ", "<< stud.firstname <<", geb. am" << stud.birthdate;
	return in;
}

