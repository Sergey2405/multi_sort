#ifndef SELECTIONSORT
#define SELECTIONSORT

#include "multi_sort.h"

class SelectionSort : public MultiSort
{
public:
    SelectionSort(const int &a_iSize);
    ~SelectionSort();

    std::chrono::microseconds sort();
};

#endif
