#ifndef CHORUS_HH
# define CHORUS_HH

# include <tbb/pipeline.h>
# include <cstdlib>
# include <iostream>

# define C_DECAY 0.2f

class Chorus : public tbb::filter
{
    public:
        Chorus(float vol, float rate, int length);

    public:
        void* operator()(void* data) override;

    private:
        float           vol;
        float           rate;
        int             length;
        float*          buff;
        unsigned int    buffsize;
        unsigned int    cnt;
        float           moy;
};

#endif /* CHORUS_HH */
