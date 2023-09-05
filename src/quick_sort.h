#ifndef QUICKSORT
#define QUICKSORT

#include "multi_sort.h"

class QuickSort : public MultiSort
{
public:
    QuickSort(const int &a_iSize);
    ~QuickSort();

    std::chrono::microseconds sort();

private:
    void sort(int startIx, int endIx);
};

#endif
