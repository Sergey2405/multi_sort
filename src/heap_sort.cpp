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
    int currentLevel = (int)sqrt((HeapSort<T>::m_iSize)) + 1;
    int lowerIx = HeapSort<T>::m_iSize - 1;
    int upperIx;
    for (; currentLevel > 0; currentLevel--){//TODO: optimize
        lowerIx = HeapSort<T>::m_iSize - 1;
        for (; lowerIx > 0; lowerIx--) {
            int upperIx = (lowerIx + 1) / 2 - 1;
            if (MultiSort<T>::m_randomArray[lowerIx] > MultiSort<T>::m_randomArray[upperIx])
                std::swap(MultiSort<T>::m_randomArray[lowerIx], MultiSort<T>::m_randomArray[upperIx]);
        }
    }
    std::cout << "HeapSort<T>::make_heap. print array: ";
    // this->printArray();

    make_heap(0);
}

template <class T>
void HeapSort<T>::make_heap(int a_SortedCounter)
{
    this->printArray();
    int currentLevel = (int)sqrt((HeapSort<T>::m_iSize)) + 1;
    // std::cout <<     "currentLevel=" << currentLevel 
    //           << "\na_SortedCounter=" << a_SortedCounter << std::endl;

    //TODO: optimize    
    // int lowerIx = HeapSort<T>::m_iSize - a_SortedCounter - 1;
    // int lowerIx2;// = lowerIx / 2 == 0 ? lower - 1 : lowerIx + 1;
    // int upperIx = (lowerIx + 1) / 2 - 1;
    // for(; currentLevel > 0; currentLevel--){
    //     lowerIx = HeapSort<T>::m_iSize - a_SortedCounter - 1;
    //     lowerIx2 = lowerIx % 2 == 0 ? lowerIx - 1 : lowerIx + 1;
    //     upperIx = (lowerIx + 1) / 2 - 1;
    //     // while (upperIx > 0) {
    //     while (lowerIx > 2) {
    //         // lowerIx = upperIx;
    //         // lowerIx2 = lowerIx % 2 == 0 ? lowerIx - 1 : lowerIx + 1;
    //         // upperIx = (lowerIx + 1) / 2 - 1;
    //         if (MultiSort<T>::m_randomArray[lowerIx] > MultiSort<T>::m_randomArray[upperIx])
    //             std::swap(MultiSort<T>::m_randomArray[lowerIx2], MultiSort<T>::m_randomArray[upperIx]);
    //         if (lowerIx2 < HeapSort<T>::m_iSize - a_SortedCounter - 1)
    //             if (MultiSort<T>::m_randomArray[lowerIx2] > MultiSort<T>::m_randomArray[upperIx])
    //                 std::swap(MultiSort<T>::m_randomArray[lowerIx2], MultiSort<T>::m_randomArray[upperIx]);
    //         lowerIx = upperIx;
    //         lowerIx2 = lowerIx % 2 == 0 ? lowerIx - 1 : lowerIx + 1;
    //         upperIx = (lowerIx + 1) / 2 - 1;
    //     }
    // }
    
    int lowerIx = HeapSort<T>::m_iSize - a_SortedCounter - 1;
    int upperIx;
    for (; currentLevel > 0; currentLevel--){//TODO: optimize
        lowerIx = HeapSort<T>::m_iSize - a_SortedCounter - 1;
        for (; lowerIx > 0; lowerIx--) {
            int upperIx = (lowerIx + 1) / 2 - 1;
            if (MultiSort<T>::m_randomArray[lowerIx] > MultiSort<T>::m_randomArray[upperIx])
                std::swap(MultiSort<T>::m_randomArray[lowerIx], MultiSort<T>::m_randomArray[upperIx]);
        }
    }
    if(HeapSort<T>::m_iSize > a_SortedCounter ){
        // std::cout << "a_SortedCounter=" << a_SortedCounter << " if  HeapSort<T>::m_iSize - a_SortedCounter - 1=" << (HeapSort<T>::m_iSize - a_SortedCounter - 1) << std::endl;
        // if (MultiSort<T>::m_randomArray[0] > MultiSort<T>::m_randomArray[HeapSort<T>::m_iSize - a_SortedCounter - 1])
        std::swap(MultiSort<T>::m_randomArray[0], MultiSort<T>::m_randomArray[HeapSort<T>::m_iSize - a_SortedCounter - 1]);
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