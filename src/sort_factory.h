#ifndef SORTFACTORY
#define SORTFACTORY

// #include "sort_factory.cpp"
// #include "bubble_sort.h"
// #include "selection_sort.h"
// #include "shaker_sort.h"
// #include "quick_sort.h"

#include "multi_sort.h"

#include <vector>

template <class T>
class SortFactory
{
public:
    SortFactory(const int &a_iSize = DEFAULT_ARRAY_SIZE);
    ~SortFactory();

    void add(MultiSort<T>* a_pMultiSort);
    void sort();
    bool checkSorted();
    void print_statistics();

protected:
    std::vector <MultiSort<T>*> m_vpMultiSort;
};

#endif
