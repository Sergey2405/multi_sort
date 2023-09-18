#include "sort_factory.h"
#include "bubble_sort.h"

extern bool debug_option;

template class SortFactory<int>;

template<class T>
SortFactory<T>::SortFactory(const int &a_iSize)
{
    add(new BubbleSort<T>(a_iSize));
    // add(new ShakerSort(a_iSize));
    // add(new SelectionSort(a_iSize));
    // add(new QuickSort(a_iSize));

    sort();
    checkSorted();
}

template<class T>
SortFactory<T>::~SortFactory()
{
    //TODO
    //delete other created objects
}

template <class T>
void SortFactory<T>::add(MultiSort<T>* a_pMultiSort)
{
    m_vpMultiSort.push_back(a_pMultiSort);
}

template <class T>
void SortFactory<T>::sort()
{
    for (auto elem : m_vpMultiSort) {
        std::cout << "Sort \"" << elem->getType() << "\"" << std::endl;
        if (debug_option) {
            std::cout << "array:";
            elem->printArray();
        }
        elem->sort();
    }
}

template <class T>
bool SortFactory<T>::checkSorted()
{
    bool bSorted = true;
    for (auto elem: m_vpMultiSort){
        if (!elem->checkSorted()){
            bSorted = false;
        }
    }
    return bSorted;
}

template <class T>
void SortFactory<T>::print_statistics()
{
    std::cout << "statisctics:\n";
    for (auto elem : m_vpMultiSort) {
        std::cout << "type: \"" << elem->getType().data()
                  << "\", duration: " << elem->getDuration().count() << " us"
                  << ", checked: " << elem->getSorted() //TODO improve
                  << std::endl;
        if (debug_option) {
            std::cout << "array:";
            elem->printArray();
        }
    }
    std::cout << std::endl;
}
