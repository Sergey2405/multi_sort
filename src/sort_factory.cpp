#include "sort_factory.h"

extern bool debug_option;

SortFactory::SortFactory(const int &a_iSize)
{
    add(new BubbleSort(a_iSize));
    add(new ShakerSort(a_iSize));
    add(new SelectionSort(a_iSize));
    add(new QuickSort(a_iSize));

    sort();
    checkSorted();
}

SortFactory::~SortFactory()
{
    //TODO
    //delete other created objects
}

void SortFactory::add(MultiSort* a_pMultiSort)
{
    m_vpMultiSort.push_back(a_pMultiSort);
}

void SortFactory::sort()
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

bool SortFactory::checkSorted()
{
    bool bSorted = true;
    for (auto elem: m_vpMultiSort){
        if (!elem->checkSorted()){
            bSorted = false;
        }
    }
    return bSorted;
}

void SortFactory::print_statistics()
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
