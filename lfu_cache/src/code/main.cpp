#include <iostream>
#include "lfu.hpp"


int main(void)
{
    int npages = 0;
    size_t cachesize = 0;
    std::cin >> cachesize >> npages;

    cache::lfu_cache<int> myCache(cachesize);
    
    int nhit = 0;
    int buf = 0;
    for (int i = 0; i < npages; i++)
    {
        do
        {
            std::cin >> buf;
        }
        while (buf == 0);

        nhit += myCache.lookup(buf) ? 1 : 0;
    }

    std::cout << nhit << std::endl;

    return 0;
}

