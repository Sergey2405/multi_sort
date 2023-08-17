#include "bubble_sort.h"

BubbleSort::BubbleSort()
{
    m_sTypeName = "bubble sort";
}

BubbleSort::~BubbleSort()
{}

void BubbleSort::printArray()
{}

std::chrono::microseconds BubbleSort::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < m_iSize; i++)
        for(int j = i; j < m_iSize - 1; j++)
            if (m_piRandomArray[j] > m_piRandomArray[j + 1])
                std::swap(m_piRandomArray[j], m_piRandomArray[j + 1]);
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    m_duration = duration;
    return duration;
}
