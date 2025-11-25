#include "Telefonbuch.h"
#include "Eintrag.h"
#include <iostream>
#include <algorithm>  // für std::sort
using namespace std;

// --- Konstruktoren ---
Telefonbuch::Telefonbuch()
{

    anzahlEintraege = 3;
    maxAnzahlEintraege = 10;

    // Standardeinträge
    Eintrag* tmp0 = new Eintrag("Betty", "123");
    eintragEinfuegen(tmp0);
    Eintrag* tmp1 = new Eintrag("Anton", "456");
    eintragEinfuegen(tmp1);
    Eintrag* tmp2 = new Eintrag("Cesar", "789");
    eintragEinfuegen(tmp2);

}

Telefonbuch::Telefonbuch(int anzahl)
{
    maxAnzahlEintraege = anzahl;
    anzahlEintraege = 0;

    // Standardeinträge
    Eintrag* tmp0 = new Eintrag("Betty", "123");
    eintragEinfuegen(tmp0);
    Eintrag* tmp1 = new Eintrag("Anton", "456");
    eintragEinfuegen(tmp1);
    Eintrag* tmp2 = new Eintrag("Cesar", "789");
    eintragEinfuegen(tmp2);
}

Telefonbuch::~Telefonbuch()
{

}



// --- Eintrag einfügen ---
void Telefonbuch::eintragEinfuegen(Eintrag* e) {
    if (anzahlEintraege >= maxAnzahlEintraege) {
        cout << "Telefonbuch ist voll!" << endl;
        return;
    }

    // Prüfen, ob Name bereits existiert
    for (Eintrag* eintrag : telefonbuchEintraege) {
        if (eintrag->getName() == e->getName()) {
            cout << "Eintrag mit diesem Namen existiert bereits!" << endl;
            return;
        }
    }

    telefonbuchEintraege.push_back(e);
    anzahlEintraege++;
}

// --- Eintrag löschen ---
void Telefonbuch::eintragLoeschen(string name) {
    // Wir brauchen Iterator, da wir Elemente löschen
    for (auto it = telefonbuchEintraege.begin(); it != telefonbuchEintraege.end(); ++it) {
        Eintrag* e = *it;
        if (e->getName() == name) {
            delete e;                          // Speicher freigeben
            telefonbuchEintraege.erase(it);    // Aus Liste entfernen
            anzahlEintraege--;
            cout << "Eintrag gelöscht: " << name << endl;
            return;
        }
    }
    cout << "Kein Eintrag mit dem Namen \"" << name << "\" gefunden." << endl;
}

// --- Telefonnummer anhand des Namens suchen ---
string Telefonbuch::nrSuche(string name)
{
    for (Eintrag* e : telefonbuchEintraege)
    {
        if (!e) continue;  // Schützt vor Null-Zeigern

        if (e->getName() == name)
            return e->getNr();
    }
    return "UNWNOWN";
}


// --- Zugriff auf die Liste ---
list<Eintrag*>& Telefonbuch::getTelefonbuchEintraege() {
    return telefonbuchEintraege;
}

// --- Sortieren nach Namen ---
void Telefonbuch::sortierenNachNamen() {
    // Nur möglich, wenn List begin()/end() und random-access Sort unterstützt
    telefonbuchEintraege.sort([](Eintrag* a, Eintrag* b) {
        return a->getName() < b->getName();
       });
}

// --- Ausgabe aller Einträge ---
void Telefonbuch::toString()
{
    cout << "-----Telefonbucheintraege--------" << endl;

    for (Eintrag*& elem : telefonbuchEintraege)
    {
        std::cout << elem->getName() << " " << elem->getNr() << std::endl;
    }
    cout << endl;
}



