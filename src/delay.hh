#ifndef DELAY_HH
# define DELAY_HH

# include <tbb/pipeline.h>
# include <cstdlib>

class Delay : public tbb::filter
{
    public:
        Delay(unsigned int sample_rate, unsigned int ms, float vol);
        ~Delay();

    public:
        void* operator()(void* data) override;

    private:
        float           volume;
        unsigned int    cnt;
        float*          buff;
        unsigned int    buffSize;
};

#endif /* DELAY_HH */
