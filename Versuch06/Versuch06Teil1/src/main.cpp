/*
 * Praktikum Informatik 1
 * Versuch 6.1: Templates und Überladen von Operatoren
 *
 * Datei:  main.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include <string>
#include "Student.h"
#include "StackSpeicher.h"

int main()
{
	StackSpeicher<7,Student> stack;

	Student stud1(212222, "Lustig", "Peter","1.1.11");
	Student stud2(222225, "Lustiger", "Pet","2,2,22");
	Student stud3(232228, "Lust333r", "asd","3.3.33");
	Student stud4(292465, "Lusfüger", "Pot","4.4.44");
	Student stud5(254525, "Lersuzer", "kal","5.5.55");
	Student stud6(264555, "Lustiger", "Phans","6.6.66");
	Student stud7(282225, "tiger", "Pet","7.7.77");

	stack.push(stud1);
	stack.push(stud2);
	stack.push(stud3);
	stack.push(stud4);
	stack.push(stud5);
	stack.push(stud6);
	stack.push(stud7);
	
	if (stud1 == stud2)
	{
		std::cout << "Stud1 und Stud2 sind gleich" << std::endl;
	}
	else
	{
		std::cout << "Stud1 und Stud2 sind nicht gleich" << std::endl;
	}
	
	stack.quick_sort(0,6);

	for(int i=0; i<7 ; i++)
	{
		Student pStud;
		stack.pop(pStud);
		std::cout << pStud << std::endl;
	}

	system("pause");
	return 0;
}
