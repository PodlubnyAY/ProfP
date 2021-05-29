#include "timer.h"
#include <thread>
#include <chrono>
#include <functional>
void
timer(int T)
{
    std::this_thread::sleep_for(std::chrono::seconds(T));
}
