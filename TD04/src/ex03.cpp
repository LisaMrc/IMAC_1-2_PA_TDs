#include <iostream>

bool is_palindrome(std::string const& str)
{
    return std::equal(str.begin(), str.end(), str.rbegin());
}

int main()
{
    std::cout << is_palindrome("kayak");
    is_palindrome("pagaie");
    return 0;
}