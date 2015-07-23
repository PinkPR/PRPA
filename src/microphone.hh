#ifndef MICROPHONE_HH
# define MICROPHONE_HH

# include <portaudio.h>
# include <cstdlib>
# include <iostream>
# include <tbb/pipeline.h>


class Microphone : public tbb::filter
{
    public:
        Microphone(unsigned int rate);
        ~Microphone();

    public:
        void* operator()(void* data) override;

    private:
        PaStream*   stream;

};

#endif /* MICROPHONE_HH */
