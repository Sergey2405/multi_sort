#include "shaker_sort.h"

ShakerSort::ShakerSort(const int &a_iSize)
{
    m_sTypeName = "shaker sort";
    initArray(a_iSize);
}

ShakerSort::~ShakerSort()
{}

std::chrono::microseconds ShakerSort::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < m_iSize; i++) {
        int j;
        for (j = i; j < m_iSize - i - 1; j++)
            if (m_piRandomArray[j] > m_piRandomArray[j + 1])
                std::swap(m_piRandomArray[j], m_piRandomArray[j + 1]);
        for (j = j; j > i; j--)
            if (m_piRandomArray[j - 1] > m_piRandomArray[j])
                std::swap(m_piRandomArray[j - 1], m_piRandomArray[j]);
    }
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    m_duration = duration;
    return duration;
}
