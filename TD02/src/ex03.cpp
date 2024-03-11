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

// fonction itérative (tri par séléction)
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

// fonction récursive (tri fusion)
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right)
{
    size_t i = left; /* index de départ pour le sous-tableau de gauche (première moitié) */
    size_t j = middle + 1; /* index de départ pour le sous-tableau de droite (deuxième moitié) */
    size_t k = left; /* index de départ pour le tableau temporaire (fusion des 2 moitiés) */

    // création du tableau temporaire
    std::vector<float> temp { vec };

    while (i <= middle && j <= right) /* <- "attention à ne pas dépasser la taille des sous-tableaux..." (encadré jaune)*/
    {
        if (vec[i] <= vec[j])
        {
            temp[k]=vec[i]; /* l'élément i du 1er sous-tableau est + petit que l'élément j du 1er sous-tableau */
            i++;
            k++;
        } 
        else
        {
            temp[k]=vec[j];
            j++;
            k++;
        }
    }

    // "s'il reste des éléments dans une des sous-parties, on les place dans le tableau original"
    while (i<=middle)
    {
        temp[k]=vec[i];
        i++;
        k++;
    }

    while (i<=middle)
    {
        temp[k]=vec[i];
        j++;
        k++;
    }
    
    // On remplit le tableau passé en paramètre avec les éléments du tableau temp
    for (int s=left; s<=right; s++) 
    {
        vec[s]=temp[s];
    } 
}

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right)
{
    // on vérifie si le tableau a un élément seulement, si c'est le cas, la condition devient fausse et le reste n'est pas exécuté
    if (left < right)
    {
        size_t middle = (left+right)/2;
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort(std::vector<float> & vec) 
{
    merge_sort(vec, 0, vec.size() - 1);
}

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

    //if (algo 1 > algo 2)
    //{
    //    std::cout << "algo 1 est + rapide"
    //}
}

// On remarque que la fonction récursive est beaucoup plus rapide (2,7us contre 36 et 4.6)