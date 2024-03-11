#include <iostream>
#include <vector>

int search(std::vector<int> vec, int value)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
        {
            return i;
        }
    }
    return -1;
};

int main()
{
    std::vector<int> testVector{1, 2, 3, 4};
    int testValue = 4;
    std::cout << search(testVector, testValue);

    return 0;
}