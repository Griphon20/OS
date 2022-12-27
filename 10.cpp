#include <atomic>
#include <iostream>
#include <unistd.h>
#include <thread>

std::atomic<int> sh = 0;

void my_thread0()
{
    int i = 0;

    for (; i < 1000; i++)
    {
        EnterCriticalRegion(0);
        sh.fetch_add(1, std::memory_order_relaxed); //критическая область
        LeaveCriticalRegion(0);
        usleep(1); //некритическая
    }
}

void my_thread1()
{
    int i = 0;

    for (; i < 1000; i++)
    {
        EnterCriticalRegion(1);
        sh.fetch_add(2, std::memory_order_relaxed); //критическая
        LeaveCriticalRegion(1);
        //некритическая область:
        usleep(1); // sleep(1);
    }
}

int main()
{
    std::thread th1(my_thread0);
    std::thread th2(my_thread1);
    th1.join();
    th2.join();
    std::cout << "lab 10 | sh = " << sh << std::endl;

    return 0;
}
