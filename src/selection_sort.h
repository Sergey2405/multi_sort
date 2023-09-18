#ifndef SELECTIONSORT
#define SELECTIONSORT

#include "multi_sort.h"

template<class T>
class SelectionSort : public MultiSort<T>
{
public:
    SelectionSort(const int &a_iSize);
    ~SelectionSort();

    std::chrono::microseconds sort();
};

#endif
