#include "delay.hh"

Delay::Delay(unsigned int sample_rate, unsigned int ms, float vol, float dec)
     : tbb::filter(tbb::filter::serial_in_order),
       volume(vol),
       decay(dec),
       cnt(0)
{
    buffSize = float(ms) * float(sample_rate) / 1000.0f;
    buff = (float*) malloc(sizeof (float) * buffSize);

    for (int i = 0; i < buffSize; i++)
        buff[i] = 0.0f;
}

Delay::~Delay()
{
    free(buff);
}

void*
Delay::operator()(void* data)
{
    float* sample = (float*) data;
    float* new_sample = new float(*sample);

    buff[cnt] *= decay;
    buff[cnt] += *sample;
    *new_sample += volume * buff[(cnt + 1) % buffSize];
    cnt++;
    cnt %= buffSize;

    return new_sample;
}
