#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>

auto const is_space = [](char letter){ return letter == ' '; };

int nbr_letters(std::string const& sentence)
{
    auto Jean = find_if(sentence.begin(), sentence.end(), is_space);

    return std::distance(sentence.begin(), Jean);
}

std::vector<std::string> split_string(std::string const& str)
{
    std::vector<std::string> output{};
    int i{};
    auto idx_begin{str.begin()};
    auto idx_end{str.begin()};

    while (i != str.size())
    {
        auto idx_end = find_if(idx_begin, str.end(), is_space);
        int nbr_letters = std::distance(idx_begin, idx_end);
        std::string tmp_str{str[idx_begin], str[nbr_letters]};
        // TODO : corriger le bug ici
        output.push_back(tmp_str);
        tmp_str.clear();
        idx_end += nbr_letters;
        i+=nbr_letters+1;
    }

    return output;
}

int main()
{
    split_string("hello world");
    return 0;
}

// PROTOCOL
// init une sortie
//  on a un indice end et begin, init tous les 2

// tant que i != str.size()
//  auto idx_end = find_if(indice_begin, str.end, xxxx)
//  nbr_letters == distance(indice_begin, idx_end, xxxx)
//  creer une string temporaire tmp_str qui contient les lettres de indice_begin à indice end (donc de indice_begin pendant nbr_letters de lettres)
// ranger la str tmp dans le tableau output
// clear la string temporaire
//  idx_begin += nbr_letters
// i+= nbr_letters+1