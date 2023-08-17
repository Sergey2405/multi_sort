#ifndef MINMAXSORT
#define MINMAXSORT

#include "multi_sort.h"

class MinMaxSort : public MultiSort
{
public:
    MinMaxSort();
    ~MinMaxSort();

    std::chrono::microseconds sort();
};

#endif
