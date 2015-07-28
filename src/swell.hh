#ifndef SWELL_HH
# define SWELL_HH

# include <tbb/pipeline.h>
# include <cstdlib>
# include <iostream>
# include <cmath>

# define _USE_MATH_DEFINES // To use M_PI

# include <math.h>

class Swell : public tbb::filter
{
    public:
        Swell(float vol, float rate, float length);

    public:
        void* operator()(void* data) override;

    private:
        float           vol;
        float           cnt;
        float           cst;
        bool            ret;
        float           rate;   // hz, 44100
        float           length; // in seconds
};

#endif /* SWELL_HH */
