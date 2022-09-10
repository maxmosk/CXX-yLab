#ifndef __IDEAL_HPP_INCLUDED__
#define __IDEAL_HPP_INCLUDED__

#include <vector>


template <typename elem_t>
class ideal_cache
{
    size_t size;
    size_t used;
    elem_t *cells;
    
    std::vector<elem_t> pageSequence;

    public:
        ideal_cache(size_t initSize) : size (initSize), used (0)
        {
            cells = new elem_t[size];
            pageSequence.reserve(size * 10);
        }


        size_t getSize() const
        {
            return size;
        }


        ~ideal_cache()
        {
            delete[] cells;
        }
};

#endif

