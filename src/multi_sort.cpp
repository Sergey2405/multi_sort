#include "multi_sort.h"

MultiSort::MultiSort(int a_size)
{
    m_iSize = a_size;
    int *m_ipRandomArray = new int[a_size];
    for (int i = 0; i < a_size; i++)
        m_ipRandomArray[i] = rand() % (a_size + 1);
}

MultiSort::~MultiSort()
{}

void MultiSort::sort()
{
    //TODO simple buble sort
}
