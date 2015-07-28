#include "drive.hh"

Drive::Drive(float _threshold, float _clamp)
     : tbb::filter(tbb::filter::serial_in_order),
       threshold(_threshold),
       clamp(_clamp)
{
}

Drive::~Drive()
{
}

void*
Drive::operator()(void* data)
{
    float* sample = (float*) data;
    float dist = 0.0f;

    if (*sample >= threshold)
        dist = clamp;
    else if (-*sample <= -threshold)
        dist = -clamp;

    *sample += dist;

    return sample;
}
