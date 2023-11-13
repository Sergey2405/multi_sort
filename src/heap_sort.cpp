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
    int nLevels = (int)sqrt(HeapSort<T>::m_iSize) + 1;
    std::cout << "NLevels=" << nLevels << std::endl;
    make_heap(nLevels, 0);
}

template <class T>
void HeapSort<T>::make_heap(int nLevels, int a_SortedCounter)
{
    int currentLevel = (int)sqrt((HeapSort<T>::m_iSize - a_SortedCounter)) + 1;
    std::cout <<     "currentLevel=" << currentLevel 
              << "\na_SortedCounter=" << a_SortedCounter << std::endl;
    
    int lowIx = HeapSort<T>::m_iSize - a_SortedCounter - 1;
    int upperIx = pow(2, currentLevel) - 1;//??
    if (MultiSort<T>::m_randomArray[lowIx] > MultiSort<T>::m_randomArray[upperIx])
        std::swap(MultiSort<T>::m_randomArray[lowIx], MultiSort<T>::m_randomArray[upperIx]);

    if (currentLevel > 1){
        for(int i = currentLevel - 1; i > 1; i--) {
            lowIx = pow(2, currentLevel) - 1;
            upperIx = pow(2, currentLevel - 1) - 1;
            if (MultiSort<T>::m_randomArray[lowIx] > MultiSort<T>::m_randomArray[upperIx])
                std::swap(MultiSort<T>::m_randomArray[lowIx], MultiSort<T>::m_randomArray[upperIx]);
        }
    }
    // std::cout << "a_SortedCounter=" << a_SortedCounter << std::endl;
    std::swap(MultiSort<T>::m_randomArray[0], MultiSort<T>::m_randomArray[HeapSort<T>::m_iSize - a_SortedCounter - 1]);
    // std::cout << "a_SortedCounter=" << a_SortedCounter << " almost ends" << std::endl;
    if(HeapSort<T>::m_iSize > a_SortedCounter + 2){
        // std::cout << "a_SortedCounter=" << a_SortedCounter << " if" << std::endl;
        // std::swap(MultiSort<T>::m_randomArray[0], MultiSort<T>::m_randomArray[HeapSort<T>::m_iSize - a_SortedCounter - 1]);
        make_heap(nLevels, a_SortedCounter + 1);
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