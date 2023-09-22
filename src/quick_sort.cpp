#include "quick_sort.h"

template class QuickSort<SORTED_TYPE>;

template<class T>
QuickSort<T>::QuickSort(const int &a_iSize)
{
    QuickSort<T>::m_sTypeName = "quick sort";
    QuickSort<T>::initArray(a_iSize);
}

template<class T>
QuickSort<T>::~QuickSort()
{}

template<class T>
void QuickSort<T>::sort(int startIx, int endIx)
{
    if (!(startIx < endIx))
        return;
    bool lesserSwap = false;
    auto pivot = QuickSort<T>::m_piRandomArray[(startIx + endIx) / 2];
    MultiSort<T>::m_iFetchCounter++;
    int pivotIx = (startIx + endIx) / 2,
        lowerIx = startIx,
        upperIx = startIx + 1;
    while (!(upperIx > endIx)) {
        if (!(QuickSort<T>::m_piRandomArray[upperIx] > pivot)) {
            MultiSort<T>::m_iCompareCounter++;
            while (lowerIx < upperIx) {
                //TODO optimize fetch
                if (QuickSort<T>::m_piRandomArray[lowerIx] > QuickSort<T>::m_piRandomArray[upperIx]) {
                    std::swap(QuickSort<T>::m_piRandomArray[lowerIx], QuickSort<T>::m_piRandomArray[upperIx]);
                    lesserSwap = true;
                    MultiSort<T>::m_iSwapCounter++;
                }
                MultiSort<T>::m_iFetchCounter += 2;
                MultiSort<T>::m_iCompareCounter++;

                if (QuickSort<T>::m_piRandomArray[lowerIx] < pivot) {
                    lowerIx++;
                    continue;
                }
                MultiSort<T>::m_iFetchCounter++;
                MultiSort<T>::m_iCompareCounter++;

                break;
            }
            upperIx++;
            continue;
        }
        MultiSort<T>::m_iFetchCounter++;
        upperIx++;
    }
    if (lesserSwap)
       sort(startIx, lowerIx);
    sort(lowerIx + 1, endIx);
}

template<class T>
std::chrono::microseconds QuickSort<T>::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    sort(0, QuickSort<T>::m_iSize - 1);
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    QuickSort<T>::m_duration = duration;
    return duration;
}