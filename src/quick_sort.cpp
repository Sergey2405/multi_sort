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
    auto pivot = QuickSort<T>::m_randomArray[(startIx + endIx) / 2];
    MultiSort<T>::m_iFetchCounter++;
    int pivotIx = (startIx + endIx) / 2,
        lowerIx = startIx,
        upperIx = startIx + 1;
    while (!(upperIx > endIx)) {
        auto upperValue = QuickSort<T>::m_randomArray[upperIx];
        if (!(upperValue > pivot)) {
            MultiSort<T>::m_iCompareCounter++;
            while (lowerIx < upperIx) {
                //TODO optimize fetch
                auto lowerValue = QuickSort<T>::m_randomArray[lowerIx];
                if (lowerValue > upperValue) {
                    std::swap(QuickSort<T>::m_randomArray[lowerIx], QuickSort<T>::m_randomArray[upperIx]);
                    lesserSwap = true;
                    MultiSort<T>::m_iSwapCounter++;
                }
                MultiSort<T>::m_iFetchCounter ++;
                MultiSort<T>::m_iCompareCounter++;

                if (lowerValue < pivot) {
                    lowerIx++;
                    continue;
                }
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