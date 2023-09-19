#include "bubble_sort.h"

template class BubbleSort<SORTED_TYPE>;

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
    for (int i = 0; i < MultiSort<T>::m_iSize; i++)
        for (int j = 0; j < MultiSort<T>::m_iSize - 1; j++)
            if (MultiSort<T>::m_piRandomArray[j] > MultiSort<T>::m_piRandomArray[j + 1])
                std::swap(MultiSort<T>::m_piRandomArray[j], MultiSort<T>::m_piRandomArray[j + 1]);
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    MultiSort<T>::m_duration = duration;
    return duration;
}
