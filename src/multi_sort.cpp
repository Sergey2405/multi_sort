#include "multi_sort.h"

MultiSort::MultiSort(int a_size)
{
    std::cout << "MultiSort::MultiSort " << a_size << std::endl;

    m_iSize = a_size;
    m_piRandomArray = new int[m_iSize];
    for (int i = 0; i < a_size; i++)// optimize
        m_piRandomArray[i] = rand() % (a_size + 1);

}

MultiSort::~MultiSort()
{
    std::cout << "MultiSort::~MultiSort";
}

void MultiSort::printArray()
{}

void MultiSort::sort()
{
    std::cout << "MultiSort::sort()" << std::endl;
}
