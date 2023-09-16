#ifndef BUBBLESORT
#define BUBBLESORT

#include "multi_sort.h"

template <class T>
class BubbleSort : public MultiSort<T>
{
public:
    BubbleSort(const int &a_iSize);
    ~BubbleSort();

    std::chrono::microseconds sort();
};

#endif
