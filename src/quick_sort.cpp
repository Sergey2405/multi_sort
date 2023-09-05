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
    if (!(startIx < endIx))
        return;
    int pivot = m_piRandomArray[(startIx + endIx) / 2],
        pivotIx = (startIx + endIx) / 2,
        lowerIx = startIx,
        upperIx = startIx + 1;
    while (!(upperIx > endIx)) {
        if (!(m_piRandomArray[upperIx] > pivot)) {
            while (lowerIx < upperIx) {
                if (m_piRandomArray[lowerIx] > m_piRandomArray[upperIx]) {
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