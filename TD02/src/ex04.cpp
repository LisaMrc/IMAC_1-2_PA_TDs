#include <iostream>
#include <vector>

int binary_search(std::vector<int> vec, int value)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (vec[middle] == value)
        return middle;

        if (vec[middle] < value)
        left = middle + 1;

        else
        right = middle - 1;
    }
    return -1;
}

int main(void)
{
    std::vector<int> test_array1 {1, 2, 2, 3, 4, 8, 12};
    std::vector<int> test_array2 {1, 2, 3, 3, 6, 14, 12, 15};
    std::vector<int> test_array3 {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> test_array4 {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> test_array5 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << binary_search(test_array1, 8) << std::endl;
    std::cout << binary_search(test_array2, 15) << std::endl;
    std::cout << binary_search(test_array3, 16) << std::endl;
    std::cout << binary_search(test_array4, 6) << std::endl;
    std::cout << binary_search(test_array5, 10) << std::endl;
}