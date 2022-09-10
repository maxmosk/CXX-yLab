#ifndef __IDEAL_HPP_INCLUDED__
#define __IDEAL_HPP_INCLUDED__

template <typename elem_t>
class ideal_cache
{
    size_t size;
    size_t used;
    elem_t *cells;

    public:
        ideal_cache(size_t initSize) : size (initSize), used (0)
        {
            cells = new elem_t[size];
        }


        ~ideal_cache()
        {
            delete[] cells;
        }
};

#endif

