#include "multi_sort.h"

class MinMaxSort : public MultiSort
{
public:
    MinMaxSort(int a_size = ARRAY_SIZE);
    ~MinMaxSort();

    void printArray();
    void sort();
};
