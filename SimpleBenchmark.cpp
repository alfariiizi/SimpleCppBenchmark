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
    std::cout << this->GetDurationMicroSec() << "us (" << this->GetDurationMiliSec() << " ms)\n";
}

double SimpleBenchmark::GetDurationMicroSec()
{
    auto endTimePoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>( m_startTimePoint ).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>( endTimePoint ).time_since_epoch().count();

    auto duration = end - start;    // duration in microsecond

    return duration;
}

double SimpleBenchmark::GetDurationMiliSec()
{
    auto ms = this->GetDurationMicroSec() * 0.001;     // duration in milisecond
    return ms;
}