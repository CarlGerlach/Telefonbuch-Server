#include "workThread.h"
#include "Eintrag.h"

WorkThread::WorkThread(Socket* s, Telefonbuch* d)
{
	this->sock = s;
	this->daten = d;
}

void WorkThread::run()
{
	
	while (!stopRequestedFlag())
	{
		while (!sock->dataAvailable())
		{
			if (stopRequestedFlag())
			{
				//sock->close();
				//delete sock;
				break;
			}
		}

		//cout << "Test1" << endl;
		
		string response = "";

		//request scheme -> [REQUEST];[NAME];[NUMBER]
		string text = sock->readLine();

		//REQUEST
		string request = text.substr(0, text.find(" "));
		text = text.substr(text.find(" ") + 1);


		if (request == "EXIT")
		{
			break;
		}


		//NAME
		string name = text.substr(0, text.find(" "));
		text = text.substr(text.find(" ") + 1);

		//NUMBER
		string number = text;

		cout << "Name1: " << name << endl;
		cout << "TEL1: " << number << endl;

		//cout << "Request: " << request << endl;

		//cout << "Request: " << request << endl;
		//cout << "Name: " << name << endl;
		//cout << "Tel.: " << number << endl;

		//cout << "Test2" << endl;

		if (request == "HILFE")
		{
			/*response = "HILFE - Gibt alle verfügbaren Befehle aus\n";
			response += "LIST - Gibt das Telefonbuch aus\n";
			response += "ADD - Fügt einen Eintrag hinzu -> [ADD] [NAME] [TEL]\n";
			response += "DELETE - Löscht einen Eintrag -> [DELETE] [NAME]\n";
			response += "SUCHE - Sucht nach einem Nutzer -> [SUCHE] [NAME]\n";*/

			response =
				"HILFE - Gibt alle verfügbaren Befehle aus | "
				"LIST - Gibt das Telefonbuch aus | "
				"ADD - Fügt einen Eintrag hinzu -> [ADD] [NAME] [TEL] | "
				"DELETE - Löscht einen Eintrag -> [DELETE] [NAME] | "
				"SUCHE - Sucht nach einem Nutzer -> [SUCHE] [NAME]";
		}

		else if (request == "LIST")
		{
			for (Eintrag* e : daten->getTelefonbuchEintraege())
			{
				response += e->getName() + " : " + e->getNr() + '\t';
			}
		}

		else if (request == "ADD")
		{
			cout << "Name2: " << name << endl;
			cout << "TEL2: " << number << endl;

			cout << "Eintrag hinzugefuegt" << endl;

			response = "Eintrag hinzugefuegt";

			daten->eintragEinfuegen(new Eintrag(name, number));
		}

		else if (request == "DELETE")
		{
			daten->eintragLoeschen(name);
			cout << "Eintrag gelöscht" << endl;

			response = "Eintrag gelöscht";
		}

		else if (request == "SUCHE")
		{
			response = name + " : ";
			response += daten->nrSuche(name);
		}

		else
		{
			response = "Fehler: Ungueltiger Befehl";
		}
		
		//cout << "Resp: " << response;
		sock->write(response);
		//cout << "Test3" << endl;


		//Sleep(10000);
		cout << "Thread läuft" << endl;
	}

	//cout << "Test4" << endl;

	sock->close();
	delete sock;
	cout << "Socket geschlossen" << endl;
	

}


