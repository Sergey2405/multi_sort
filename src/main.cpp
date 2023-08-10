#include <iostream>
#include <random>

#define ARRAY_SIZE 1000

std::random_device rd;
std::mt19937 gen(rd());

int random_array[ARRAY_SIZE];

void init_random_array(int *a_random_array, int &&a_size)
{
    for (int i = 0; i < a_size; i++)
        a_random_array[i] = rand() % (a_size + 1);
}

void min_max_sort(int *a_array, int a_size)
{
    for (int i = 0; i < a_size / 2; i++) {
        int min = a_array[i],
            max = a_array[i],
            min_ptr = i,
            max_ptr = i;

        for(int j = i; j < a_size - i; j++) {
            if (a_array[j] < min) {
                min = a_array[j];
                min_ptr = j;
            }
            if (a_array[j] > max) {
                max = a_array[j];
                max_ptr = j;
            }
        }
        std::swap(a_array[min_ptr], a_array[i]);
        std::swap(a_array[max_ptr], a_array[a_size - i - 1]);
    }
}

int main()
{
    init_random_array(random_array, ARRAY_SIZE);
    for (auto elem : random_array)
        std::cout << elem << " ";

    std::cout << std::endl;

    min_max_sort(random_array, ARRAY_SIZE);
    for (auto elem : random_array)
        std::cout << elem << " ";

    return 0;
}