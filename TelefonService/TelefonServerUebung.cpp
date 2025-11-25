#include "TelefonbuchServer.h"
#include <iostream>
#include <filesystem>

using namespace std;
#define SERVERPORT 54321
#define SERVERIP "127.0.0.1"


int main()
{
	namespace fs = std::filesystem;
	// Mehr sollte in der main() nicht stehen!

	std::cout << "Arbeitsverzeichnis: " << fs::current_path() << std::endl;

	TelefonbuchServer* srv = new TelefonbuchServer(SERVERPORT);
	cout << "------------SERVER--------------" << endl;
	srv->start();

	



	delete srv;
	return 0;
}