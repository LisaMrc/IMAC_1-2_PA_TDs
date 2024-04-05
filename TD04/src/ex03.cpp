#include <iostream>

bool is_palindrome(std::string const& str)
{
    return std::equal(str.begin(), str.end(), str.rbegin());
}

int main()
{
    std::cout << is_palindrome("kayak") << std::endl;
    std::cout << is_palindrome("pagaie") << std::endl;
    return 0;
}