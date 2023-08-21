#ifndef SHAKERSORT
#define SHAKERSORT

#include "multi_sort.h"

class ShakerSort : public MultiSort
{
public:
    ShakerSort();
    ~ShakerSort();

    void printArray();
    std::chrono::microseconds sort();
};

#endif
