#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <cctype>
#include <system_error>
#include <charconv>
#include <stack>
#include <cmath>

std::vector<std::string>split_string(std::string const& s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
   for (int i = 0; i < s.size() ; i++)
   {
        if (!(std::isdigit(s[i]) || s[i] == '.'))
            return false;
   }
    return true;
}

float calculate_result (float leftOperand, std::string hello_operator, float rightOperand)
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
    else if (hello_operator == "/")
    {
        return leftOperand / rightOperand;
    }
    else
    {
        pow(leftOperand, rightOperand);
    }
}

float npi_evaluate(std::vector<std::string> const& tokens)
{
    // initialiser une stack, if is_floating, on le convertit
    std::stack<float> stack;
    float result{};

    for (int i = 0; i < tokens.size(); i++)
    {
        if (is_floating(tokens[i]))
        {
            stack.push(std::stof(tokens[i]));
        }
        else
        {
            std::string hello_operator = tokens[i];

            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };

            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();

            // Idem pour l'autre opérande
            float leftOperand { stack.top() };
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            result = calculate_result(leftOperand, hello_operator, rightOperand);
            stack.push(result);
        }
    }
    return result; 
}

int main()
{
    std::string user_input;
    std::cout << "Please enter NPI expression :";
    std::getline(std::cin, user_input);
    
    std::vector<std::string> splitted_user_input = split_string(user_input);

    std::cout << npi_evaluate(splitted_user_input);

    return 0;
}