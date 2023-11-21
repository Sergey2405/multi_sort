#include "heap_sort.h"

template class HeapSort<SORTED_TYPE>;

template <class T>
HeapSort<T>::HeapSort(const int &a_iSize)
{
    MultiSort<T>::m_sTypeName = "heap sort";
    MultiSort<T>::initArray(a_iSize);
}

template <class T>
HeapSort<T>::~HeapSort()
{}

template <class T>
void HeapSort<T>::make_heap()
{
    int lowerIx,
        upperIx;
    for (int currentLevel = (int)sqrt((HeapSort<T>::m_iSize));
         currentLevel > 0;
         currentLevel--){
        lowerIx = std::min(HeapSort<T>::m_iSize - 1, (int)pow(2, currentLevel));
        for (; lowerIx > 0; lowerIx--) {
            int upperIx = (lowerIx + 1) / 2 - 1;
            if (MultiSort<T>::m_randomArray[lowerIx] > MultiSort<T>::m_randomArray[upperIx]) {
                std::swap(MultiSort<T>::m_randomArray[lowerIx], MultiSort<T>::m_randomArray[upperIx]);
                MultiSort<T>::m_iSwapCounter++;
            }
            MultiSort<T>::m_iCompareCounter++;
            MultiSort<T>::m_iFetchCounter += 2;
        }
    }
    make_heap(0);
}

template <class T>
void HeapSort<T>::make_heap(int a_SortedCounter)
{
    int lowerIx = HeapSort<T>::m_iSize - a_SortedCounter - 1,
        upperIx;
        lowerIx = HeapSort<T>::m_iSize - a_SortedCounter - 1;
    for (; lowerIx > 0; lowerIx--) {
        upperIx = (lowerIx + 1) / 2 - 1;
        if (MultiSort<T>::m_randomArray[lowerIx] > MultiSort<T>::m_randomArray[upperIx]) {
            std::swap(MultiSort<T>::m_randomArray[lowerIx], MultiSort<T>::m_randomArray[upperIx]);
                            MultiSort<T>::m_iSwapCounter++;
        }
        MultiSort<T>::m_iCompareCounter++;
        MultiSort<T>::m_iFetchCounter += 2;
    }
    if(HeapSort<T>::m_iSize > a_SortedCounter + 1){
        std::swap(MultiSort<T>::m_randomArray[0], MultiSort<T>::m_randomArray[HeapSort<T>::m_iSize - a_SortedCounter - 1]);
        MultiSort<T>::m_iSwapCounter++;
        make_heap(a_SortedCounter + 1);
    }
}


template <class T>
std::chrono::microseconds HeapSort<T>::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    unsigned int level;

    make_heap();
    std::cout << "make_heap ends" << std::endl;

    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    MultiSort<T>::m_duration = duration;
    return duration;
}