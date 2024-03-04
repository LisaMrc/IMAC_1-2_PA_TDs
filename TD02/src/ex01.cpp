#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const& vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

int find_minimum(std::vector array)
{
    for (int i{0}; i < array.size(); i++) 
    {
        int valeur_courante = array[i];

        if (valeur_courante > max_provision)
        {
            max_provision = valeur_courante;
            max_nain = i;
        }

        if (valeur_courante < min_provision) {
            min_provision = valeur_courante;
            min_nain = i;
        }
    }
}


void selection_sort(std::vector<int> & vec)
{
    // trouve le minimum du tableau entre l'indice 0 et l
    // place-le à l'indice 0 et l'indice 0 à l'indice du minimum (échange : swap)

    // trouve le minimum du tableau entre l'indice 1 et l
    // place-le à l'indice 1 et l'indice 0 à l'indice du minimum
    // ...
}

int main()
{
    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};

    if (is_sorted(array))
    {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    return 0;
}