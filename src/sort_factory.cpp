#include "sort_factory.h"

SortFactory::SortFactory()
{
    add(new BubbleSort);
    add(new ShakerSort);
    add(new SelectionSort);

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
        // elem->printArray();//make it optional
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
        std::cout << "type: " << elem->getType().data()
                  << ", duration: " << elem->getDuration().count() << " us"
                  << ", checked: " << elem->getSorted() //TODO improve
                  << std::endl;
        // elem->printArray();//make it optional
    }
    std::cout << std::endl;
}
