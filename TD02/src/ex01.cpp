#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const& vec)
{
    return std::is_sorted(vec.begin(), vec.end());
};

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
        // trouve le minimum du tableau entre l'indice boundary et l
        int minimum = find_minimum(vec, boundary);

        // échange le nombre qui se trouve à l'indice boundary avec le minimum trouvé
        std::swap(minimum, vec[boundary]);
    }
};

int main()
{
    std::vector<int> sortedArray {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> notSortedArray {5, 7, 3, 4, 9, 6, 0, 8, 4};

    selection_sort(notSortedArray);

    if (is_sorted(notSortedArray))
    {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    return 0;
}