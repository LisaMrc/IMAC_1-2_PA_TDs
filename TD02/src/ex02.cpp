#include <vector>
#include <algorithm>
#include <iostream>
// using namespace std;

bool is_sorted(std::vector<int> const& vec)
{
    return std::is_sorted(vec.begin(), vec.end());
};

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right)
{
    // copie la 1e moitié du tableau vec dans un tableau firstHalf et la 2e moitié dans un tableau secondHalf
    // copie la 1e moitié du tableau firstHalf dans un tableau firstQuarter et la 2e moitié dans un tableau secondQuarter
    // copie la 1e moitié du tableau secondHalf dans un tableau thirdQuarter et la deuxième moitié du tableau dans un tableau fourthQuarter
    // continue jusqu'à ce qu'il ne reste plus que des tableaux de 2 ou 1
    // pour les tableaux de 2, si le 2e chiffre est + petit que le 1er, inverse-les
    // fusionne firstQuarter et SecondQuarter et range les nombres
    // fusionne thirdQuarter et SecondQuarter et range les nombres
    

}

void merge_sort(std::vector<float> & vec) 
{
    merge_sort(vec, 0, vec.size() - 1);
}

int main()
{
    // std::vector<int> notSortedArray {6, 5, 3, 1, 8, 7, 2, 4};
    std::vector<int> arr{4, 6, 1, 2, 7};

    std::cout << "before merge sort : " << std::endl;
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout<< arr[i] << " ";
    }
    
    // merge_sort(arr);

    if (is_sorted(arr))
    {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    return 0;
}