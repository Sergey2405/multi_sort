#ifndef SORTFACTORY
#define SORTFACTORY

#include "bubble_sort.h"
#include "selection_sort.h"
#include "shaker_sort.h"

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
