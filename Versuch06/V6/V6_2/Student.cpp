/*
 * Praktikum Informatik 1
 * Versuch 6.2: STL
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
 * @param date The date of birth of the Student.
 */
Student::Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string date):
	matNr(matriculationnumber), name(name), firstname(firstname), dateofbirth(date)
{}

/**
 * @brief Gets matr. number of the student
 * @return matr. number of the student (read-only)
 */
int Student::getMatNr() const
{
	return this->matNr;
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return If two Students are the same true. Else false.
 */
bool Student::operator == (const Student& stud) const
{
	if (matNr == stud.matNr)
		return true;
	else 
		return false;
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return True: if matr of the given student is less then the one of stud(param)
 */
bool Student::operator > (const Student& stud) const
{
	if (matNr > stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return True: if matr of the given student is greater then the one of stud(param)
 */
bool Student::operator < (const Student& stud) const
{
	if (matNr < stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Output operator
 * @param stud Student to print to outstream
 */
std::ostream& operator << (std::ostream& out ,const Student& stud)
{
	out << "Matrikelnummer:" << stud.matNr << " ,Name:"<< stud.name << ", "<< stud.firstname <<", geb. am" << stud.dateofbirth;
	return out;
}

