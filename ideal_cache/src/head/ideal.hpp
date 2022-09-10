#ifndef __IDEAL_HPP_INCLUDED__
#define __IDEAL_HPP_INCLUDED__

#include <vector>


template <typename elem_t>
class ideal_cache
{
    size_t size;
    size_t used;
    elem_t *cells;
    
    std::vector<elem_t> sequence;

    public:
        ideal_cache(size_t initSize) : size (initSize), used (0)
        {
            cells = new elem_t[size];
            sequence.reserve(size * 10);
        }


        size_t getSize() const
        {
            return size;
        }

        size_t getHits() const
        {
            return 0;
        }

        void putElem(const elem_t &src)
        {
            sequence.push_back(src);
        }


        ~ideal_cache()
        {
            delete[] cells;
        }
};

#endif

