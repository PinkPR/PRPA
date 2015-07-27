#include "reverb.hh"

Reverb::Reverb(float vol, float decay)
     : tbb::filter(tbb::filter::serial_in_order),
       volume(vol),
       cnt(0),
       decay(decay),
       old_sample(0)
{}

Reverb::~Reverb()
{}

void*
Reverb::operator()(void* data)
{
    float* sample = (float*) data;
    float* new_sample = new float(*sample);
    old_sample = *sample + old_sample * decay;
    *new_sample += old_sample * volume;
    return new_sample;
}
