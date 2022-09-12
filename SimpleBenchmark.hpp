#pragma once

#include <chrono>


class SimpleBenchmark
{
public:
    SimpleBenchmark();
    ~SimpleBenchmark();
    void Stop();
    double GetDurationMicroSec();
    double GetDurationMiliSec();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
};