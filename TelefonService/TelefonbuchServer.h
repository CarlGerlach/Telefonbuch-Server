#pragma once
#include "ServerSocket.hpp"
#include "Telefonbuch.h"
#include <vector>

// 2.5 Aufgabe
class TelefonbuchServer
{
private:
	ServerSocket *server;
	Telefonbuch *daten;
	vector<WorkThread*> threads;

public:
	void start();
	TelefonbuchServer(int);
	~TelefonbuchServer();
};