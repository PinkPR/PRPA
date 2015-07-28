#include "flanger.hh"

Flanger::Flanger(float sample_rate_, float speed_, float depth_)
       : tbb::filter(tbb::filter::serial_in_order),
         sample_rate(sample_rate_),
         speed(speed_),
         depth(depth_),
         cnt(0)
{
    buffSize = int(MIN_DELAY_TIME + (MAX_DELAY_TIME - MIN_DELAY_TIME) * speed) * 44100;
    buffer = (float*) calloc(sizeof (float), int(buffSize));
}

Flanger::~Flanger()
{
    free(buffer);
}

void*
Flanger::operator()(void* data)
{
    float* sample = (float*) data;
    float* new_sample = new float(*sample);

    buffer[cnt] = *sample;
    int offset = int(((sinf(2.0f * 3.14f * float(cnt) / float(buffSize)) + 1.0f) / 2.0f) * float(buffSize - 1)) + 1;
    offset += cnt;
    offset %= buffSize;

    *new_sample += depth * buffer[offset];

    cnt++;
    cnt %= buffSize;

    return new_sample;
}
