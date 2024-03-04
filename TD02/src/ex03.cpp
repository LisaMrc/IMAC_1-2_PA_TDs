#include <iostream>

int main() 
{
    int variable{11};

    std::cout << variable;
    std::cout << variable/2;
    // On obtient un nombre entier car on fait une division d'entiers

    float floatVariable{static_cast<float>(variable)};
    std::cout << variable/2.0f;
}