#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <cctype>
#include <system_error>
#include <charconv>
#include <stack>
// TODO : cleanup includes

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

// TEST FONCTION : problem with the !=
// bool is_floating(std::string const& s)
// {
//    for (int i = 0; i < s.size() ; i++)
//    {
//         if (std::isdigit(s[i]) == false || s[i] != ".")
//         {
//             return false;
//         }
//    }
//     return true;
// }

bool is_floating(std::string const& s)
{
    float value;
    auto [p, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
    return ec == std::errc() && p == s.data() + s.size();
}
// TODO (?) if not floating, is an operator

// TODO : push floating numbers to stack

float calculate_result (float leftOperand, char hello_operator, float rightOperand)
{
    if (hello_operator == "+")
    {
        return leftOperand + rightOperand;
    }
    else if (hello_operator == "-")
    {
        return leftOperand - rightOperand;
    }
    else if (hello_operator == "*")
    {
        return leftOperand * rightOperand;
    }
    else
    {
        return leftOperand / rightOperand;
    }
}

float npi_evaluate(std::vector<std::string> const& tokens)
{
    char hello_operator {};

    // Je récupère l'élément en haut de la pile
    float rightOperand { stack.top() };

    // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
    stack.pop();
    float leftOperand { stack.top() };
    stack.pop();

    // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
    float result {calculate_result(leftOperand, hello_operator, rightOperand)};
    stack.push(result);
}

// TODO : erase this function in the end for better performance
float string_to_float (std::string str)
{
    std::stof(str);
}

int main()
{
    std::string user_input;
    std::getline (std::cin, user_input);
    
    std::vector<std::string> splitted_user_input = split_string(user_input);

    return 0;
}