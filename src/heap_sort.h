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

    // void make_heap(int nLevels, int a_rSortedCounter = 0);
    void make_heap(int a_sortedCounter);
    void make_heap();
    void sort_heap(int a_upperIx, int a_sortedCounter);

    std::chrono::microseconds sort();
};

#endif