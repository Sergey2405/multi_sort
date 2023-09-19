#ifndef SHAKERSORT
#define SHAKERSORT

#include "multi_sort.h"

template <class T>
class ShakerSort : public MultiSort<T>
{
public:
    ShakerSort(const int &a_iSize);
    ~ShakerSort();

    std::chrono::microseconds sort();
};

#endif
