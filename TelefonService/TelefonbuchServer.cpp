#include <iostream>
#include <string>
#include <fstream>

#include "TelefonbuchServer.h"
#include "Thread.h"
#include "WorkThread.h"

using namespace std;

TelefonbuchServer::TelefonbuchServer(int port)
{
    server = new ServerSocket(port);
    cout << "Server-Konstruktor aufgerufen mit Port " << port << endl;

    cout << server << endl;

    daten = new Telefonbuch();
	daten->toString();
}

TelefonbuchServer::~TelefonbuchServer(void)
{
	delete server;
	delete daten;
}

void TelefonbuchServer::start()
{
	string anfrageName = "";
	string antwort;
	// ToDo

    cout << "start() ist ausgeführt 1" << endl;

    int currentConnected = 1;
    int overallConnected = 0;

    
 
    cout << "Load Test 1" << endl;
    daten->loadCSV(dateiname);
    cout << "Load Test 2" << endl;


    while (true)
    {
        cout << "Warten auf Client ..." << endl;

        if(currentConnected >= 3)
        {
            cout << "Aktuell zu viele Nutzer" << endl;
            
            
        }

        Socket* s = server->accept();

       // if (s != nullptr)
       // {
       //     nummer++;
       // }
       //
       // if (nummer > 3)
       // {
       //     break;
       // }

        WorkThread* work = new WorkThread(s, daten);

        threads.push_back(work);

        work->start(); 

     
         
        //if (work == NULL)
        //{
        //    cout << "Warnung: accept() fehlgeschlagen. Warte weiter..." << endl;
        //    continue;
        //}

        //while (true)
        //{
        //    bool isEXIT = false;
        //    cout << "Client verbunden. Erwartet Anfrage (Zeile) ..." << endl;

        //    // 3) Anfrage (Request) lesen
        //    anfrageName = work->readLine();
        //    cout << "Empfangen: [" << anfrageName << "]" << endl;


        //    if (anfrageName == "EXIT")
        //    {
        //        antwort = "BYE";
        //        isEXIT = true;
        //    }
        //    else if (anfrageName == "SORTIEREN")
        //    {
        //        daten->sortierenNachNamen();
        //        daten->toString();
        //        antwort = "ECHO:" + anfrageName;
        //    }
        //  
        //    else
        //    {   
        //       // cout << "test2" << endl;
        //        antwort = daten->nrSuche(anfrageName);

        //        //cout << "Test 3" << endl;

        //        cout << "Die gefundene Nummer zu: " << anfrageName << " ist: " << antwort << endl;
      
        //    }

        //    // 5) Antwort (Respons) senden - eine Zeile --> write(s: string)
        //    work->write(antwort);
        //    cout << "Antwort gesendet: [" << antwort << "]" << endl;

        //    if (isEXIT == true)
        //    {
        //        break;
        //    }
        //}

        //work->close();
    }

    for (WorkThread* w : threads)
    {
        w->join();
        delete w;
        
    }

    server->close();

    cout << "Save Test 1" << endl;
    daten->saveCSV(dateiname);    
    cout << "Save Test 2" << endl;

    cout << "Server Geschlossen" << endl;
    
}