#ifndef BOOST_HH
# define BOOST_HH

# include <tbb/pipeline.h>

class Boost : public tbb::filter
{
    public:
        Boost(float val);
        ~Boost();

    public:
        void* operator()(void* data);

    private:
        float value;
};

#endif /* BOOST_HH */
