#ifndef BUBBLESORT
#define BUBBLERSORT

#include "multi_sort.h"

class BubbleSort : public MultiSort
{
public:
    BubbleSort();
    ~BubbleSort();

    void printArray();
    std::chrono::microseconds sort();
};

#endif
