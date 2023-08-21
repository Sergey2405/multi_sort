#include "selection_sort.h"

SelectionSort::SelectionSort()
{
    m_sTypeName = "selection min sort";
}

SelectionSort::~SelectionSort()
{}

std::chrono::microseconds SelectionSort::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    int min = m_piRandomArray[0],
        max = m_piRandomArray[0],
        min_ptr = 0,
        max_ptr = 0;
    for (int i = 0; i < m_iSize; i++) {
        // std::cout << i << ": "; this->printArray();
        int min_ptr = i,
            min = m_piRandomArray[i];
            // max_ptr = m_iSize - 1 - i;
            // max = m_piRandomArray[m_iSize - 1 - i];
        for (int j = i; j < m_iSize; j++) {
            if (m_piRandomArray[j] < min) {
                min = m_piRandomArray[j];
                min_ptr = j;
            }
            // if (m_piRandomArray[j] > max) {
            //     max =  m_piRandomArray[j];
            //     max_ptr = j;
        }
        std::swap(m_piRandomArray[min_ptr],  m_piRandomArray[i]);
    }
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    m_duration = duration;
    return duration;
}
