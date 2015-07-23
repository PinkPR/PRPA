#include "output-stream.hh"

OutputStream::OutputStream(unsigned int rate)
            : tbb::filter(tbb::filter::serial_in_order)
{
    PaStreamParameters outputParameters;

    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = 1;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency =
        Pa_GetDeviceInfo( outputParameters.device )->defaultHighOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    Pa_OpenStream(&stream,
                  NULL,
                  &outputParameters,
                  rate,
                  1,
                  paClipOff,
                  NULL,
                  NULL);

    Pa_StartStream(stream);
}

OutputStream::~OutputStream()
{
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
}

void*
OutputStream::operator()(void* data)
{
    float* sample = (float*) data;

    Pa_WriteStream(stream, sample, 1);

    delete sample;

    return NULL;
}
