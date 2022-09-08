#include <cstdio>
#include <cstdlib>
#include <cstdint>


template <typename elem_t>
class lfu_pare
{
    elem_t *data;
    uint32_t used;

    public:
        lfu_pare () : data (nullptr), used (0) {}
};


template <typename elem_t>
class lfu_cache
{
    size_t size;
    lfu_pare<elem_t> *cells;

    public:
        lfu_cache (size_t size) : size (size)
        {
            cells = new lfu_pare<elem_t>[size];
        }

        size_t getSize () const
        {
            return size;
        }

        ~lfu_cache ()
        {
            delete[] cells;
        }
};


int main (void)
{
    lfu_cache<int> my_cache (100);
    printf ("Hello, Max! Tuzya is cute! Cache size is %zd.\n", my_cache.getSize ());
    return 0;
}

