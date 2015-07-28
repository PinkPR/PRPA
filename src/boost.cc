#include "boost.hh"

Boost::Boost(float val)
     : tbb::filter(tbb::filter::serial_in_order),
       value(val)
{
}

Boost::~Boost()
{
}

void*
Boost::operator()(void* data)
{
    float* sample = (float*) data;

    *sample *= 1.0 + value;

    return sample;
}
