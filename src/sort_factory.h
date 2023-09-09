#ifndef SORTFACTORY
#define SORTFACTORY

// #include "bubble_sort.h"
// #include "selection_sort.h"
// #include "shaker_sort.h"
// #include "quick_sort.h"

#include "multi_sort.h"

#include <vector>

template <typename T>
class SortFactory
{
public:
    SortFactory(const int &a_iSize);
    ~SortFactory();

    // void add(MultiSort* a_pMultiSort);
    void sort();
    bool checkSorted();
    void print_statistics();

protected:
    std::vector <MultiSort<T>*> m_vpMultiSort;
};

#endif
