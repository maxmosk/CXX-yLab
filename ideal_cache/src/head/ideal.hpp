#ifndef __IDEAL_HPP_INCLUDED__
#define __IDEAL_HPP_INCLUDED__

#include <vector>
#include <cstring>


template <typename elem_t>
class ideal_cache
{
    size_t size;
    size_t used = 0;
    elem_t *cells;
    
    std::vector<elem_t> sequence;
    

    size_t findToReplace(size_t pos)
    {
        if (used < size)
        {
            used++;
            return used - 1;
        }

        for ()
    }
    
    bool 

    public:
        ideal_cache(size_t initSize) : size (initSize), used (0)
        {
            cells = new elem_t[size];
            memset(cells, 0, size * sizeof (elem_t))
            sequence.reserve(size * 10);
        }


        size_t getSize() const
        {
            return size;
        }

        size_t getHits()
        {
            size_t nelems = sequence.size();
            for (size_t i = 0; i < nelems; i++)
            {
            }

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

