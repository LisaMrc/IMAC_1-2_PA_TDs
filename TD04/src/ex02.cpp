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
    auto it_begin{str.begin()};
    auto it_end{str.begin()};

    while (i < str.size())
    {
        it_end = find_if(it_begin, str.end(), is_space);
        int nbr_letters = std::distance(it_begin, it_end);
        std::string tmp_str{it_begin, it_end};
        output.push_back(tmp_str);
        tmp_str.clear();
        if (it_end == str.end())
         break;
        it_begin = it_end + 1;
        i+=nbr_letters+1;
    }

    return output;
}

int main()
{
    std::vector<std::string> splitted_string = split_string("hello world toto");

    for (size_t i = 0; i < splitted_string.size(); i++)
    {
        std::cout << splitted_string[i] << std::endl;
    }

    return 0;
}