#ifndef __LFU_H_INCLUDED__
#define __LFU_H_INCLUDED__

#include <cstdlib>
#include <cstdint>


typedef size_t lfu_count_t;


template <typename key_t>
class lfu_pare
{
    key_t key;
    lfu_count_t used;

    public:
        lfu_pare () : key (nullptr), used (0) {}

        lfu_pare (key_t init_key) : key (nullptr), used (0) {}

        const key_t getKey () const
        {   return key;   }

        lfu_count_t getUsed () const
        {   return used;   }

        ~lfu_pare () {}
};


template <typename elem_t>
class lfu_cache
{
    size_t size;
    size_t used;
    lfu_pare<elem_t> *cells;

    size_t lookupLFU () const
    {
        size_t minUsed = SIZE_MAX;
        size_t minIndex = 0;

        for (size_t i = 0; i < used; i++)
        {
            if (cells[i].getUsed() <= minUsed)
            {
                minUsed = cells[i].getUsed();
                minIndex = i;
            }
        }

        return minIndex;
    }

    void insert (elem_t elem)
    {
        if (size == 0)
        {
            return;
        }
        else
        {
            cells[lookupLFU] = lfu_pare<elem_t>(elem);
        }
    }

    public:
        lfu_cache (size_t size) : size (size), used (0)
        {
            cells = new lfu_pare<elem_t>[size];
        }

        size_t getSize () const
        {   return size;   }

        const elem_t *lookup (const elem_t *elem)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (*elem == cells[i].getKey ())
                {
                    return &cells[i];
                }
                else
                {
                    insert (elem);
                    return nullptr;
                }
            }
        }

        ~lfu_cache ()
        {
            delete[] cells;
        }
};

#endif

