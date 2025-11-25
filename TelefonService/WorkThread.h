#pragma once
#include "Socket.hpp"
#include "Thread.h"
#include "Telefonbuch.h"
#include <iostream>
#include <mutex>

using namespace std;

static mutex telefonbuchMutex;


class WorkThread : public Thread
{
private:
	Socket* sock;
	Telefonbuch* daten;

public:
	WorkThread(Socket* s, Telefonbuch* d);

	void run() override;

};

