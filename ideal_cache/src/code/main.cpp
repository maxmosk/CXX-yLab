#include <cstdio>
#include "ideal.hpp"

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    ideal_cache<int> cache(10);

    int pageN = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pageN);
        cache.putElem(pageN);
    }

    printf("%zu\n", cache.getHits());


    return 0;
}
