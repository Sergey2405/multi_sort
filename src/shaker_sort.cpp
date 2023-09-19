#include "shaker_sort.h"

template class ShakerSort<SORTED_TYPE>;

template <class T>
ShakerSort<T>::ShakerSort(const int &a_iSize)
{
    ShakerSort<T>::m_sTypeName = "shaker sort";
    ShakerSort<T>::initArray(a_iSize);
}

template <class T>
ShakerSort<T>::~ShakerSort()
{}

template <class T>
std::chrono::microseconds ShakerSort<T>::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ShakerSort<T>::m_iSize; i++) {
        int j;
        for (j = i; j < ShakerSort<T>::m_iSize - i - 1; j++)
            if (ShakerSort<T>::m_piRandomArray[j] > ShakerSort<T>::m_piRandomArray[j + 1])
                std::swap(ShakerSort<T>::m_piRandomArray[j], ShakerSort<T>::m_piRandomArray[j + 1]);
        for (j = j; j > i; j--)
            if (ShakerSort<T>::m_piRandomArray[j - 1] > ShakerSort<T>::m_piRandomArray[j])
                std::swap(ShakerSort<T>::m_piRandomArray[j - 1], ShakerSort<T>::m_piRandomArray[j]);
    }
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    ShakerSort<T>::m_duration = duration;
    return duration;
}
