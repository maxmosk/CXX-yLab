#include <iostream>
#include "ideal.hpp"

int main(void)
{
    int npages = 0;
    size_t cachesize = 0;
    std::cin >> cachesize >> npages;

    cache::ideal_cache<int> cache(cachesize);

    int pagenum = 0;
    for (int i = 0; i < npages; i++)
    {
        std::cin >> pagenum;
        cache.putElem(pagenum);
    }

    std::cout << cache.getHits() << std::endl;

    return 0;
}
