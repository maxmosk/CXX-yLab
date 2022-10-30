#ifndef LFU_H_INCLUDED__
#define LFU_H_INCLUDED__


#include <unordered_map>
#include <vector>


namespace cache
{
    typedef size_t lfu_count_t;


    template <typename key_t>
    class lfu_pare final
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

        ~lfu_pare() = default;
    };


    template <typename elem_t>
    class lfu_cache final
    {
        size_t size;
        size_t used = 0;
        std::vector<lfu_pare<elem_t>> cells = std::vector<lfu_pare<elem_t>>{};
        std::unordered_map<elem_t, size_t> finder = std::unordered_map<elem_t, size_t>{};


        size_t lookupLFU() const
        {
            lfu_count_t minUsed = cells.at(0).getUsed();
            size_t minIndex = 0;

            size_t lookEnd = (size > used) ? (used + 1) : size;
            for (size_t i = 0; i < lookEnd; i++)
            {
                if (cells[i].getUsed() < minUsed)
                {
                    minUsed = cells.at(i).getUsed();
                    minIndex = i;
                }
            }

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
                size_t indexLFU = lookupLFU();
                finder.erase(cells.at(indexLFU).getKey());
                cells.at(indexLFU) = lfu_pare<elem_t>(elem);
                finder[elem] = indexLFU;

                if (indexLFU < (size - 1))
                {
                    used++;
                }
            }
        }


    public:
        lfu_cache(size_t initSize) : size (initSize)
        {
            cells.resize(size);
        }


        bool lookup(const elem_t &elem)
        {
            auto search = finder.find(elem);
            if (search != finder.end())
            {
                cells.at(finder.at(elem)).use();
                return true;
            }

            else
            {
                insert(elem);
                return false;
            }
        }


        ~lfu_cache() = default;
    };
}


#endif // LFU_H_INCLUDED__

