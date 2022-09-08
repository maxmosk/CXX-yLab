#include <cstdio>
#include <cstdlib>
#include <cstdint>


typedef uint32_t lfu_count_t;


template <typename key_t>
class lfu_pare
{
    key_t *key;
    lfu_count_t used;

    public:
        lfu_pare () : key (nullptr), used (0) {}

        const key_t *getKey () const
        {   return key;   }

        lfu_count_t getUsed () const
        {   return used;   }

        ~lfu_pare () {}
};


template <typename elem_t>
class lfu_cache
{
    size_t size;
    lfu_pare<elem_t> *cells;

    int insert (elem_t elem)
    {

    }

    public:
        lfu_cache (size_t size) : size (size)
        {
            cells = new lfu_pare<elem_t>[size];
        }

        size_t getSize () const
        {   return size;   }

        const elem_t *lookup (const elem_t *elem)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (*elem == cells[i])
                {   return &cells[i];   }
                else
                {
                    insert (elem);
                    return nullptr;
                }
            }
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

