#include "SimpleBenchmark.hpp"
#include <iostream>


SimpleBenchmark::SimpleBenchmark()
{
    m_startTimePoint = std::chrono::high_resolution_clock::now();
}

SimpleBenchmark::~SimpleBenchmark()
{
    Stop();
}

void SimpleBenchmark::Stop()
{
    auto endTimePoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>( m_startTimePoint ).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>( endTimePoint ).time_since_epoch().count();

    auto duration = end - start;    // duration in microsecond
    auto ms = duration * 0.001;     // duration in milisecond

    std::cout << duration << "us (" << ms << " ms)\n";
}
