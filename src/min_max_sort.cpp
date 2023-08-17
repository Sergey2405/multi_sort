#include "min_max_sort.h"

MinMaxSort::MinMaxSort()
{
    m_sTypeName = "min max sort";
}

MinMaxSort::~MinMaxSort()
{}

std::chrono::microseconds MinMaxSort::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
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
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    m_duration = duration;
    return duration;
}
