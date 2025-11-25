#include "Thread.h"

// Konstruktor
Thread::Thread()
    : running(false), stopRequested(false)
{
}

// Destruktor
Thread::~Thread()
{
    requestStop();
    if (p_thread.joinable())
    {
        p_thread.join();
    }
}

// Startet den Thread
bool Thread::start()
{
    if (running) return false;

    running = true;
    stopRequested = false;

    p_thread = std::thread(&Thread::threadLoop, this);
    return true;
}

// Fordert den Thread auf zu stoppen
void Thread::requestStop()
{
    stopRequested = true;
}

// Gibt zurück, ob ein Stop angefordert wurde
bool Thread::stopRequestedFlag() const
{
    return stopRequested;
}

// Auf Thread warten
void Thread::join()
{
    if (p_thread.joinable()) 
    {
        p_thread.join();
    }
    running = false;
}

// Interne Thread-Funktion
void Thread::threadLoop()
{
    run();      // führt den überschriebenen Code aus
    running = false;
}
