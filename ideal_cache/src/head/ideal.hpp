#ifndef __IDEAL_HPP_INCLUDED__
#define __IDEAL_HPP_INCLUDED__

#include <vector>
#include <unordered_map>
#include <cstring>


template <typename elem_t>
class ideal_cache
{
    //================================== Private
    size_t size;
    size_t used = 0;
    elem_t *cells;
    
    std::vector<elem_t> sequence;
    std::unordered_map<elem_t, size_t> finderCache;


    size_t findToReplace(size_t pos)
    {
        if (used < size)
        {
            used++;
            return used - 1;
        }

    }
    
    bool lookup(elem_t elem)
    {
        auto search = finderCache.find(elem);
        if (search != finderCache.end())
        {
            return true;
        }

        else
        {

        }
    }

public:
    //================================== Public
    ideal_cache(size_t initSize) : size (initSize), used (0)
    {
        cells = new elem_t[size];
        memset(cells, 0, size * sizeof (elem_t));
        sequence.reserve(size * 10);
    }


    size_t getHits()
    {
        size_t hits = 0;
        size_t nelems = sequence.size();
        for (size_t i = 0; i < nelems; i++)
        {
            hits += lookup(sequence[i]);
        }

        return hits;
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

