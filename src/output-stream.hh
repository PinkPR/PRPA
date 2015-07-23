#ifndef OUTPUT_STREAM_HH
# define OUTPUT_STREAM_HH

# include <portaudio.h>
# include <cstdlib>
# include <tbb/pipeline.h>

class OutputStream : public tbb::filter
{
    public:
        OutputStream(unsigned int rate);
        ~OutputStream();

    public:
        void* operator()(void* data) override;

    private:
        PaStream*   stream;
};

#endif /* OUTPUT_STREAM_HH */
