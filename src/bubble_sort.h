#ifndef BUBBLESORT
#define BUBBLESORT

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
