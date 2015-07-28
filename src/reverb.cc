#include <iostream>

#include "reverb.hh"

Reverb::Reverb(float vol, float decay_)
     : tbb::filter(tbb::filter::serial_in_order),
       volume(vol),
       cnt(0),
       decay(decay_),
       old_sample(0.0f)
{
    std::cout << "Reverb" << std::endl;
    std::cout << "decay : " << decay << std::endl;
}

Reverb::~Reverb()
{}

void*
Reverb::operator()(void* data)
{
    float* sample = (float*) data;
    float* new_sample = new float(*sample);
    *new_sample += old_sample * volume;
    old_sample = *sample + old_sample * decay;
    return new_sample;
}
