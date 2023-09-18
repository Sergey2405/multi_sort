#ifndef QUICKSORT
#define QUICKSORT

#include "multi_sort.h"

template<class T>
class QuickSort : public MultiSort<T>
{
public:
    QuickSort(const int &a_iSize);
    ~QuickSort();

    std::chrono::microseconds sort();

private:
    void sort(int startIx, int endIx);
};

#endif
