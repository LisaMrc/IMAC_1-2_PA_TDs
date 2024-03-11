#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

int find_minimum(std::vector<int> array, int boundary)
{
    int minimum = array[0];

    for (int i{boundary}; i < array.size(); i++) 
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }
    return minimum;
}

void selection_sort(std::vector<int> & vec)
{
    for (int boundary = 0; boundary < vec.size(); boundary++)
    {
        int minimumOfArray = find_minimum(vec, boundary);
        std::swap(minimumOfArray, vec[boundary]);
    }
};


// code de la fonction récursive

int main()
{
    std::vector<int>vec = generate_random_vector(9, 100);
    
    {
        ScopedTimer timer("chrono iterative");
        selection_sort(vec);
    }

    {
        ScopedTimer timer("chrono recursive");
        // merge_sort(vec, 0, vec.size()-1);
    }

    {
        ScopedTimer timer("chrono sort");
        std::sort(vec.begin(), vec.end());
    }

// if (algo 1 > algo 2)
// {
//     std::cout << "algo 1 est + rapide"
// }

}