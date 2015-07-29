#include "chorus.hh"

Chorus::Chorus(float vol, float rate, int length)
      : tbb::filter(tbb::filter::serial_in_order),
        vol(vol),
        rate(rate),
        length(length),
        cnt(0),
        moy(0)
{
  buffsize = length;
  buff = (float*) malloc(sizeof (float) * buffsize);
  for (size_t i = 0; i < buffsize; i++)
    buff[i] = 0.0f;
}

void*
Chorus::operator()(void* data)
{
  float* sample = (float*) data;

  buff[cnt] = *sample;

  if (cnt == buffsize - 1)
  {
    moy = 0;
    for (size_t i = 0; i < buffsize; i++)
      moy += buff[i];
    moy /= buffsize;
  }

  cnt++;
  cnt %= buffsize;

  float* new_sample = new float(moy);
  std::cout << "returned value: " << moy << std::endl;

  return new_sample;
}
