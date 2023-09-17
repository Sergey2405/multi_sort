#include "bubble_sort.h"
// #include "multi_sort.cpp"

template <class T>
BubbleSort<T>::BubbleSort(const int &a_iSize)
{
    MultiSort<T>::m_sTypeName = "bubble sort";
    MultiSort<T>::initArray(a_iSize);
}

template <class T>
BubbleSort<T>::~BubbleSort()
{}

template <class T>
std::chrono::microseconds BubbleSort<T>::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < m_iSize; i++)
    //     for (int j = 0; j < m_iSize - 1; j++)
    //         if (m_piRandomArray[j] > m_piRandomArray[j + 1])
    //             std::swap(m_piRandomArray[j], m_piRandomArray[j + 1]);
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    // m_duration = duration;
    return duration;
}

void tempBubbleSortFunc()
{
    BubbleSort<int> tmpBS(1);
    // MultiSort<int>s *p_tmp = new BubbleSort<int>(1);
}
