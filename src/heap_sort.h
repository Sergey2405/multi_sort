#ifndef HEAPSORT
#define HEAPSORT

#include <math.h>
#include "multi_sort.h"

template <class T>
class HeapSort : public MultiSort<T>
{
public:
    HeapSort(const int &a_iSize);
    ~HeapSort();

    void make_heap(int nLevels, int a_rSortedCounter = 0);
    void make_heap();

    std::chrono::microseconds sort();
};

#endif