/*
 * Praktikum Informatik 1
 * Versuch 6.2: STL
 *
 * Datei:  main.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"
using namespace std;

vector<Student> db;
typedef vector<Student>::iterator studIt;
studIt loopIt;

static void ausgabeListe();

int main()
{
	int input = 0;


	Student stud1(22222, "Born"      ,"Jessica", "16.03.1986");
	Student stud2(24528, "Rodenstock","Max"    , "09.02.1985");
	Student stud3(95420, "Schneider" ,"Petra"  , "29.12.1989");
	Student stud4(44523, "Baumeister","Siggi"  , "13.01.1979");
	Student stud5(12635, "Baumeister","Dinah"  , "07.06.1982");
	Student stud6(81237, "Simoneit"  ,"Harro"  , "30.10.1973");
	Student stud7(54879, "Soers"     ,"Irmchen", "01.06.1983");

	db.push_back(stud1);
	db.push_back(stud2);
	db.push_back(stud3);
	db.push_back(stud4);
	db.push_back(stud5);
	db.push_back(stud6);
	db.push_back(stud7);

	stable_sort(db.begin(), db.end());

	ausgabeListe();

	while(1)
	{
		std::cout << "Matrikelnr [#/quit=0]: " << endl;
		std:cin >> input;

		if(input == 0)
		{
			break;
		}
		else
		{

			for(loopIt = db.begin(); loopIt != db.end(); loopIt++)
			{
				if(loopIt->getMatNr() == input)
				{
					std::cout << *loopIt << endl;
					db.erase(loopIt);
					break;
				}
			}

		}

		ausgabeListe();
	}


	system("pause");
	return 0;
}

static void ausgabeListe()
{
	for(loopIt = db.begin(); loopIt != db.end(); loopIt++)
	{
		cout << *loopIt << endl;
	}
}
