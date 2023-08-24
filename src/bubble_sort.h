#ifndef BUBBLESORT
#define BUBBLESORT

#include "multi_sort.h"

class BubbleSort : public MultiSort
{
public:
    BubbleSort(const int &a_iSize);
    ~BubbleSort();

    std::chrono::microseconds sort();
};

#endif
