#ifndef SORTFACTORY
#define SORTFACTORY

#include "bubble_sort.h"
#include "min_max_sort.h"
#include "double_bubble_sort.h"

#include <vector>

class SortFactory
{
public:
    SortFactory();
    ~SortFactory();

    void add(MultiSort* a_pMultiSort);
    void sort();
    void print();

protected:
    std::vector <MultiSort*> m_vpMultiSort;
};

#endif
