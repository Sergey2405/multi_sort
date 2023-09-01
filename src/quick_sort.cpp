#include "quick_sort.h"

QuickSort::QuickSort(const int &a_iSize)
{
    m_sTypeName = "quick sort";
    initArray(a_iSize);
}

QuickSort::~QuickSort()
{}

std::chrono::microseconds QuickSort::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < m_iSize; i++)
    //     for (int j = 0; j < m_iSize - 1; j++)
    //         if (m_piRandomArray[j] > m_piRandomArray[j + 1])
    //             std::swap(m_piRandomArray[j], m_piRandomArray[j + 1]);
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    m_duration = duration;
    return duration;
}