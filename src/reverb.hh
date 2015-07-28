#ifndef REVERB_HH
# define REVERB_HH

# include <tbb/pipeline.h>
# include <cstdlib>

class Reverb : public tbb::filter
{
    public:
        Reverb(float vol, float decay);

    public:
        void* operator()(void* data) override;

    private:
        float           vol;
        unsigned int    cnt;
        float           decay;
        float           old_sample;
};

#endif /* REVERB_HH */
