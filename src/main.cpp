#include "sort_factory.h"

//TODO: handle it
#include <unistd.h>
// #include <stdio.h>

//TODO move them to singleton.
//TODO make flexible debug level
int array_size;
bool debug_option = false;

// how to launch
// example: ./multi_sort -s 60 -d
int main( int argc, char *argv[], char *envp[])
{
    int opt;
    while((opt = getopt(argc, argv, "ds:")) != -1)
    {
        switch(opt)
        {
            case 'd':
                debug_option = true;
                break;
            case 's':
                array_size = atoi(optarg);
                break;
            case ':':// it does not work!
                std::cout << "Option needs a value";
                return -1;
            case '?':
                std::cout << "Unknown option: " << (char)optopt << std::endl;
                return -1;
        }
    }
    if (debug_option)
        std::cout << "Debug option is enabled\n";
    else
        std::cout << "Debug option is disabled\n";
    std::cout << "array_size = " << array_size << std::endl;
    if (!(array_size > 0)) {
        std::cout << "Array size is not correct\n";
        return -1;
    }

    SortFactory<SORTED_TYPE> sortFactory(array_size);
    sortFactory.print_statistics();

    return 0;
}
