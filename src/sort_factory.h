#ifndef SORTFACTORY
#define SORTFACTORY

#include "multi_sort.h"

#include "bubble_sort.h"
#include "shaker_sort.h"
#include "selection_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"

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

private:
    friend MultiSort<T>;
};

#endif
