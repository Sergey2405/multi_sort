#ifndef DOUBLEBUBBLESORT
#define DOUBLEBUBBLESORT

#include "multi_sort.h"

class DoubleBubbleSort : public MultiSort
{
public:
    DoubleBubbleSort();
    ~DoubleBubbleSort();

    void printArray();
    std::chrono::microseconds sort();
};

#endif
