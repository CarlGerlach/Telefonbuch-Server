#pragma once
#include <thread>
#include <atomic>

class Thread
{
private:
    std::thread p_thread;
    std::atomic<bool> running;
    std::atomic<bool> stopRequested;

    void threadLoop();

public:
    Thread();
    virtual ~Thread();

    virtual void run() = 0;

    virtual bool start();
    void requestStop();
    bool stopRequestedFlag() const;

    void join();
};
