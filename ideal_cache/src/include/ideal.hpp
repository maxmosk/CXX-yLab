#ifndef IDEAL_HPP_INCLUDED__
#define IDEAL_HPP_INCLUDED__


#include <cstdint>
#include <unordered_map>
#include <vector>


namespace cache
{
    template <typename elem_t>
    class ideal_cache final
    {
        //================================== Private
        size_t size;
        size_t used = 0;
        std::vector<elem_t> cells;
        
        std::vector<elem_t> sequence = std::vector<elem_t>();
        size_t curPos = 0;

        std::unordered_map<elem_t, size_t> finderCache = std::unordered_map<elem_t, size_t>();


        size_t lookupToReplace()
        {
            if (used < size)
            {
                return used;
            }

            else
            {
                size_t foundIndex = SIZE_MAX;
                size_t foundEntry = 0;
                size_t seqLen = sequence.size();

                for (size_t i = 0; i < used; i++)
                {
                    size_t curEntry = SIZE_MAX;
                    for (size_t j = curPos; j < seqLen; j++)
                    {
                        if (sequence.at(j) == cells.at(i))
                        {
                            curEntry = j;
                            break;
                        }
                    }

                    if (foundEntry < curEntry)
                    {
                        foundEntry = curEntry;
                        foundIndex = i;
                    }
                }

                return foundIndex;
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
                insert(elem);
                return false;
            }
        }

        void insert(elem_t elem)
        {
            if (size == 0)
            {
                return;
            }

            else
            {
                size_t indexFind = lookupToReplace();
                
                finderCache.erase(cells.at(indexFind));
                cells.at(indexFind) = elem;
                finderCache[elem] = indexFind;

                if (used < size)
                {
                    used++;
                }
            }
        }


    public:
        //================================== Public
        ideal_cache(size_t initSize) :
            size (initSize),
            used (0),
            cells (std::vector<elem_t>(initSize))
        {
            sequence.reserve(size * 10);
        }


        size_t getHits()
        {
            size_t hits = 0;
            size_t nelems = sequence.size();
            for (; curPos < nelems; curPos++)
            {
                dump(std::cout);
                hits += lookup(sequence.at(curPos));
                dump(std::cout);
            }

            return hits;
        }

        void putElem(const elem_t &src)
        {
            sequence.push_back(src);
        }


        void dump(std::ostream &os)
        {
            os << "Size: " << size << std::endl;
            os << "Used: " << used << std::endl;
            os << "Pos: " << used << std::endl;

            os << "Pages:";
            for (size_t i = 0; i < used; i++)
            {
                os << " " << cells.at(i);
            }
            os << std::endl;
        }


        ~ideal_cache() = default;
    };
}


#endif // IDEAL_HPP_INCLUDED__
