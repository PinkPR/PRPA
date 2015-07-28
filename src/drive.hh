#ifndef DRIVE_HH
# define DRIVE_HH

# include <tbb/pipeline.h>
# include <math.h>

class Drive : public tbb::filter
{
    public:
        Drive(float _threshold, float _clamp);
        ~Drive();

    public:
        void* operator()(void* data);

    private:
        float   threshold;
        float   clamp;
};

#endif /* DRIVE_HH */
