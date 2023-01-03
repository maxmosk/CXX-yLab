#ifndef IDEAL_HPP_INCLUDED__
#define IDEAL_HPP_INCLUDED__


#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>


namespace cache
{
    template <typename elem_t>
    class ideal_cache final
    {
        //================================== Private
        std::size_t size;
        std::size_t used = 0;
        std::vector<elem_t> cells;
        
        std::vector<elem_t> sequence = std::vector<elem_t>();
        size_t curPos = 0;

        std::unordered_map<elem_t, std::size_t> finderCache = std::unordered_map<elem_t, std::size_t>();


        std::size_t lookupNext(const elem_t &elem)
        {
            std::size_t seqLen = sequence.size();

            for (std::size_t j = curPos + 1; j < seqLen; j++)
            {
                if (sequence.at(j) == elem)
                {
                    return j;
                }
            }

            return SIZE_MAX;
        }

        std::size_t lookupToReplace(const elem_t &elem)
        {
            if (used < size)
            {
                return used++;
            }

            else
            {
                std::size_t foundIndex = SIZE_MAX;
                std::size_t foundEntry = 0;

                for (std::size_t i = 0; i < used; i++)
                {
                    std::size_t curEntry = lookupNext(cells.at(i));        

                    if (foundEntry < curEntry)
                    {
                        foundEntry = curEntry;
                        foundIndex = i;
                    }
                }

                if (foundEntry > lookupNext(elem))
                {
                    return foundIndex;
                }
                else
                {
                    return SIZE_MAX;
                }
            }
        }
        
        bool lookup(const elem_t &elem)
        {
            auto search = finderCache.find(elem);
            if (search != finderCache.end())
            {
                return true;
            }

            else
            {
                insert(elem);
                return false;
            }
        }

        void insert(const elem_t &elem)
        {
            if (size == 0)
            {
                return;
            }

            else
            {
                std::size_t indexFind = lookupToReplace(elem);

                if (indexFind != SIZE_MAX)
                {                
                    finderCache.erase(cells.at(indexFind));
                    cells.at(indexFind) = elem;
                    finderCache[elem] = indexFind;
                }
            }
        }


    public:
        //================================== Public
        ideal_cache(std::size_t initSize) :
            size (initSize),
            used (0),
            cells (std::vector<elem_t>(initSize))
        {
            sequence.reserve(size * 10);
        }


        std::size_t getHits()
        {
            std::size_t hits = 0;
            std::size_t nelems = sequence.size();
            for (; curPos < nelems; curPos++)
            {
                hits += lookup(sequence.at(curPos));
            }

            return hits;
        }

        void putElem(const elem_t &src)
        {
            sequence.push_back(src);
        }


        void dump(std::ostream &os)
        {
            os << std::endl;
            os << "Size: " << size << std::endl;
            os << "Used: " << used << std::endl;
            os << "Pos: " << used << std::endl;

            os << "Pages:";
            for (std::size_t i = 0; i < used; i++)
            {
                os << " " << cells.at(i);
            }
            os << std::endl << std::endl;
        }


        ~ideal_cache() = default;
    };
}


#endif // IDEAL_HPP_INCLUDED__

