#include <cstdio>
#include "lfu.hpp"


int main(void)
{
    int npages = 0;
    scanf("%d", &npages);

    lfu_cache<int> myCache(10);
    
    int buf = 0;
    for (int i = 0; i < npages; i++)
    {
        scanf("%d", &buf);
        myCache.lookup(buf);
    }

    return 0;
}

