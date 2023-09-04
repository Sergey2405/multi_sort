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
    // std::cout << "QuickSort::sort " << startIx << "Ix " << endIx << "Ix "; printArray(); std::cout << std::endl;

    // if (!(startIx < endIx && startIx >= 0)) {
    if (!(startIx < endIx)) {
        // std::cout << "return0" << startIx << "Ix " << endIx << "Ix "; printArray(); std::cout << std::endl;
        return;
    }
    if (startIx + 1 == endIx) {
        if (m_piRandomArray[startIx] > m_piRandomArray[endIx])
            std::swap(m_piRandomArray[startIx], m_piRandomArray[endIx]);
        // std::cout << "return+1 " << startIx << "Ix " << endIx << "Ix "; printArray(); std::cout << std::endl;
        return;
    }
    int pivot = m_piRandomArray[(startIx + endIx) / 2],
        pivotIx = (startIx + endIx) / 2,
        lowerIx = startIx,
        upperIx = startIx + 1;
    while (!(upperIx > endIx)) {
        // std::cout << "while " << lowerIx << "Ix " << upperIx << "Ix "; printArray(); std::cout << std::endl;
        if (!(m_piRandomArray[upperIx] > pivot)) {
            while (lowerIx < upperIx) {
                // std::cout << "while2 " << lowerIx << "Ix " << upperIx << "Ix "; printArray(); std::cout << std::endl;
                if (m_piRandomArray[lowerIx] > m_piRandomArray[upperIx]) {
                    // std::cout << "swap2 " << lowerIx << "Ix " << upperIx << "Ix "; printArray(); std::cout << std::endl;
                    // if (lowerIx == pivotIx)
                    //     pivot = upperIx;
                    // if (upperIx == lowerIx)
                    //     pivotIx == upperIx;
                    std::swap(m_piRandomArray[lowerIx], m_piRandomArray[upperIx]);
                }
                if (m_piRandomArray[lowerIx] < pivot) {
                    lowerIx++;
                    continue;
                }
                break;
            }
            upperIx++;
            continue;
        }
        upperIx++;
    }

    // pivotIx = std::min(pivotIx, lowerIx);
    sort(startIx, lowerIx);
    sort(lowerIx + 1, endIx);

}

std::chrono::microseconds QuickSort::sort()
{
    auto startClock = std::chrono::high_resolution_clock::now();
    sort(0, m_iSize - 1);
    auto endClock = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endClock - startClock);
    m_duration = duration;
    return duration;
}