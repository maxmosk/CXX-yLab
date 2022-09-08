#include <cstdio>
#include <cstdlib>
#include <cstdint>


template <typename elem_t>
class lfu_cache
{
    size_t size;
    elem_t *cells;

    public:
        lfu_cache (size_t size) : size (size)
        {
            cells = (elem_t *) calloc (size, sizeof (elem_t *));
        }

        size_t getSize () const
        {
            return size;
        }

        ~lfu_cache ()
        {
            free (cells);
        }
};


int main (void)
{
    lfu_cache<int> my_cache (100);
    printf ("Hello, Max! Tuzya is cute! Cache size is %d.\n", my_cache.getSize ());
    return 0;
}

