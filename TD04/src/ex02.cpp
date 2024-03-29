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
    std::vector<std::string>splitted_string{};
    int idx{};

    for (size_t i = 0; i < str.size(); i++)
    {
        auto Jean = find_if(str.begin() + idx, str.end(), is_space);
        int nbr_letters = std::distance(idx, Jean);
        std::string tmp_str{str[idx], str[nbr_letters]};
        splitted_string.push_back(tmp_str);
        tmp_str.clear();

        idx += Jean;
    }
    
    // TODO : idx et Jean à renommer en idx_begin et idx_end pour y voir + clair

    return splitted_string;
}

int main()
{
    std::cout << nbr_letters("hello world") << std::endl;
    split_string("hello world");
    return 0;
}