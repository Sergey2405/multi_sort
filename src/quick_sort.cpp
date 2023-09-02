#include "quick_sort.h"

QuickSort::QuickSort(const int &a_iSize)
{
    m_sTypeName = "quick sort";
    initArray(a_iSize);
}

QuickSort::~QuickSort()
{}

void QuickSort::sort(int startIx, int endIx)
{
    std::cout << "QuickSort::sort " << startIx << "Ix " << endIx << "Ix ";
    printArray(); std::cout << std::endl;

    if (!(startIx < endIx && startIx >= 0)) {
        std::cout << "return\n";
        return;
    }
    int pivot = m_piRandomArray[endIx],
        lowerIx = startIx -1,
        upperIx = startIx;
    while (upperIx < endIx && lowerIx < upperIx) {
        if (m_piRandomArray[upperIx] > pivot) {
            upperIx++;
            break;
        }
        std::swap(m_piRandomArray[++lowerIx], m_piRandomArray[upperIx]);
    }

    sort(startIx, lowerIx - 1);
    sort(lowerIx, endIx);

}

std::chrono::microseconds QuickSort::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    sort(0, m_iSize - 1);
    // for (int i = 0; i < m_iSize; i++)
    //     for (int j = 0; j < m_iSize - 1; j++)
    //         if (m_piRandomArray[j] > m_piRandomArray[j + 1])
    //             std::swap(m_piRandomArray[j], m_piRandomArray[j + 1]);
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    m_duration = duration;
    return duration;
}