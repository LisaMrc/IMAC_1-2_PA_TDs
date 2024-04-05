#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>

int main()
{
    std::srand(42);
    std::vector<int> v{};

    for (int i = 0; i < 100; ++i)
    {
      v.push_back(rand() % 100 + 1);
    }

    for (std::vector<int>::iterator it {v.begin()}; it != v.end(); ++it)
    {
      std::cout << *it << std::endl;
    }

    int user_input{};
    std::cout << "Enter searched number :";
    std::cin >> user_input;
    auto it {std::find(v.begin(), v.end(), user_input)};
    if (it != v.end())
    {
        std::cout << *it << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    std::cout << "Numbers of 3 in the vector : " << std::count(v.begin(), v.end(), 3) << std::endl;

    std::sort(v.begin(), v.end());

    int sum { std::accumulate(v.begin(), v.end(), 0, [](int acc, int current_element) { return acc + current_element; }) };
    std::cout << "sum of vector" << sum << std::endl;

    return 0;
}