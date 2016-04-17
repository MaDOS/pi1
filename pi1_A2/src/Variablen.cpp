#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <string>

using namespace std;

int main()
{
	int iErste = 0, iZweite = 0, iSumme = 0, iQuotient = 0;
	double dSumme = 0.0f, dQuotient = 0.0f, dSummeCast = 0.0f, dQuotientCast = 0.0f;

	cout << "Zahl1: ";
	cin >> iErste;
	cout << "\n";

	cout << "Zahl2: ";
	cin >> iZweite;
	cout << "\n";

	iSumme |= iErste + iZweite;
	iQuotient = iErste / iZweite;

	dSumme = iErste + iZweite;
	dQuotient = iErste / iZweite;

	cout << "iSumme: " << iSumme << "\n";
	cout << "iQuotient: " << iQuotient << "\n";
	cout << "dSumme: " << dSumme << "\n";
	cout << "dQuotient: " << dQuotient << "\n";

	dSummeCast = (double)iErste + (double)iZweite;
	dQuotientCast = (double)iErste / (double)iZweite;

	cout << "dSumme: " << dSummeCast << "\n";
	cout << "dQuotient: " << dQuotientCast << "\n";

	string sNachname = "", sVorname = "", sNameVorname = "", sVornameName = "";

	cout << "Name: ";
	cin >> sNachname;
	cout << "\n";

	cout << "Vorname: ";
	cin >> sVorname;
	cout << "\n";

	sNameVorname = sNachname + ", " + sVorname;
	sVornameName = sVorname + " " + sNachname;

	cout << "sNameVorname: " << sNameVorname << "\n";
	cout << "sVornameName: " << sVornameName << "\n";

	{
		int iFeld[2] = {1,2};
		int Spielfeld[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

		int i;

		for(int i = 0; i < 2; i++)
		{
			cout << "iFeld[" << i << "]: " << iFeld[i] << "\n";
		}

		int x;
		int y;

		for(y = 0; y < 3; y++)
		{
			for(x = 0; x < 3; x++)
			{
				cout << "Spielfeld[" << y << "][" << x << "]: " << Spielfeld[y][x] << "\n";
			}
		}

		const int iZweite  = 1;

		cout << "iZweite (Konstante): " << iZweite << "\n";
	}

	cout << "iZweite: " << iZweite << "\n";

	return 0;
}
