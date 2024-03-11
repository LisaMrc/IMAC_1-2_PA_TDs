#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<float> const& vec)
{
    return std::is_sorted(vec.begin(), vec.end());
};

// merge function
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right)
{
    size_t i = left; /* (autre) indice de départ pour le sous-tableau de gauche (première moitié)*/
    size_t j = middle + 1; /* (autre) indice de départ pour le sous-tableau de droite (deuxième moitié)*/
    size_t k = left; /* (autre) indice de départ pour le tableau temporaire (fusion des 2 moitiés)*/

    std::vector<float> temp; /* tableau temporaire */

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

    // les deux while suivants sont une sécurité, au cas où les 2 sous-tableaux ne font pas la même taille (?)
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
    
    for (int s=left; s<=right; s++)
    {
        vec[s]=temp[s];
    } 
}

//  merge sort function
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right)
{
    if (left < right) /* on vérifie si le tableau a un élément seulement, si c'est le cas, la condition devient fausse et le reste n'est pas exécuté*/
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
    std::vector<float> myarr{4, 6, 1, 2, 7};

    merge_sort(myarr, 0, myarr.size()-1);

    if (is_sorted(myarr))
    {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    return 0;
}