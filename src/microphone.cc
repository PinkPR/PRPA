#include "microphone.hh"

Microphone::Microphone(unsigned int rate)
          : tbb::filter(tbb::filter::serial_in_order)
{
    PaStreamParameters inputParameters;

    inputParameters.device = Pa_GetDefaultInputDevice();
    inputParameters.channelCount = 1;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency =
        Pa_GetDeviceInfo(inputParameters.device)->defaultHighInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    int error =
    Pa_OpenStream(&stream,
                  &inputParameters,
                  NULL,
                  rate,
                  1,
                  paClipOff,
                  NULL,
                  NULL);

    Pa_StartStream(stream);
}

Microphone::~Microphone()
{
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
}

void*
Microphone::operator()(void* data)
{
    float* sample = new float(0.0f);

    int err = Pa_ReadStream(stream, sample, 1);

    std::cout << *sample << std::endl;

    return sample;
}
