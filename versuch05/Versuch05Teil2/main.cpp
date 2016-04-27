/**
 * @file main.cpp
 * content: main routine
 */

/**
 * @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 5.2: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include "List.h"
#include "Student.h"

int main()
{
	List testListe;
	Student stud1;

	char abfrage;
	std::cout << "Wollen sie die Liste selbst fuellen? (j)/(n) ";
	std::cin >> abfrage;

	if (abfrage != 'j')
	{
		stud1.matNr = 12345;
		stud1.adresse = "Ahornst.55";
		stud1.date_of_birth = "23.04.1983";
		stud1.name = "Siggi Baumeister";
		testListe.enqueue_head(stud1);
		stud1.matNr = 23456;
		stud1.adresse = "Wuellnerstr.9";
		stud1.date_of_birth = "15.10.1963";
		stud1.name = "Walter Rodenstock";
		testListe.enqueue_head(stud1);
		stud1.matNr = 34567;
		stud1.adresse = "Am Markt 1";
		stud1.date_of_birth = "19.06.1971";
		stud1.name = "Harro Simoneit";
		testListe.enqueue_head(stud1);
	}

	do
	{
		std::cout << "\nMenue:" << std::endl << "-----------------------------" << std::endl
			 << "(1): Datenelement vorne ergaenzen" << std::endl
			 << "(2): Datenelement abhaengen" << std::endl
			 << "(3): Datenbank ausgeben vorwärts" << std::endl
			 << "(4): Datenbank ausgeben rückwärts" << std::endl
			 << "(5): Eintrag durch Matrikelnr löschen" << std::endl
			 << "(6): Datenelement hinten ergaenzen" << std::endl
			 << "(7): Beenden" << std::endl;
		std::cin >> abfrage;

		switch (abfrage)
		{
			case '1':
				std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
				std::cin.ignore(10, '\n'); // Ignoriere das Zeichen '\n', das noch im Puffer ist
				std::getline(std::cin, stud1.name);  // ganze Zeilen einlesen, inkl Leerzeichen
				std::cout << "Geburtsdatum: ";
				std::getline(std::cin, stud1.date_of_birth);
				std::cout << "Adresse: ";
				std::getline(std::cin, stud1.adresse);
				std::cout << "Matrikelnummer: ";
				std::cin >> stud1.matNr;
				testListe.enqueue_head(stud1);
				break;

			case '2':
				std::cout << "Das hintere Datenelemt wird abgehangen\n";
				testListe.dequeue(stud1);
				break;

			case '3':
				std::cout << "Inhalt der Liste von vorne nach hinten\n";
				testListe.print_forwards();
				break;

			case '4':
				std::cout << "Inhalt der Liste von hinten nach vorn\n";
				testListe.print_backwards();
				break;

			case '5':
				int lNr;
				std::cout << "Matrikelnummer des zulöschenden eintrages eingeben:";
				std::cin >>lNr;
				testListe.delete_element(lNr);
				break;

			case '6':
				std::cout << "Der folgende Student wird am Ende der Liste eingefügt." << std::endl
						  << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
				std::cin.ignore(10, '\n'); // Ignoriere das Zeichen '\n', das noch im Puffer ist
				std::getline(std::cin, stud1.name);  // ganze Zeilen einlesen, inkl Leerzeichen
				std::cout << "Geburtsdatum: ";
				std::getline(std::cin, stud1.date_of_birth);
				std::cout << "Adresse: ";
				std::getline(std::cin, stud1.adresse);
				std::cout << "Matrikelnummer: ";
				std::cin >> stud1.matNr;
				testListe.enqueue_tail(stud1);
				break;

			case '7':
				std::cout << "Das Programm wird nun beendet";
				break;

			default :
				std::cout << "Falsche Eingabe, bitte nochmal";
		}
	}
	while (abfrage != '7');

	return 0;
}
