#include <iostream>
#include <cstdlib>
#include <cmath>
#include <portaudio.h>
#include <tbb/pipeline.h>

#include "microphone.hh"
#include "output-stream.hh"
#include "delay.hh"
#include "boost.hh"
#include "drive.hh"
#include "flanger.hh"
#include "reverb.hh"
#include "swell.hh"

#define RATE    44100

int main()
{
    int error = Pa_Initialize();

    Microphone mic(RATE);
    //Boost boost(1.0f);
    //Drive drive(0.1f, 0.5f);
    //Flanger flanger(RATE, 0.05f, 0.5f);
    //Reverb reverb(1.0f, 0.99999f);
    //Delay delay1(RATE, 300, 0.1f, 0.3f);
    Swell swell(1.0, RATE, 1.0);
    OutputStream output(RATE);

    tbb::pipeline ppl;

    ppl.add_filter(mic);
    //ppl.add_filter(boost);
    //ppl.add_filter(drive);
    //ppl.add_filter(flanger);
    //ppl.add_filter(reverb);
    //ppl.add_filter(delay1);
	  ppl.add_filter(swell);
    ppl.add_filter(output);

    ppl.run(2);

    Pa_Terminate();

    return 0;
}
