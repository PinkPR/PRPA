#include "swell.hh"

Swell::Swell(float vol, float rate, float length)
     : tbb::filter(tbb::filter::serial_in_order),
       vol(vol),
       cnt(0),
       rate(rate),
       length(length)
{
    cst = M_PI / (rate * length);
}

void*
Swell::operator()(void* data)
{
    float* sample = (float*) data;

    if (cnt > M_PI)
    {
      cnt = M_PI;
      ret = true;
    }
    else if (cnt < 0)
    {
      cnt = 0;
      ret = false;
    }

    if (!ret)
      cnt += cst;
    else
      cnt -= cst;

    float* new_sample = new float(*sample);
    *new_sample *= sin(cnt);
    return new_sample;
}
