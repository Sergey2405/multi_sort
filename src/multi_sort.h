#include <random>

#define ARRAY_SIZE 1000

class MultiSort
{
public:
    MultiSort(int a_size = ARRAY_SIZE);
    ~MultiSort();
    virtual void sort();

protected:
    int m_iSize;
    int *m_ipRandomArray;
};
