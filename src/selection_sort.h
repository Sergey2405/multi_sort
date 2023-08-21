#ifndef SELECTIONSORT
#define SELECTIONSORT

#include "multi_sort.h"

class SelectionSort : public MultiSort
{
public:
    SelectionSort();
    ~SelectionSort();

    std::chrono::microseconds sort();
};

#endif
