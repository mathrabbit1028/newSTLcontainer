#include "TimerWind.h"
#include <Windows.h>

int64_t GetFreq(void) {
    LARGE_INTEGER freq;

    if (!QueryPerformanceFrequency(&freq))
        return 0;
    
    return freq.QuadPart;
}

int64_t GetTicks(void) {
    LARGE_INTEGER ticks;

    if (!QueryPerformanceCounter(&ticks))
        return 0;

    return ticks.QuadPart;
}