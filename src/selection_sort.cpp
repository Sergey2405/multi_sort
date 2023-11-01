#include "selection_sort.h"

template class SelectionSort<SORTED_TYPE>;

template<class T>
SelectionSort<T>::SelectionSort(const int &a_iSize)
{
    SelectionSort<T>::m_sTypeName = "selection min sort";
    SelectionSort<T>::initArray(a_iSize);
}

template<class T>
SelectionSort<T>::~SelectionSort()
{}

template<class T>
std::chrono::microseconds SelectionSort<T>::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    auto min = SelectionSort<T>::m_randomArray[0],
         max = SelectionSort<T>::m_randomArray[0];
    int min_ptr = 0,
        max_ptr = 0;
    for (int i = 0; i < SelectionSort<T>::m_iSize; i++) {
        int min_ptr = i;
        min = SelectionSort<T>::m_randomArray[i];
        MultiSort<T>::m_iFetchCounter++;
        for (int j = i; j < SelectionSort<T>::m_iSize; j++) {
            if (SelectionSort<T>::m_randomArray[j] < min) {
                min = SelectionSort<T>::m_randomArray[j];
                min_ptr = j;
            }
            MultiSort<T>::m_iCompareCounter++;
        }
        std::swap(SelectionSort<T>::m_randomArray[min_ptr], SelectionSort<T>::m_randomArray[i]);
        MultiSort<T>::m_iSwapCounter++;
    }
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    SelectionSort<T>::m_duration = duration;
    return duration;
}
