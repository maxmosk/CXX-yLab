#include <cstdio>
#include "lfu.hpp"


int main(void)
{
    int npages = 0;
    scanf("%d", &npages);

    cache::lfu_cache<int> myCache(10);
    
    int nhit = 0;
    int buf = 0;
    for (int i = 0; i < npages; i++)
    {
        do
        {
            scanf("%d", &buf);
        }
        while (buf == 0);

        nhit += myCache.lookup(buf) ? 1 : 0;
    }

    printf("%d\n", nhit);

    return 0;
}

