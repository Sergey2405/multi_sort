#ifndef MINMAXSORT
#define MINMAXSORT

#include "multi_sort.h"

class MinMaxSort : public MultiSort
{
public:
    MinMaxSort();
    ~MinMaxSort();

    void printArray();
    std::chrono::microseconds sort();
};
#endif
