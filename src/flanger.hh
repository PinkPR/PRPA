#ifndef FLANGER_HH
# define FLANGER_HH

# include <tbb/pipeline.h>
# include <cstdlib>
# include <cmath>

# define MAX_DELAY_TIME     3.0f
# define MIN_DELAY_TIME     1.0f

class Flanger : public tbb::filter
{
    public:
        Flanger(float sample_rate_, float speed_, float depth_);
        ~Flanger();

    public:
        void* operator()(void* data);

    private:
        float   sample_rate;
        float   speed;
        float   depth;
        int     cnt;
        int     buffSize;
        float*  buffer;
};

#endif /* DRIVE_HH */
