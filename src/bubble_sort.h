#ifndef BUBBLESORT
#define BUBBLESORT

#include "multi_sort.h"

class BubbleSort : public MultiSort
{
public:
    BubbleSort();
    ~BubbleSort();

    std::chrono::microseconds sort();
};

#endif
