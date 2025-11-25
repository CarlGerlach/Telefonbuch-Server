#pragma once
#include <string>
#include "List.h"

#include <mutex>
#include <fstream>
#include <sstream>

using namespace std;

class Eintrag;

// 2.2 Aufgabe
class Telefonbuch
{
private:
	int maxAnzahlEintraege;
	list <Eintrag*>telefonbuchEintraege; 
	int anzahlEintraege;
	mutex telMutex;


	

public:
	void eintragEinfuegen(Eintrag*);
	void eintragLoeschen(string);
	string nrSuche(string);
	list<Eintrag*>& getTelefonbuchEintraege();
	void sortierenNachNamen();
	void toString();

	void saveCSV(string dateiname);
	void loadCSV(string dateiname);



	Telefonbuch();
	Telefonbuch(int);
	~Telefonbuch();
};