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
        lfu_pare() : key (0), used (0) {}

        lfu_pare(key_t init_key) : key (init_key), used (1) {}


        const key_t getKey() const
        {
            return key;
        }

        lfu_count_t getUsed() const
        {
            return used;
        }

        void use()
        {
            used++;
        }

        ~lfu_pare() {}
};


template <typename elem_t>
class lfu_cache
{
    size_t size;
    size_t used;
    lfu_pare<elem_t> *cells;

    size_t lookupLFU() const
    {
        lfu_count_t minUsed = cells[0].getUsed();
        size_t minIndex = 0;

        for (size_t i = 0; i <= used; i++)
        {
            if (cells[i].getUsed() <= minUsed)
            {
                printf("*** %zu-th used: %zu\n", i, cells[i].getUsed());
                minUsed = cells[i].getUsed();
                minIndex = i;
            }
        }
        printf("*** Looked up: %zd\n", minIndex);

        return minIndex;
    }

    void insert(const elem_t &elem)
    {
        if (size == 0)
        {
            return;
        }
        else
        {
            cells[lookupLFU()] = lfu_pare<elem_t>(elem);
            used++;
        }
    }


    public:
        lfu_cache(size_t size) : size (size), used (0)
        {
            cells = new lfu_pare<elem_t>[size];
        }


        size_t getSize() const
        {   return size;   }

        bool lookup(const elem_t &elem)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (elem == cells[i].getKey())
                {
                    cells[i].use();
                    return true;
                }
            }


            insert(elem);
            return false;
        }


        ~lfu_cache()
        {
            delete[] cells;
        }
};

#endif

