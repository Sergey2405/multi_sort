#include "min_max_sort.h"

MinMaxSort::MinMaxSort()
{}

MinMaxSort::~MinMaxSort()
{}

void MinMaxSort::sort()
{
    for (int i = 0; i < m_iSize / 2; i++) {
        int min = m_ipRandomArray[i],
            max = m_ipRandomArray[i],
            min_ptr = i,
            max_ptr = i;

        for(int j = i; j < m_iSize - i; j++) {
            if (m_ipRandomArray[j] < min) {
                min = m_ipRandomArray[j];
                min_ptr = j;
            }
            if (m_ipRandomArray[j] > max) {
                max =  m_ipRandomArray[j];
                max_ptr = j;
            }
        }
        std::swap(m_ipRandomArray[min_ptr],  m_ipRandomArray[i]);
        std::swap(m_ipRandomArray[max_ptr],  m_ipRandomArray[m_iSize - i - 1]);
    }
}
