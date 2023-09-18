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
    auto min = SelectionSort<T>::m_piRandomArray[0],
         max = SelectionSort<T>::m_piRandomArray[0];
    int min_ptr = 0,
        max_ptr = 0;
    for (int i = 0; i < SelectionSort<T>::m_iSize; i++) {
        // std::cout << i << ": "; this->printArray();
        int min_ptr = i;
            min = SelectionSort<T>::m_piRandomArray[i];
            // max_ptr = m_iSize - 1 - i;
            // max = m_piRandomArray[m_iSize - 1 - i];
        for (int j = i; j < SelectionSort<T>::m_iSize; j++) {
            if (SelectionSort<T>::m_piRandomArray[j] < min) {
                min = SelectionSort<T>::m_piRandomArray[j];
                min_ptr = j;
            }
            // if (m_piRandomArray[j] > max) {
            //     max =  m_piRandomArray[j];
            //     max_ptr = j;
        }
        std::swap(SelectionSort<T>::m_piRandomArray[min_ptr], SelectionSort<T>::m_piRandomArray[i]);
    }
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    SelectionSort<T>::m_duration = duration;
    return duration;
}
