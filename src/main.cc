#include <iostream>
#include <cstdlib>
#include <cmath>
#include <portaudio.h>
#include <tbb/pipeline.h>

#include "microphone.hh"
#include "output-stream.hh"
#include "delay.hh"

#define RATE    44100

int main()
{
    int error = Pa_Initialize();

    Microphone mic(RATE);
    Delay delay(RATE, 1000, 1.0);
    OutputStream output(RATE);

    tbb::pipeline ppl;

    ppl.add_filter(mic);
    ppl.add_filter(delay);
    ppl.add_filter(output);

    ppl.run(2);

    Pa_Terminate();

    return 0;
}
