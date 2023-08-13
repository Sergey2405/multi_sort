#include "min_max_sort.h"

MinMaxSort::MinMaxSort(int a_size)
{
    std::cout << "MinMaxSort::MinMaxSort " << a_size << std::endl;
}

MinMaxSort::~MinMaxSort()
{}

void MinMaxSort::printArray()
{
    std::cout << "MinMaxSort::printArray" << std::endl;
    for (int i = 0; i < m_iSize; i++)
        std::cout << m_piRandomArray[i] << " ";
    std::cout << std::endl;
}

void MinMaxSort::sort()
{
    std::cout << "MinMaxSort::sort()" << std::endl;
    for (int i = 0; i < m_iSize / 2 - 1; i++) {
        int min = m_piRandomArray[i],
            max = m_piRandomArray[i],
            min_ptr = i,
            max_ptr = i,
            tmp;

        for(int j = i; j < m_iSize - i; j++) {
            if (m_piRandomArray[j] < min) {
                min = m_piRandomArray[j];
                min_ptr = j;
            }
            if (m_piRandomArray[j] > max) {
                max =  m_piRandomArray[j];
                max_ptr = j;
            }
        }
        std::swap(m_piRandomArray[min_ptr],  m_piRandomArray[i]);
        std::swap(m_piRandomArray[max_ptr],  m_piRandomArray[m_iSize - i - 1]);
    }
}
