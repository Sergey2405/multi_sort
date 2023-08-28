#ifndef SHAKERSORT
#define SHAKERSORT

#include "multi_sort.h"

class ShakerSort : public MultiSort
{
public:
    ShakerSort(const int &a_iSize);
    ~ShakerSort();

    std::chrono::microseconds sort();
};

#endif
