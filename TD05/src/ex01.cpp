#include <iostream>
#include <vector>

size_t folding_string_hash(std::string const& s, size_t max)
{
    size_t sum{};

    for (char character : s) 
    {
        sum+=static_cast<int>(character);
    }

    sum%=max;

    return sum;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max)
{
    size_t sum{};

    for (int i = 0; i < s.size()-1; i++)
    {
        sum+=static_cast<int>(s[i])*i;
    }

    sum%=max;

    return sum;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m)
{
    size_t sum{};
    size_t power{p};

    for (int i = 0; i < s.size()-1; i++)
    {
        if (i==0)
        {
            sum+=static_cast<int>(s[i])*1;
        }

        sum+=static_cast<int>(s[i])*power;
        power*=p;
    }

    sum%=m;

    return sum;
}

int main()
{
    std::cout << folding_string_hash("hello world", 1024) << "\n\n";
    
    std::cout << folding_string_ordered_hash("hello world", 1024) << std::endl;
    std::cout << folding_string_ordered_hash("world hello", 1024) << "\n\n";

    std::cout << polynomial_rolling_hash("hello world", 2, 1024) << std::endl;

    return 0;
}