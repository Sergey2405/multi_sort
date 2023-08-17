#include "double_bubble_sort.h"

DoubleBubbleSort::DoubleBubbleSort()
{
    m_sTypeName = "double bubble sort";
}

DoubleBubbleSort::~DoubleBubbleSort()
{}

void DoubleBubbleSort::printArray()
{}

std::chrono::microseconds DoubleBubbleSort::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < m_iSize; i++)
        for(int j = i; j < m_iSize - i - 1; j++)
            if (m_piRandomArray[j] > m_piRandomArray[j + 1])
                std::swap(m_piRandomArray[j], m_piRandomArray[j + 1]);
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    m_duration = duration;
    return duration;
}
